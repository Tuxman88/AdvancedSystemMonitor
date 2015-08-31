# ifndef OPTIONALFIELD_HH
# define OPTIONALFIELD_HH

# include <string>

namespace Base
{
   namespace DataType
   {
      struct t_OptionalField
      {
         t_OptionalField ( void );
         void reset ( void );
         
         std::string Tag;
         long int    Value;
      };
      typedef struct t_OptionalField OptionalField;
   }
}

# endif
