# include "ExtendedAgent.hh"

Base::ExtendedAgent::ExtendedAgent ( std::string monitoring_folder )
   : Agent ( monitoring_folder )
{
   mExtendedInformation = new ExtendedInformation;
}

Base::ExtendedAgent::~ExtendedAgent ( void )
{
   delete mExtendedInformation;
}

bool Base::ExtendedAgent::update ( void )
{
   /*
    * The file contents are just a series of values. These values represent the components I'm looking for.
    * 
    */
   
   std::string file_to_verify;   
   std::string file_contents;
   std::string load_command;
   
   file_to_verify = "/proc/";
   file_to_verify += mMonitoringFolder;
   file_to_verify += "/stat";
   
   load_command = "cat ";
   load_command += file_to_verify;
   
   file_contents = runCommand ( load_command );
   
   std::cout << "Contents: " << file_contents << std::endl;
   
   if ( file_contents == "ERROR" )
      return ( false );
   
   // Split the string using a right parentheses as separator. This will help me to
   // remove some values I don't need
   std::vector< std::string > pieces;
   
   pieces = splitString ( file_contents , ") " ); // With an added space to remove it from the result
   
   if ( pieces.size () != 2 ) // There must be 2 components
      return ( false );
   
   // Split the second component using a whitespace as separator to be able to access these values directly
   pieces = splitString ( pieces[ 1 ] , " " );
   
   // Now, start at index 6 since the previous values have already been gathered by the IdentificationAgent.
   
   for ( unsigned int i = 6; i < pieces.size (); i++ )
      storeValue ( pieces[ i ] , i );
   
   return ( true );
}

Base::ExtendedAgent::ExtendedInformation* Base::ExtendedAgent::getIdentificationInformation ( void )
{
   return ( mExtendedInformation );
}

void Base::ExtendedAgent::storeValue ( std::string value, unsigned int position )
{
   std::cout << "Valor: " << value << std::endl;
   std::cout << "Posicion: " << position << std::endl;
   switch ( position )
   {
      case 6:
         mExtendedInformation->KernelFlags = toULInt ( value );
         break;
      case 7:
         mExtendedInformation->MinorMemoryFaults = toULInt ( value );
         break;
      case 8:
         mExtendedInformation->MinorChildrenMemoryFaults = toULInt ( value );
         break;
      case 9:
         mExtendedInformation->MajorMemoryFaults = toULInt ( value );
         break;
      case 10:
         mExtendedInformation->MajorChildrenMemoryFaults = toULInt ( value );
         break;
      case 11:
         mExtendedInformation->UserTime = toULInt ( value );
         break;
      case 12:
         mExtendedInformation->KernelTime = toULInt ( value );
         break;
      case 13:
         mExtendedInformation->ChildrenUserTime = toULInt ( value );
         break;
      case 14:
         mExtendedInformation->ChildrenKernelTime = toULInt ( value );
         break;
      case 15:
         mExtendedInformation->Priority = toULInt ( value );
         break;
      case 16:
         mExtendedInformation->NiceValue = toULInt ( value );
         break;
      case 17:
         mExtendedInformation->NumberOfThreads = toULInt ( value );
         break;
      case 18:
         mExtendedInformation->JiffiesTime = toULInt ( value );
         break;
      case 19:
         mExtendedInformation->StartTime = toULInt ( value );
         break;
      case 20:
         mExtendedInformation->VirtualMemorySize = toULInt ( value );
         break;
      case 21:
         mExtendedInformation->ResidentMemorySetSize = toULInt ( value );
         break;
      case 22:
         mExtendedInformation->CurrentSoftLimit = toULInt ( value );
         break;
      case 23:
         mExtendedInformation->StartCode = toULInt ( value );
         break;
      case 24:
         mExtendedInformation->EndCode = toULInt ( value );
         break;
      case 25:
         mExtendedInformation->StartStack = toULInt ( value );
         break;
      case 26:
         mExtendedInformation->StackPointer = toULInt ( value );
         break;
      case 27:
         mExtendedInformation->InstructionPointer = toULInt ( value );
         break;
      case 28:
         mExtendedInformation->PendingSignals = toULInt ( value );
         break;
      case 29:
         mExtendedInformation->BlockedSignals = toULInt ( value );
         break;
      case 30:
         mExtendedInformation->IgnoredSignals = toULInt ( value );
         break;
      case 31:
         mExtendedInformation->CatchedSignals = toULInt ( value );
         break;
      case 32:
         mExtendedInformation->WaitingSignals = toULInt ( value );
         break;
      case 33:
         mExtendedInformation->PagesSwaped = toULInt ( value );
         break;
      case 34:
         mExtendedInformation->ChildrenPagesSwaped = toULInt ( value );
         break;
      case 35:
         mExtendedInformation->ExitSignal = toULInt ( value );
         break;
      case 36:
         mExtendedInformation->Processor = toULInt ( value );
         break;
      case 37:
         mExtendedInformation->RealTimeSchedulingPriority = toULInt ( value );
         break;
      case 38:
         mExtendedInformation->SchedulingPolicy = toULInt ( value );
         break;
      case 39:
         mExtendedInformation->DelayInBlocks= toULInt ( value );
         break;
      case 40:
         mExtendedInformation->GuestTime = toULInt ( value );
         break;
      case 41:
         mExtendedInformation->ChildrenGuestTime = toULInt ( value );
         break;
      case 42:
         mExtendedInformation->StartData = toULInt ( value );
         break;
      case 43:
         mExtendedInformation->EndData = toULInt ( value );
         break;
      case 44:
         mExtendedInformation->StartExpansion = toULInt ( value );
         break;
      case 45:
         mExtendedInformation->ArgumentsStart = toULInt ( value );
         break;
      case 46:
         mExtendedInformation->ArgumentsEnd = toULInt ( value );
         break;
      case 47:
         mExtendedInformation->EnvironmentStart = toULInt ( value );
         break;
      case 48:
         mExtendedInformation->EnvironmentEnd = toULInt ( value );
         break;
      case 49:
         mExtendedInformation->ExitCode = toULInt ( value );
         break;
   }
   
   return;
}
