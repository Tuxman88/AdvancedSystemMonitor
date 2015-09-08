# include "FileSystemAgent.hh"

Base::FileSystemAgent::FileSystemAgent ( std::string monitoring_folder )
   : Agent ( monitoring_folder )
{
   mFilesInformation = new std::vector< Base::DataType::FileInformation* > ();
}

Base::FileSystemAgent::~FileSystemAgent ( void )
{
   deleteFilesInformation ();
   
   delete mFilesInformation;
}

std::vector< Base::DataType::FileInformation* >* Base::FileSystemAgent::getFilesInformation ( void )
{
   return ( mFilesInformation );
}

bool Base::FileSystemAgent::update ( void )
{
   /*
    * I need to apply an LS -LA command in the FD folder of the process. That will give me an output
    * similar to this:
    * 
    * total 0
    * dr-x------ 2 moises moises  0 sep  8 12:26 .
    * dr-xr-xr-x 9 moises moises  0 sep  8 12:12 ..
    * lr-x------ 1 moises moises 64 sep  8 12:26 0 -> pipe:[15450]
    * l-wx------ 1 moises moises 64 sep  8 12:26 1 -> /home/moises/.xsession-errors
    * l-wx------ 1 moises moises 64 sep  8 12:26 10 -> /home/moises/.kde/share/apps/kdevelop/sessions/{dfeb9eff-71c5-42fe-a495-7ff485c54a64}/lock
    * lr-x------ 1 moises moises 64 sep  8 12:26 11 -> /dev/urandom
    * lrwx------ 1 moises moises 64 sep  8 12:26 12 -> anon_inode:[eventfd]
    * lr-x------ 1 moises moises 64 sep  8 12:26 13 -> anon_inode:inotify
    * lrwx------ 1 moises moises 64 sep  8 12:26 14 -> anon_inode:[eventfd]
    * lrwx------ 1 moises moises 64 sep  8 12:26 15 -> anon_inode:[eventfd]
    * 
    * As can be seen, the output can be split using the string " -> ". The first element will contain the ID of the file, while the second element
    * will contain the path to the file.
    */
   
   std::string file_to_verify;
   std::string file_contents;
   std::string load_command;
   std::string line_loaded;
   
   file_to_verify = "/proc/";
   file_to_verify += mMonitoringFolder;
   file_to_verify += "/fd/";
   
   load_command = "ls -la  ";
   load_command += file_to_verify;
   
   deleteFilesInformation ();
   
   file_contents = runCommand ( load_command );
   
   if ( file_contents == "ERROR" )
      return ( false );
   
   std::istringstream iss ( file_contents );
   
   getline ( iss , line_loaded );
   
   while ( !iss.eof () )
   {
      processLine ( line_loaded );
      
      getline ( iss , line_loaded );
   }
   
   return ( true );
}

void Base::FileSystemAgent::deleteFilesInformation ( void )
{
   for ( unsigned int i = 0; i < mFilesInformation->size (); i++ )
   {
      delete mFilesInformation->operator[] ( i );
      mFilesInformation->operator[] ( i ) = 0;
   }
   
   mFilesInformation->clear ();
   
   return;
}

void Base::FileSystemAgent::processLine ( std::string& line_loaded )
{
   std::vector< std::string > main_pieces;
   std::string file_path;
   
   // Split the line and store the file path
   main_pieces = splitString ( line_loaded , " -> " );
   
   if ( main_pieces.size () != 2 )
      return;
   
   file_path = main_pieces[ 1 ];
   
   // Split the first piece and store the File Descriptor ID
   main_pieces = splitString ( main_pieces[ 0 ] , " " );
   
   if ( main_pieces.empty () )
      return;
   
   Base::DataType::FileInformation* information;
   information = new Base::DataType::FileInformation;
   
   information->FilePath = file_path;
   information->FileDescriptorID = toULInt ( main_pieces[ main_pieces.size () - 1 ] );
   
   extractDetailedInformation ( information );
   
   mFilesInformation->push_back ( information );
   
   return;
}

void Base::FileSystemAgent::extractDetailedInformation ( Base::DataType::FileInformation* information )
{
   /*
    * Based in the information provided by the pointer given, I can access the information stored
    * in the FDINFO file expected.
    */
   
   std::string file_to_verify;
   std::string file_contents;
   std::string load_command;
   std::string line_loaded;
   
   file_to_verify = "/proc/";
   file_to_verify += mMonitoringFolder;
   file_to_verify += "/fdinfo/";
   file_to_verify += ULIntToString ( information->FileDescriptorID );
   
   load_command = "cat ";
   load_command += file_to_verify;
   
   file_contents = runCommand ( load_command );
   
   if ( file_contents == "ERROR" )
      return;
   
   std::istringstream iss ( file_contents );
   
   getline ( iss , line_loaded );
   
   while ( !iss.eof () )
   {
      processDetail ( line_loaded , information );
      
      getline ( iss , line_loaded );
   }
   
   return;
}

void Base::FileSystemAgent::processDetail ( std::string& line_loaded , Base::DataType::FileInformation* information )
{
   /*
    * Split the string using spaces and check the first component to know
    * which value to use.
    */
   
   std::vector< std::string > pieces;
   
   pieces = splitString ( line_loaded , " " );
   
   
   
   return;
}
