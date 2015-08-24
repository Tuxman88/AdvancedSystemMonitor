# include "NetworkAgent.hh"

Base::NetworkAgent::NetworkAgent ( std::string monitoring_folder )
   : Agent ( monitoring_folder ) ,
     mFirstColumnType ( Input ) ,
     mSecondColumnType ( Output )
{
   
}

Base::NetworkAgent::~NetworkAgent ( void )
{
   cleanInformation ();
}

bool Base::NetworkAgent::update ( void )
{
   /*
    * From an input file like this:
    * 
    * Inter-|   Receive                                                |  Transmit
    *  face |bytes    packets errs drop fifo frame compressed multicast|bytes    packets errs drop fifo colls carrier compressed
    *  eth0: 234703361  227184    0    7    0     0          0         0 18395469  178876    0    0    0     0       0          0
    *  lo:   42395     571    0    0    0     0          0         0    42395     571    0    0    0     0       0          0
    *
    * I can know this:
    * 
    *    - The first line can tell me the order of the contents (first column of data is input, while the second is output)
    *    - The second line can tell me the order of the components of the information lines
    *    - From the third line, I can detect the interface and values, based in the information gathered with the previous lines.
    */
   
   std::string file_to_verify;   
   std::string file_contents;
   std::string load_command;
   std::string line_loaded;
   
   file_to_verify = "/proc/";
   file_to_verify += mMonitoringFolder;
   file_to_verify += "/net/dev";
   
   load_command = "cat ";
   load_command += file_to_verify;
   
   cleanInformation ();
   
   file_contents = Base::CommandManager::runCommand ( load_command );
   
   if ( file_contents == "ERROR" )
      return ( false );
   
   std::istringstream iss ( file_contents );
   
   std::getline ( iss , line_loaded );
   processOrderOfColumns ( line_loaded );
   
   std::getline ( iss , line_loaded );
   processOrderOfData ( line_loaded );
   
   std::getline ( iss , line_loaded );
   while ( !iss.eof () )
   {
      processLineOfData ( line_loaded );
      std::getline ( iss , line_loaded );
   }
   
   return ( true );
}

void Base::NetworkAgent::cleanInformation ( void )
{
   for ( unsigned int i = 0; i < mAvailableInterfaces.size (); i++ )
   {
      delete mInterfaceInformationMap[ mAvailableInterfaces[ i ] ];
      mInterfaceInformationMap[ mAvailableInterfaces[ i ] ] = 0;
   }
   
   mInterfaceInformationMap.clear ();
   mAvailableInterfaces.clear ();
   mFirstColumnContents.clear ();
   mSecondColumnContents.clear ();
}

void Base::NetworkAgent::processLineOfData ( std::string& input_line )
{
   /*
    * I'll have a line like this:
    * 
    * " eth0: 234703361  227184    0    7    0     0          0         0 18395469  178876    0    0    0     0       0          0"
    * 
    * The first value is a string, the name of the interface. The following values are the values for every column of data. All of them
    * are integers.
    */
   
   std::istringstream iss ( input_line );
   std::string interface_name;
   unsigned long int value;
   InterfaceInformation* new_information;
   
   iss >> interface_name;
   
   if ( !interface_name.empty () )
      interface_name.substr ( 0 , interface_name.size () - 2 ); // Remove the last character
    
   new_information = new (std::nothrow) InterfaceInformation ();
   
   if ( new_information == 0 ) // If I can't make a new component, stop
      return;
   
   new_information->InterfaceName = interface_name;
   
   mAvailableInterfaces.push_back ( interface_name );
   mInterfaceInformationMap[ interface_name ] = new_information;
      
   for ( unsigned int i = 0; i < mFirstColumnContents.size (); i++ )
   {
      iss >> value;
      storeValue ( mFirstColumnType , mFirstColumnContents[ i ] , value );
   }
   
   for ( unsigned int i = 0; i < mSecondColumnContents.size (); i++ )
   {
      iss >> value;
      storeValue ( mSecondColumnType , mSecondColumnContents[ i ] , value );
   }
   
   return;
}

void Base::NetworkAgent::storeValue ( const Base::NetworkAgent::ColumnContents& column_type , const std::string& column_data , const long unsigned int& value )
{
   // Get the pointer to the data
   std::string name = mAvailableInterfaces[ mAvailableInterfaces.size () - 1 ];
   InterfaceInformation* information = mInterfaceInformationMap[ name ];
   
   // Input or output?
   if ( column_type == Input )
      storeValue ( information->InputInfo , column_data , value );
   else
      storeValue ( information->OutputInfo , column_data , value );
   
   return;
}

void Base::NetworkAgent::storeValue ( NetworkStatistics& statistics , const std::string& column_data , const long unsigned int& value )
{   
   if ( column_data == "PACKETS" )
      statistics.Packets = value;
   else if ( column_data == "BYTES" )
      statistics.Bytes = value;
   else if ( column_data == "ERRS" )
      statistics.Errors = value;
   else if ( column_data == "DROP" )
      statistics.DroppedPackets = value;
   else if ( column_data == "FIFO" )
      statistics.FifoOverruns = value;
   else if ( column_data == "FRAME"  )
      statistics.FrameErrors = value;
   else if ( column_data == "CARRIER" )
      statistics.CarrierErrors = value;
   else if ( column_data == "COMPRESSED" )
      statistics.CompressedPackets = value;
   else if ( column_data == "MULTICAST" )
      statistics.MulticastPackets = value;
   else
      statistics.Collitions = value;
   
   return;
}

void Base::NetworkAgent::processOrderOfData ( std::string& input_line )
{
   /*
    * I'll process an input line like this:
    * 
    * " face |bytes    packets errs drop fifo frame compressed multicast|bytes    packets errs drop fifo colls carrier compressed"
    * 
    * I'll split the string using the pipes. That will give me three strings. Split the strings 2 and 3 using spaces.
    * Trim every element and turn them into uppercase strings and store them.
    */
   
   std::vector< std::string > pieces;
   
   pieces = splitString ( input_line , "|" );
   
   if ( pieces.size () != 3 ) // There must be 3 elements
      return;
   
   std::vector< std::string > column_elements;
   
   column_elements = splitString ( pieces[ 1 ] , " " );
   
   if ( column_elements.size () > 1 )
      for ( unsigned int i = 0; i < column_elements.size (); i++ )
         mFirstColumnContents.push_back ( toUpperCase ( trimString ( column_elements[ i ] ) ) );
      
   column_elements = splitString ( pieces[ 2 ] , " " );
   
   if ( column_elements.size () > 1 )
      for ( unsigned int i = 0; i < column_elements.size (); i++ )
         mSecondColumnContents.push_back ( toUpperCase ( trimString ( column_elements[ i ] ) ) );
         
   return;
}

void Base::NetworkAgent::processOrderOfColumns ( std::string& input_line )
{
   std::vector< std::string > pieces;
   pieces = splitString ( input_line , "|" );
   
   for ( unsigned int i = 0; i < pieces.size (); i++ )
      pieces[ i ] = toUpperCase ( trimString ( pieces[ i ] ) );
   
   if ( pieces.size () != 3 ) // There must be 3 sections. If not, I don't know how to process them
      return;
   
   mFirstColumnType = ( pieces[ 1 ] == "RECEIVE" ) 
                      ? ( mSecondColumnType = Output , Input )
                      : ( mSecondColumnType = Input , Output );
   
   return;
}

std::vector< std::string > Base::NetworkAgent::getAvailableInterfaces ( void )
{
   return ( mAvailableInterfaces );
}

Base::NetworkAgent::InterfaceInformation* Base::NetworkAgent::getInterfaceInformation ( std::string interface_name )
{
   bool found_interface = false;
   
   for ( unsigned int i = 0; i < mAvailableInterfaces.size () && !found_interface; i++ )
      found_interface = ( mAvailableInterfaces[ i ] == interface_name );
   
   if ( found_interface == true )
      return ( mInterfaceInformationMap[ interface_name ] );
   else
      return ( 0 );
}
