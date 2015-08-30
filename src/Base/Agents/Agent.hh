# ifndef AGENT_HH
# define AGENT_HH

# include <iostream>
# include <string>
# include <sstream>
# include <vector>
# include <cstdlib>
# include <cstdio>
# include <cstring>

namespace Base
{
   class Agent
   {
      public:
         Agent ( std::string monitoring_folder );
         
         virtual bool update ( void ) = 0;
         
      protected:
         std::string                runCommand  ( std::string command_to_run );
         std::vector< std::string > splitString ( std::string string_to_split , const std::string& separator_string );
         std::string                trimString  ( std::string string_to_trim );
         std::string                toUpperCase ( std::string string_to_change );
         unsigned long int          toULInt     ( std::string string_to_convert );
         
      protected:
         std::string mMonitoringFolder;
   };
}

# endif
