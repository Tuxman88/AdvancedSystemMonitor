# ifndef MEMORYAGENT_HH
# define MEMORYAGENT_HH

# include <iostream>
# include <string>
# include <vector>

# include "Agent.hh"
# include "../DataTypes/MemoryInformation.hh"

namespace Base
{
   class MemoryAgent : public Agent
   {
      public:
         explicit MemoryAgent ( std::string monitoring_folder );
         virtual ~MemoryAgent ( void );
         
         bool update ( void );
         
         Base::DataTypes::MemoryInformation* getMemoryInformation ( void );
         
      private:
         Base::DataTypes::MemoryInformation* mMemoryInformation;
   };
}

# endif
