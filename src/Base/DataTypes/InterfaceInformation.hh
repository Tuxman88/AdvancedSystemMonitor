# ifndef INTERFACEINFORMATION_HH_
# define INTERFACEINFORMATION_HH_

# include <string>

# include "NetworkStatistics.hh"

namespace Base
{
   namespace DataTypes
   {
      struct t_InterfaceInformation
      {
         t_InterfaceInformation ( void );
         
         void reset ( void );
         
         std::string                        InterfaceName;
         Base::DataTypes::NetworkStatistics InputInfo;
         Base::DataTypes::NetworkStatistics OutputInfo;
         // TODO: Sockets
      };
      typedef struct t_InterfaceInformation InterfaceInformation;
   }
}

# endif
