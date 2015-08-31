# ifndef MEMORYINFORMATION_HH_
# define MEMORYINFORMATION_HH_

# include <iostream>

namespace Base
{
   namespace DataTypes
   {
      struct t_MemoryInformation;
   }
}

std::istream& operator>> ( std::istream& input , struct Base::DataTypes::t_MemoryInformation& data );

namespace Base
{
   namespace DataTypes
   {
      struct t_MemoryInformation
      {
         t_MemoryInformation ( void );
         
         void reset ( void );
         
         friend std::istream& (::operator>>) ( std::istream& input , struct Base::DataTypes::t_MemoryInformation& data );
         
         unsigned long int TotalProgramSize;
         unsigned long int ResidentSetSize;
         unsigned long int SharedPages;
         unsigned long int Text;
         unsigned long int Library;
         unsigned long int DataAndStack;
         unsigned long int DirtyPages;
      };
      typedef struct t_MemoryInformation MemoryInformation;
   }
}

# endif
