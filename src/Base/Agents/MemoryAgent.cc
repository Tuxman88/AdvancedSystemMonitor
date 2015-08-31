# include "MemoryAgent.hh"

Base::MemoryAgent::MemoryAgent ( std::string monitoring_folder )
   : Agent ( monitoring_folder )
{
   mMemoryInformation = new Base::DataTypes::MemoryInformation;
}

Base::MemoryAgent::~MemoryAgent ( void )
{
   delete mMemoryInformation;
}

bool Base::MemoryAgent::update ( void )
{
   /*
    * The memory can be monitored using the file statm, which has a format like this:
    * 
    * "172494 43393 11339 31 0 133622 0"
    * 
    */
   
   std::string file_to_verify;   
   std::string file_contents;
   std::string load_command;
   std::string line_loaded;
   
   file_to_verify = "/proc/";
   file_to_verify += mMonitoringFolder;
   file_to_verify += "/statm";
   
   load_command = "cat ";
   load_command += file_to_verify;
   
   mMemoryInformation->reset ();
   
   file_contents = runCommand ( load_command );
   
   if ( file_contents == "ERROR" )
      return ( false );
   
   std::istringstream iss ( file_contents );
   
   iss >> (*mMemoryInformation);
   
   return ( true );
}

Base::DataTypes::MemoryInformation* Base::MemoryAgent::getMemoryInformation(void)
{
   return ( mMemoryInformation );
}
