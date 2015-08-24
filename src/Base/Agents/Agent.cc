# include "Agent.hh" 

Base::Agent::Agent ( std::string monitoring_folder )
   : mMonitoringFolder ( monitoring_folder )
{
}

std::string Base::Agent::runCommand ( std::string command_to_run )
{
   FILE* pipe = popen ( command_to_run.c_str (), "r" );
   
   if ( !pipe )
      return "ERROR";
   
   char buffer[ 128 ];
   std::string result = "";
   
   while ( !feof ( pipe ) )
   {
      if ( fgets ( buffer , 128 , pipe ) != NULL )
         result += buffer;
   }
   
   pclose ( pipe );
   
   return result;
}

std::vector< std::string > Base::Agent::splitString ( std::string string_to_split , const std::string& separator_string )
{
   std::vector< std::string > pieces;
   int position;
   
   position = string_to_split.find ( separator_string );
   
   while ( position != (int)std::string::npos )
   {
      std::string tmp_str;
      unsigned long int tmp_int;
      
      tmp_str = string_to_split.substr ( 0 , position );
      tmp_int = position + separator_string.size ();
      
      string_to_split = string_to_split.substr ( tmp_int , string_to_split.size () - tmp_int );
      
      if ( !tmp_str.empty () )
         pieces.push_back ( tmp_str );
      
      position = string_to_split.find ( separator_string );
   }
   
   if ( !string_to_split.empty () )
      pieces.push_back ( string_to_split );
   
   return ( pieces );
}

std::string Base::Agent::trimString ( std::string string_to_trim )
{
   // Remove final ENTER
   if ( !string_to_trim.empty () && string_to_trim[ string_to_trim.size () - 1 ] == '\n' )
      string_to_trim.erase ( string_to_trim.begin () + string_to_trim.size () - 1 );
   
   while ( !string_to_trim.empty () && string_to_trim[ 0 ] == ' ' )
      string_to_trim.erase ( string_to_trim.begin () );
   
   while ( !string_to_trim.empty () && string_to_trim[ string_to_trim.size () - 1 ] == ' ' )
      string_to_trim.erase ( string_to_trim.begin () + string_to_trim.size () - 1 );
   
   return ( string_to_trim );
}

std::string Base::Agent::toUpperCase ( std::string string_to_change )
{
   for ( unsigned int i = 0; i < string_to_change.size (); i++ )
      string_to_change[ i ] = std::toupper ( string_to_change[ i ] );
   
   return ( string_to_change );
}
