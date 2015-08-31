# ifndef MOUNTINFORMATION_HH
# define MOUNTINFORMATION_HH

# include <string>
# include <vector>

# include "OptionalField.hh"
# include "MountType.hh"

namespace Base
{
   namespace DataType
   {
      struct t_MountInformation
      {
         t_MountInformation ( void );
         void reset ( void );
         
         unsigned long int            ID;
         unsigned long int            Parent;
         std::string                  MajorMinor;
         std::string                  RootPath;
         std::string                  MountPoint;
         std::vector< std::string >   MountOptions;
         std::vector< OptionalField > OptionalFields;
         MountType                    FileSystemType;
         std::string                  Source;
         std::vector< std::string >   SuperOptions;
      };
      typedef struct t_MountInformation MountInformation;
   }
}

# endif
