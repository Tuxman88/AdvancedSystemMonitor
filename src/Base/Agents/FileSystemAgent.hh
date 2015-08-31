# ifndef FILESYSTEMAGENT_HH
# define FILESYSTEMAGENT_HH

# include <iostream>
# include <string>

# include "Agent.hh"
# include "../DataTypes/FileInformation.hh"

namespace Base
{
   class FileSystemAgent : public Base::Agent
   {
      public:
         FileSystemAgent ( std::string monitoring_folder );
         ~FileSystemAgent ( void );
         
         bool update ( void );
         
         std::vector< Base::DataType::FileInformation >* getFilesInformation ( void );
         
      private:
         std::vector< Base::DataType::FileInformation >* mFilesInformation;
   };
}

# endif
 
