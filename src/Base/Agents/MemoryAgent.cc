# include "MemoryAgent.hh"

Base::MemoryAgent::MemoryAgent ( std::string monitoring_folder )
   : Agent ( monitoring_folder )
{
   mMemoryInformation = new MemoryInformation;
}

Base::MemoryAgent::~MemoryAgent ( void )
{
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
   
   iss >> mMemoryInformation->TotalProgramSize;
   iss >> mMemoryInformation->ResidentSetSize;
   iss >> mMemoryInformation->SharedPages;
   iss >> mMemoryInformation->Text;
   iss >> mMemoryInformation->Library;
   iss >> mMemoryInformation->DataAndStack;
   iss >> mMemoryInformation->DirtyPages;
   
   return ( true );
}

Base::MemoryAgent::MemoryInformation* Base::MemoryAgent::getMemoryInformation(void)
{
   return ( mMemoryInformation );
}
