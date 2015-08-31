# ifndef MOUNTTYPE_HH
# define MOUNTTYPE_HH

# include <string>

namespace Base
{
   namespace DataType
   {
      struct t_MountType
      {
         t_MountType ( void );
         void reset ( void );
         
         std::string MainType;
         std::string SubType;
      };
      typedef struct t_MountType MountType;
   }
}

# endif
 
