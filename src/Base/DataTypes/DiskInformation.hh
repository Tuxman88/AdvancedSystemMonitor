# ifndef DISKINFORMATION_HH_
# define DISKINFORMATION_HH_

# include <iostream>
# include <sstream>

namespace Base
{
   namespace DataTypes
   {
      struct t_DiskInformation;
   }
}

std::istream& operator>> ( std::istream& input , struct Base::DataTypes::t_DiskInformation& data );

namespace Base
{
   namespace DataTypes
   {
      struct t_DiskInformation
      {
         t_DiskInformation ( void );
         
         void reset ( void );
         
         friend std::istream& (::operator>>) ( std::istream& input , struct Base::DataTypes::t_DiskInformation& data );
         
         unsigned long int BytesRead;
         unsigned long int BytesWriten;
         unsigned long int WriteCalls;
         unsigned long int ReadCalls;
         unsigned long int RealBytesRead;
         unsigned long int RealBytesWriten;
         unsigned long int CancelledBytes;
      };
      typedef struct t_DiskInformation DiskInformation;
   }
}

# endif
