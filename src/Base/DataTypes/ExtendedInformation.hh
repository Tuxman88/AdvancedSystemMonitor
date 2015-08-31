# ifndef EXTENDEDINFORMATION_HH_
# define EXTENDEDINFORMATION_HH_

# include <iostream>

namespace Base
{
   namespace DataTypes
   {
      struct t_ExtendedInformation;
   }
}

std::istream& operator>> ( std::istream& input , struct Base::DataTypes::t_ExtendedInformation& data );

namespace Base
{
   namespace DataTypes
   {
      struct t_ExtendedInformation
      {
         t_ExtendedInformation ( void );
         
         void reset ( void );
         
         friend std::istream& (::operator>>) ( std::istream& input , struct Base::DataTypes::t_ExtendedInformation& data );
         
         unsigned long int KernelFlags;
         unsigned long int MinorMemoryFaults;
         unsigned long int MinorChildrenMemoryFaults;
         unsigned long int MajorMemoryFaults;
         unsigned long int MajorChildrenMemoryFaults;
         unsigned long int UserTime;
         unsigned long int KernelTime;
         unsigned long int ChildrenUserTime;
         unsigned long int ChildrenKernelTime;
         unsigned long int Priority;
         unsigned long int NiceValue;
         unsigned long int NumberOfThreads;
         unsigned long int JiffiesTime;
         unsigned long int StartTime;
         unsigned long int VirtualMemorySize;
         unsigned long int ResidentMemorySetSize;
         unsigned long int CurrentSoftLimit;
         unsigned long int StartCode;
         unsigned long int EndCode;
         unsigned long int StartStack;
         unsigned long int StackPointer;
         unsigned long int InstructionPointer;
         unsigned long int PendingSignals;
         unsigned long int BlockedSignals;
         unsigned long int IgnoredSignals;
         unsigned long int CatchedSignals;
         unsigned long int WaitingSignals;
         unsigned long int PagesSwaped;
         unsigned long int ChildrenPagesSwaped;
         unsigned long int ExitSignal;
         unsigned long int Processor;
         unsigned long int RealTimeSchedulingPriority;
         unsigned long int SchedulingPolicy;
         unsigned long int DelayInBlocks;
         unsigned long int GuestTime;
         unsigned long int ChildrenGuestTime;
         unsigned long int StartData;
         unsigned long int EndData;
         unsigned long int StartExpansion;
         unsigned long int ArgumentsStart;
         unsigned long int ArgumentsEnd;
         unsigned long int EnvironmentStart;
         unsigned long int EnvironmentEnd;
         unsigned long int ExitCode;
      };
      typedef struct t_ExtendedInformation ExtendedInformation;
   }
}

# endif
