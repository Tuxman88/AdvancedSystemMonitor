# include <iostream>
# include <string>
# include <cstdlib>

# include "Base/Agents/NetworkAgent.hh"
# include "Base/Agents/MemoryAgent.hh"
# include "Base/Agents/DiskAgent.hh"
# include "Base/Agents/IdentificationAgent.hh"

using namespace std;

int main ()
{
   Base::NetworkAgent network ( "1568" );
   Base::MemoryAgent memory ( "1568" );
   Base::DiskAgent disk ( "1568" );
   Base::IdentificationAgent identification ( "1568" );
   
   int c = 0;
   
   while ( c < 1000 )
   {
      network.update ();
      memory.update ();
      disk.update ();
      identification.update ();
      
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
      
      std::cout << "TotalProgramSize: " << memory.getMemoryInformation ()->TotalProgramSize << std::endl;
      std::cout << "ResidentSetSize:  " << memory.getMemoryInformation ()->ResidentSetSize << std::endl;
      std::cout << "SharedPages:      " << memory.getMemoryInformation ()->SharedPages << std::endl;
      std::cout << "Text:             " << memory.getMemoryInformation ()->Text << std::endl;
      std::cout << "Library:          " << memory.getMemoryInformation ()->Library << std::endl;
      std::cout << "DataAndStack:     " << memory.getMemoryInformation ()->DataAndStack << std::endl;
      std::cout << "DirtyPages:       " << memory.getMemoryInformation ()->DirtyPages << std::endl << std::endl;
      
      std::cout << "Bytes Read:        " << disk.getDiskInformation ()->BytesRead << std::endl;
      std::cout << "Bytes Writen:      " << disk.getDiskInformation ()->BytesWriten << std::endl;
      std::cout << "Read Calls:        " << disk.getDiskInformation ()->ReadCalls << std::endl;
      std::cout << "Write Calls:       " << disk.getDiskInformation ()->WriteCalls << std::endl;
      std::cout << "Real Bytes Read:   " << disk.getDiskInformation ()->RealBytesRead << std::endl;
      std::cout << "Real Bytes Writen: " << disk.getDiskInformation ()->RealBytesWriten << std::endl;
      std::cout << "Cancelled Bytes:   " << disk.getDiskInformation ()->CancelledBytes << std::endl << std::endl;
      
      std::cout << "Command line:                " << identification.getIdentificationInformation ()->CommandLine << std::endl;
      std::cout << "Login UID:                   " << identification.getIdentificationInformation ()->LoginUID << std::endl;
      std::cout << "PID:                         " << identification.getIdentificationInformation ()->PID << std::endl;
      std::cout << "Command:                     " << identification.getIdentificationInformation ()->Command << std::endl;
      std::cout << "State:                       " << identification.getIdentificationInformation ()->State << std::endl;
      std::cout << "Parent PID:                  " << identification.getIdentificationInformation ()->ParentPID << std::endl;
      std::cout << "Process group ID:            " << identification.getIdentificationInformation ()->ProcessGroupID << std::endl;
      std::cout << "Session ID:                  " << identification.getIdentificationInformation ()->SessionID << std::endl;
      std::cout << "Controlling Terminal:        " << identification.getIdentificationInformation ()->ControllingTerminal << std::endl;
      std::cout << "Foreground process group ID: " << identification.getIdentificationInformation ()->ForegroundProcessGroupID << std::endl << std::endl;
      
      system ( "sleep 0.1s" );
      
      c++;
   }
   
   return ( 0 );
}