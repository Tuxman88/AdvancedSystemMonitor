# ifndef EXTENDEDAGENT_HH
# define EXTENDEDAGENT_HH

# include <iostream>
# include <string>

# include "Agent.hh"

namespace Base
{
   class ExtendedAgent : public Base::Agent
   {
      public:
         struct t_ExtendedInformation
         {
            t_ExtendedInformation ( void )
            {
               reset ();
            }
            
            void reset ( void )
            {
               KernelFlags = 0;
               MinorMemoryFaults = 0;
               MinorChildrenMemoryFaults = 0;
               MajorMemoryFaults = 0;
               MajorChildrenMemoryFaults = 0;
               UserTime = 0;
               KernelTime = 0;
               ChildrenUserTime = 0;
               ChildrenKernelTime = 0;
               Priority = 0;
               NiceValue = 0;
               NumberOfThreads = 0;
               JiffiesTime = 0;
               StartTime = 0;
               VirtualMemorySize = 0;
               ResidentMemorySetSize = 0;
               CurrentSoftLimit = 0;
               StartCode = 0;
               EndCode = 0;
               StartStack = 0;
               StackPointer = 0;
               InstructionPointer = 0;
               PendingSignals = 0;
               BlockedSignals = 0;
               IgnoredSignals = 0;
               CatchedSignals = 0;
               WaitingSignals = 0;
               PagesSwaped = 0;
               ChildrenPagesSwaped = 0;
               ExitSignal = 0;
               Processor = 0;
               RealTimeSchedulingPriority = 0;
               SchedulingPolicy = 0;
               DelayInBlocks = 0;
               GuestTime = 0;
               ChildrenGuestTime = 0;
               StartData = 0;
               EndData = 0;
               StartExpansion = 0;
               ArgumentsStart = 0;
               ArgumentsEnd = 0;
               EnvironmentStart = 0;
               EnvironmentEnd = 0;
               ExitCode = 0;
               
               return;
            }
            
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
         
         ExtendedAgent ( std::string monitoring_folder );
         ~ExtendedAgent ( void );
         
         bool update ( void );
         
         ExtendedInformation* getIdentificationInformation ( void );
         
      private:
         ExtendedInformation* mExtendedInformation;
   };
}

# endif
 
