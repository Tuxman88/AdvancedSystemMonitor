# include "DiskAgent.hh"

Base::DiskAgent::DiskAgent ( std::string monitoring_folder )
   : Agent ( monitoring_folder )
{
   mDiskInformation = new DiskInformation;   
}

Base::DiskAgent::~DiskAgent ( void )
{
   delete mDiskInformation;
}

bool Base::DiskAgent::update ( void )
{
   /*
    * The memory can be monitored using the file statm, which has a format like this:
    * 
    * rchar: 36214862
    * wchar: 25848053
    * syscr: 24841
    * syscw: 26380
    * read_bytes: 68612096
    * write_bytes: 21377024
    * cancelled_write_bytes: 9801728
    * 
    */
   
   std::string file_to_verify;   
   std::string file_contents;
   std::string load_command;
   std::string line_loaded;
   
   file_to_verify = "/proc/";
   file_to_verify += mMonitoringFolder;
   file_to_verify += "/io";
   
   load_command = "cat ";
   load_command += file_to_verify;
   
   mDiskInformation->reset ();
   
   file_contents = runCommand ( load_command );
   
   if ( file_contents == "ERROR" )
      return ( false );
   
   std::istringstream iss ( file_contents );
   
   std::getline ( iss , line_loaded );
   
   while ( !iss.eof () )
   {
      storeValue ( line_loaded );
      
      getline ( iss , line_loaded );
   }
   
   return ( true );
}

Base::DiskAgent::DiskInformation* Base::DiskAgent::getDiskInformation ( void )
{
   return ( mDiskInformation );
}

void Base::DiskAgent::storeValue ( std::string line_loaded )
{
   std::string keyname;
   std::istringstream iss ( line_loaded );
   
   iss >> keyname;
   keyname = toUpperCase ( keyname );
   
   if ( keyname == "RCHAR:" )
      iss >> mDiskInformation->BytesRead;
   else if ( keyname == "WCHAR:" )
      iss >> mDiskInformation->BytesWriten;
   else if ( keyname == "SYSCR:" )
      iss >> mDiskInformation->ReadCalls;
   else if ( keyname == "SYSCW:" )
      iss >> mDiskInformation->WriteCalls;
   else if ( keyname == "READ_BYTES:" )
      iss >> mDiskInformation->RealBytesRead;
   else if ( keyname == "WRITE_BYTES:" )
      iss >> mDiskInformation->RealBytesWriten;
   else if ( keyname == "CANCELLED_WRITE_BYTES:" )
      iss >> mDiskInformation->CancelledBytes;
   
   return;
}
