# include "NetworkStatistics.hh"

Base::DataTypes::t_NetworkStatistics::t_NetworkStatistics ( void )
{
   reset ();
}

void Base::DataTypes::t_NetworkStatistics::reset ( void )
{
   Bytes = 0;
   Packets = 0;
   Errors = 0;
   DroppedPackets = 0;
   FifoOverruns = 0;
   FrameErrors = 0;
   CompressedPackets = 0;
   MulticastPackets = 0;
   CarrierErrors = 0;
   Collitions = 0;
}
