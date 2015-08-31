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
         DiskAgent ( std::string monitoring_folder );
         ~DiskAgent ( void );
         
         bool update ( void );
         
         Base::DataTypes::DiskInformation* getDiskInformation ( void );
         
      private:
         Base::DataTypes::DiskInformation* mDiskInformation;
   };
}

# endif
