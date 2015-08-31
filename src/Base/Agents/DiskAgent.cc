# include "DiskAgent.hh"

Base::DiskAgent::DiskAgent ( std::string monitoring_folder )
   : Agent ( monitoring_folder )
{
   mDiskInformation = new Base::DataTypes::DiskInformation;   
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
   
   iss >> (*mDiskInformation);
   
   return ( true );
}

Base::DataTypes::DiskInformation* Base::DiskAgent::getDiskInformation ( void )
{
   return ( mDiskInformation );
}
