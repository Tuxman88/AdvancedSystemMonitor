# include <iostream>
# include <string>
# include <cstdlib>

# include "Base/Agents/NetworkAgent.hh"
# include "Base/Agents/MemoryAgent.hh"
# include "Base/Agents/DiskAgent.hh"
# include "Base/Agents/IdentificationAgent.hh"
# include "Base/Agents/ExtendedAgent.hh"

using namespace std;

int main ()
{
   Base::NetworkAgent network ( "1221" );
   Base::MemoryAgent memory ( "1221" );
   Base::DiskAgent disk ( "1221" );
   Base::IdentificationAgent identification ( "1221" );
   Base::ExtendedAgent extended ( "1221" );
   
   int c = 0;
   
   while ( c < 1000 )
   {
      network.update ();
      memory.update ();
      disk.update ();
      identification.update ();
      extended.update ();
      
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
      
      std::cout << "Kernel flags:                  " << extended.getIdentificationInformation ()->KernelFlags << std::endl;
      std::cout << "Minor memory faults:           " << extended.getIdentificationInformation ()->MinorMemoryFaults << std::endl;
      std::cout << "Minor children memory faults:  " << extended.getIdentificationInformation ()->MinorChildrenMemoryFaults << std::endl;
      std::cout << "Major memory faults:           " << extended.getIdentificationInformation ()->MajorMemoryFaults << std::endl;
      std::cout << "Major children memory faults:  " << extended.getIdentificationInformation ()->MajorChildrenMemoryFaults << std::endl;
      std::cout << "User time:                     " << extended.getIdentificationInformation ()->UserTime << std::endl;
      std::cout << "Kernel time:                   " << extended.getIdentificationInformation ()->KernelTime << std::endl;
      std::cout << "Children user time:            " << extended.getIdentificationInformation ()->ChildrenUserTime << std::endl;
      std::cout << "Children kernel time:          " << extended.getIdentificationInformation ()->ChildrenKernelTime << std::endl;
      std::cout << "Priority:                      " << extended.getIdentificationInformation ()->Priority << std::endl;
      std::cout << "Nice value:                    " << extended.getIdentificationInformation ()->NiceValue << std::endl;
      std::cout << "Number of threads:             " << extended.getIdentificationInformation ()->NumberOfThreads << std::endl;
      std::cout << "Jiffies time:                  " << extended.getIdentificationInformation ()->JiffiesTime << std::endl;
      std::cout << "Start time:                    " << extended.getIdentificationInformation ()->StartTime << std::endl;
      std::cout << "Virtual memory size:           " << extended.getIdentificationInformation ()->VirtualMemorySize << std::endl;
      std::cout << "Resident set size:             " << extended.getIdentificationInformation ()->ResidentMemorySetSize << std::endl;
      std::cout << "Current soft limit:            " << extended.getIdentificationInformation ()->CurrentSoftLimit << std::endl;
      std::cout << "Start code:                    " << extended.getIdentificationInformation ()->StartCode << std::endl;
      std::cout << "End code:                      " << extended.getIdentificationInformation ()->EndCode << std::endl;
      std::cout << "Start stack:                   " << extended.getIdentificationInformation ()->StartStack << std::endl;
      std::cout << "Stack pointer:                 " << extended.getIdentificationInformation ()->StackPointer << std::endl;
      std::cout << "Instruction pointer:           " << extended.getIdentificationInformation ()->InstructionPointer << std::endl;
      std::cout << "Pending signals:               " << extended.getIdentificationInformation ()->PendingSignals << std::endl;
      std::cout << "Blocked signals:               " << extended.getIdentificationInformation ()->BlockedSignals << std::endl;
      std::cout << "Ignored signals:               " << extended.getIdentificationInformation ()->IgnoredSignals << std::endl;
      std::cout << "Catched signals:               " << extended.getIdentificationInformation ()->CatchedSignals << std::endl;
      std::cout << "Waiting signals:               " << extended.getIdentificationInformation ()->WaitingSignals << std::endl;
      std::cout << "Pages swaped:                  " << extended.getIdentificationInformation ()->PagesSwaped << std::endl;
      std::cout << "Children pages swaped:         " << extended.getIdentificationInformation ()->ChildrenPagesSwaped << std::endl;
      std::cout << "Exit signal:                   " << extended.getIdentificationInformation ()->ExitSignal << std::endl;
      std::cout << "Processor:                     " << extended.getIdentificationInformation ()->Processor << std::endl;
      std::cout << "Real time scheduling priority: " << extended.getIdentificationInformation ()->RealTimeSchedulingPriority << std::endl;
      std::cout << "Scheduling policy:             " << extended.getIdentificationInformation ()->SchedulingPolicy << std::endl;
      std::cout << "Delay in blocks:               " << extended.getIdentificationInformation ()->DelayInBlocks << std::endl;
      std::cout << "Guest time:                    " << extended.getIdentificationInformation ()->GuestTime << std::endl;
      std::cout << "Children guest time:           " << extended.getIdentificationInformation ()->ChildrenGuestTime << std::endl;
      std::cout << "Start data:                    " << extended.getIdentificationInformation ()->StartData << std::endl;
      std::cout << "End data:                      " << extended.getIdentificationInformation ()->EndData << std::endl;
      std::cout << "Start expansion:               " << extended.getIdentificationInformation ()->StartExpansion << std::endl;
      std::cout << "Arguments start:               " << extended.getIdentificationInformation ()->ArgumentsStart << std::endl;
      std::cout << "Arguments end:                 " << extended.getIdentificationInformation ()->ArgumentsEnd << std::endl;
      std::cout << "Environment start:             " << extended.getIdentificationInformation ()->EnvironmentStart << std::endl;
      std::cout << "Environment end:               " << extended.getIdentificationInformation ()->EnvironmentEnd << std::endl;
      std::cout << "Exit code:                     " << extended.getIdentificationInformation ()->ExitCode << std::endl;
      
      system ( "sleep 0.1s" );
      
      c++;
   }
   
   return ( 0 );
}