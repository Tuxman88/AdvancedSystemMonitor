# include <iostream>
# include <string>
# include <cstdlib>

# include "Base/Agents/NetworkAgent.hh"

using namespace std;

int main ()
{
   Base::NetworkAgent network ( "1666" );
   
   int c = 0;
   
   while ( c < 100 )
   {
      network.update ();
      
      std::vector< std::string > interfaces;
      interfaces = network.getAvailableInterfaces ();
      
      for ( unsigned int i = 0; i < interfaces.size (); i++ )
      {
         Base::NetworkAgent::InterfaceInformation* info;
         info = network.getInterfaceInformation ( interfaces[ i ] );
         
         std::cout << "Name: " << info->InterfaceName << std::endl << std::endl;
         
         std::cout << "INPUT: " << std::endl << std::endl;
         
         std::cout << "Bytes:             " << info->InputInfo.Bytes << std::endl;
         std::cout << "Packets:           " << info->InputInfo.Packets << std::endl;
         std::cout << "Errors:            " << info->InputInfo.Errors << std::endl;
         std::cout << "DroppedPackets:    " << info->InputInfo.DroppedPackets << std::endl;
         std::cout << "FifoOverruns:      " << info->InputInfo.FifoOverruns << std::endl;
         std::cout << "FrameErrors:       " << info->InputInfo.FrameErrors << std::endl;
         std::cout << "CompressedPackets: " << info->InputInfo.CompressedPackets << std::endl;
         std::cout << "MulticastPackets:  " << info->InputInfo.MulticastPackets << std::endl;
         std::cout << "CarrierErrors:     " << info->InputInfo.CarrierErrors << std::endl;
         std::cout << "Collitions:        " << info->InputInfo.Collitions << std::endl << std::endl;
         
         std::cout << "OUTPUT: " << std::endl << std::endl;
         
         std::cout << "Bytes:             " << info->OutputInfo.Bytes << std::endl;
         std::cout << "Packets:           " << info->OutputInfo.Packets << std::endl;
         std::cout << "Errors:            " << info->OutputInfo.Errors << std::endl;
         std::cout << "DroppedPackets:    " << info->OutputInfo.DroppedPackets << std::endl;
         std::cout << "FifoOverruns:      " << info->OutputInfo.FifoOverruns << std::endl;
         std::cout << "FrameErrors:       " << info->OutputInfo.FrameErrors << std::endl;
         std::cout << "CompressedPackets: " << info->OutputInfo.CompressedPackets << std::endl;
         std::cout << "MulticastPackets:  " << info->OutputInfo.MulticastPackets << std::endl;
         std::cout << "CarrierErrors:     " << info->OutputInfo.CarrierErrors << std::endl;
         std::cout << "Collitions:        " << info->OutputInfo.Collitions << std::endl << std::endl;
      }
      
      system ( "sleep 0.1s" );
      
      c++;
   }
   
   return ( 0 );
}