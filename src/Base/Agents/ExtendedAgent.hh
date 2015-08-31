# ifndef EXTENDEDAGENT_HH
# define EXTENDEDAGENT_HH

# include <iostream>
# include <string>

# include "Agent.hh"
# include "../DataTypes/ExtendedInformation.hh"

namespace Base
{
   class ExtendedAgent : public Base::Agent
   {
      public:
         ExtendedAgent ( std::string monitoring_folder );
         ~ExtendedAgent ( void );
         
         bool update ( void );
         
         Base::DataTypes::ExtendedInformation* getIdentificationInformation ( void );
         
      private:
         Base::DataTypes::ExtendedInformation* mExtendedInformation;
   };
}

# endif
 
