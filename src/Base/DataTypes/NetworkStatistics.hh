# ifndef NETWORKSTATISTICS_HH_
# define NETWORKSTATISTICS_HH_

# include <string>

namespace Base
{
   namespace DataTypes
   {
      struct t_NetworkStatistics
      {
         t_NetworkStatistics ( void );
         
         void reset ( void );
         
         unsigned long int Bytes;
         unsigned long int Packets;
         unsigned long int Errors;
         unsigned long int DroppedPackets;
         unsigned long int FifoOverruns;
         unsigned long int FrameErrors;
         unsigned long int CompressedPackets;
         unsigned long int MulticastPackets;
         unsigned long int CarrierErrors;
         unsigned long int Collitions;
      };
      typedef struct t_NetworkStatistics NetworkStatistics;
   }
}

# endif
