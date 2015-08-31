# include "ExtendedAgent.hh"

Base::ExtendedAgent::ExtendedAgent ( std::string monitoring_folder )
   : Agent ( monitoring_folder )
{
   mExtendedInformation = new Base::DataTypes::ExtendedInformation;
}

Base::ExtendedAgent::~ExtendedAgent ( void )
{
   delete mExtendedInformation;
}

bool Base::ExtendedAgent::update ( void )
{
   /*
    * The file contents are just a series of values. These values represent the components I'm looking for.
    * 
    */
   
   std::string file_to_verify;   
   std::string file_contents;
   std::string load_command;
   
   file_to_verify = "/proc/";
   file_to_verify += mMonitoringFolder;
   file_to_verify += "/stat";
   
   load_command = "cat ";
   load_command += file_to_verify;
   
   file_contents = runCommand ( load_command );

   if ( file_contents == "ERROR" )
      return ( false );
   
   // Split the string using a right parentheses as separator. This will help me to
   // remove some values I don't need
   std::vector< std::string > pieces;
   
   pieces = splitString ( file_contents , ") " ); // With an added space to remove it from the result
   
   if ( pieces.size () != 2 ) // There must be 2 components
      return ( false );
   
   mExtendedInformation->reset ();
   
   std::istringstream iss ( pieces[ 1 ] );
   
   iss >> (*mExtendedInformation);
   
   return ( true );
}

Base::DataTypes::ExtendedInformation* Base::ExtendedAgent::getIdentificationInformation ( void )
{
   return ( mExtendedInformation );
}
