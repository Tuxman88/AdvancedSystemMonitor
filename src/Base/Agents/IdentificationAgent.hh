# ifndef IDENTIFICATIONAGENT_HH
# define IDENTIFICATIONAGENT_HH

# include <iostream>
# include <string>

# include "Agent.hh"
# include "../DataTypes/IdentificationInformation.hh"

namespace Base
{
   class IdentificationAgent : public Base::Agent
   {
      public:
         IdentificationAgent ( std::string monitoring_folder );
         ~IdentificationAgent ( void );
         
         bool update ( void );
         
         Base::DataTypes::IdentificationInformation* getIdentificationInformation ( void );
         
      private:
         bool loadCommandLine ( void );
         bool loadLoginUID ( void );
         bool loadStat ( void );
         
      private:
         Base::DataTypes::IdentificationInformation* mIdentificationInformation;
   };
}

# endif
