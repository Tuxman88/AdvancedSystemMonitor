# include "ExtendedInformation.hh"

Base::DataTypes::t_ExtendedInformation::t_ExtendedInformation ( void )
{
   reset ();
}

void Base::DataTypes::t_ExtendedInformation::reset ( void )
{
   KernelFlags                = 0;
   MinorMemoryFaults          = 0;
   MinorChildrenMemoryFaults  = 0;
   MajorMemoryFaults          = 0;
   MajorChildrenMemoryFaults  = 0;
   UserTime                   = 0;
   KernelTime                 = 0;
   ChildrenUserTime           = 0;
   ChildrenKernelTime         = 0;
   Priority                   = 0;
   NiceValue                  = 0;
   NumberOfThreads            = 0;
   JiffiesTime                = 0;
   StartTime                  = 0;
   VirtualMemorySize          = 0;
   ResidentMemorySetSize      = 0;
   CurrentSoftLimit           = 0;
   StartCode                  = 0;
   EndCode                    = 0;
   StartStack                 = 0;
   StackPointer               = 0;
   InstructionPointer         = 0;
   PendingSignals             = 0;
   BlockedSignals             = 0;
   IgnoredSignals             = 0;
   CatchedSignals             = 0;
   WaitingSignals             = 0;
   PagesSwaped                = 0;
   ChildrenPagesSwaped        = 0;
   ExitSignal                 = 0;
   Processor                  = 0;
   RealTimeSchedulingPriority = 0;
   SchedulingPolicy           = 0;
   DelayInBlocks              = 0;
   GuestTime                  = 0;
   ChildrenGuestTime          = 0;
   StartData                  = 0;
   EndData                    = 0;
   StartExpansion             = 0;
   ArgumentsStart             = 0;
   ArgumentsEnd               = 0;
   EnvironmentStart           = 0;
   EnvironmentEnd             = 0;
   ExitCode                   = 0;
   
   return;
}

std::istream& operator>> ( std::istream& input, struct Base::DataTypes::t_ExtendedInformation& data )
{   
   std::string dummy;
   
   // Not loading the first 6 values since I don't need them
   input >> dummy;
   input >> dummy;
   input >> dummy;
   input >> dummy;
   input >> dummy;
   input >> dummy;
   
   input >> data.KernelFlags;
   input >> data.MinorMemoryFaults;
   input >> data.MinorChildrenMemoryFaults;
   input >> data.MajorMemoryFaults;
   input >> data.MajorChildrenMemoryFaults;
   input >> data.UserTime;
   input >> data.KernelTime;
   input >> data.ChildrenUserTime;
   input >> data.ChildrenKernelTime;
   input >> data.Priority;
   input >> data.NiceValue;
   input >> data.NumberOfThreads;
   input >> data.JiffiesTime;
   input >> data.StartTime;
   input >> data.VirtualMemorySize;
   input >> data.ResidentMemorySetSize;
   input >> data.CurrentSoftLimit;
   input >> data.StartCode;
   input >> data.EndCode;
   input >> data.StartStack;
   input >> data.StackPointer;
   input >> data.InstructionPointer;
   input >> data.PendingSignals;
   input >> data.BlockedSignals;
   input >> data.IgnoredSignals;
   input >> data.CatchedSignals;
   input >> data.WaitingSignals;
   input >> data.PagesSwaped;
   input >> data.ChildrenPagesSwaped;
   input >> data.ExitSignal;
   input >> data.Processor;
   input >> data.RealTimeSchedulingPriority;
   input >> data.SchedulingPolicy;
   input >> data.DelayInBlocks;
   input >> data.GuestTime;
   input >> data.ChildrenGuestTime;
   input >> data.StartData;
   input >> data.EndData;
   input >> data.StartExpansion;
   input >> data.ArgumentsStart;
   input >> data.ArgumentsEnd;
   input >> data.EnvironmentStart;
   input >> data.EnvironmentEnd;
   input >> data.ExitCode;
   
   return ( input );
}
