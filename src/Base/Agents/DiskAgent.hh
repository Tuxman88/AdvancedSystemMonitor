# ifndef DISKAGENT_HH_
# define DISKAGENT_HH_

# include <iostream>
# include <string>

# include "Agent.hh"
# include "../DataTypes/DiskInformation.hh"

namespace Base
{
   class DiskAgent : public Base::Agent
   {
      public:         
         explicit DiskAgent ( std::string monitoring_folder );
         virtual ~DiskAgent ( void );
         
         bool update ( void );
         
         Base::DataTypes::DiskInformation* getDiskInformation ( void );
         
      private:
         Base::DataTypes::DiskInformation* mDiskInformation;
   };
}

# endif
