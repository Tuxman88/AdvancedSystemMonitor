# ifndef FILEINFORMATION_HH
# define FILEINFORMATION_HH

# include <string>
# include <vector>

# include "MountInformation.hh"

namespace Base
{
   namespace DataType
   {
      struct t_FileInformation
      {
         t_FileInformation  ( void );
         ~t_FileInformation ( void );
         
         void reset ( void );
         
         unsigned long int                 FileDescriptorID;
         std::string                       FilePath;
         unsigned long int                 FileOffset;
         std::string                       FileFlags;
         Base::DataType::MountInformation* MountInfo;
      };
      typedef struct t_FileInformation FileInformation;
   }
}

# endif
