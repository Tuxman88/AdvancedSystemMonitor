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
         explicit FileSystemAgent ( std::string monitoring_folder );
         virtual ~FileSystemAgent ( void );
         
         bool update ( void );
         
         std::vector< Base::DataType::FileInformation* >* getFilesInformation ( void );
         
      private:
         void deleteFilesInformation     ( void );
         void processLine                ( std::string& line_loaded );
         void processDetail              ( std::string& line_loaded , Base::DataType::FileInformation* information );
         void extractDetailedInformation ( Base::DataType::FileInformation* information );
         
      private:
         std::vector< Base::DataType::FileInformation* >* mFilesInformation;
   };
}

# endif
 
