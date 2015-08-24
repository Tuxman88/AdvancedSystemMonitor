# ifndef COMMAND_MANAGER_HH
# define COMMAND_MANAGER_HH

# include <iostream>
# include <string>
# include <cstdlib>
# include <cstdio>

namespace Base
{
   class CommandManager
   {
      public:
         static std::string runCommand ( std::string command_to_run );
   };
}

# endif
