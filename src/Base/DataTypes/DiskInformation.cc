# include "DiskInformation.hh"

Base::DataTypes::t_DiskInformation::t_DiskInformation ( void )
{
   reset ();
}

void Base::DataTypes::t_DiskInformation::reset ( void )
{
   BytesRead = 0;
   BytesWriten = 0;
   WriteCalls = 0;
   ReadCalls = 0;
   RealBytesRead = 0;
   RealBytesWriten = 0;
   CancelledBytes = 0;
   
   return;
}

std::istream& operator>> ( std::istream& input , struct Base::DataTypes::t_DiskInformation& data )
{
   std::string line_loaded;
   
   std::getline ( input , line_loaded );
   
   while ( !input.eof () )
   {
      std::string keyname;
      std::istringstream iss ( line_loaded );
      
      iss >> keyname;
      
      if ( keyname == "rchar:" )
         iss >> data.BytesRead;
      else if ( keyname == "wchar:" )
         iss >> data.BytesWriten;
      else if ( keyname == "syscr:" )
         iss >> data.ReadCalls;
      else if ( keyname == "syscw:" )
         iss >> data.WriteCalls;
      else if ( keyname == "read_bytes:" )
         iss >> data.RealBytesRead;
      else if ( keyname == "write_bytes:" )
         iss >> data.RealBytesWriten;
      else if ( keyname == "cancelled_write_bytes:" )
         iss >> data.CancelledBytes;
      
      std::getline ( input , line_loaded );
   }
   
   return ( input );
}