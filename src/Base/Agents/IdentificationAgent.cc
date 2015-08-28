# include "IdentificationAgent.hh"

Base::IdentificationAgent::IdentificationAgent ( std::string monitoring_folder )
   : Agent ( monitoring_folder )
{
   mIdentificationInformation = new IdentificationInformation;
}

Base::IdentificationAgent::~IdentificationAgent ( void )
{
   delete mIdentificationInformation;
}

bool Base::IdentificationAgent::update ( void )
{
   /*
    * There is needed to access the following files:
    * 
    * cmdline
    * loginuid
    * stat
    * 
    */
   
   mIdentificationInformation->reset ();
   
   if ( !loadCommandLine () )
      return ( false );
   
   if ( !loadLoginUID () )
      return ( false );
   
   if ( !loadStat () )
      return ( false );
   
   return ( true );
}

Base::IdentificationAgent::IdentificationInformation* Base::IdentificationAgent::getIdentificationInformation ( void )
{
   return ( mIdentificationInformation );
}

bool Base::IdentificationAgent::loadCommandLine ( void )
{
   /*
    * The file contents are just the command, so, take such value directly.
    */
   
   std::string file_to_verify;   
   std::string file_contents;
   std::string load_command;
   
   file_to_verify = "/proc/";
   file_to_verify += mMonitoringFolder;
   file_to_verify += "/cmdline";
   
   load_command = "cat ";
   load_command += file_to_verify;
   
   file_contents = runCommand ( load_command );
   
   if ( file_contents == "ERROR" )
      return ( false );
   
   mIdentificationInformation->CommandLine = file_contents;
   
   return ( true );
}

bool Base::IdentificationAgent::loadLoginUID ( void )
{
   /*
    * The file contents are just the UID, so, take such value directly.
    */
   
   std::string file_to_verify;   
   std::string file_contents;
   std::string load_command;
   unsigned long int value_loaded;
   
   file_to_verify = "/proc/";
   file_to_verify += mMonitoringFolder;
   file_to_verify += "/loginuid";
   
   load_command = "cat ";
   load_command += file_to_verify;
   
   file_contents = runCommand ( load_command );
   
   if ( file_contents == "ERROR" )
      return ( false );
   
   std::istringstream iss ( file_contents );
   
   iss >> value_loaded;
   
   mIdentificationInformation->LoginUID = value_loaded;
   
   return ( true );
}

bool Base::IdentificationAgent::loadStat ( void )
{
   /*
    * The file contents are just the command, so, take such value directly.
    */
   
   std::string file_to_verify;   
   std::string file_contents;
   std::string load_command;
   std::string line_loaded;
   
   file_to_verify = "/proc/";
   file_to_verify += mMonitoringFolder;
   file_to_verify += "/stat";
   
   load_command = "cat ";
   load_command += file_to_verify;
   
   file_contents = runCommand ( load_command );
   
   if ( file_contents == "ERROR" )
      return ( false );
   
   // We have a string like this:
   // 1568 (iceweasel) S 1133 1133 1133 0 -1 4202496 52826 1484 461 40
   // Since we don't have any guarantee that the command name doesn't have spaces, I'll split
   // the string using the right parentheses and then, the left piece, split it using the left
   // parentheses so that I will end with the string in a known format.
   
   std::vector< std::string > main_pieces;
   
   main_pieces = splitString ( file_contents , ")" );
   
   if ( main_pieces.size () != 2 )
      return ( false );
   
   // Reuse the variables
   file_contents = main_pieces[ 1 ];
   
   main_pieces = splitString ( main_pieces[ 0 ] , "(" );
   
   if ( main_pieces.size () != 2 )
      return ( false );
   
   mIdentificationInformation->PID = toULInt ( main_pieces[ 0 ] );
   mIdentificationInformation->Command = main_pieces[ 1 ];
   
   std::istringstream iss ( file_contents );
   
   iss >> mIdentificationInformation->State;
   iss >> mIdentificationInformation->ParentPID;
   iss >> mIdentificationInformation->ProcessGroupID;
   iss >> mIdentificationInformation->SessionID;
   iss >> mIdentificationInformation->ControllingTerminal;
   iss >> mIdentificationInformation->ForegroundProcessGroupID;
   
   return ( true );
}
