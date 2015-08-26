# ifndef NETWORKAGENT_HH
# define NETWORKAGENT_HH

# include <iostream>
# include <string>
# include <vector>
# include <map>

# include "Agent.hh"

namespace Base
{
   class NetworkAgent : public Base::Agent
   {
      public:
         struct t_NetworkStatistics
         {
            t_NetworkStatistics ( void )
            {
               reset ();
            }
            
            void reset ( void )
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
            
            unsigned long int Bytes;
            unsigned long int Packets;
            unsigned long int Errors;
            unsigned long int DroppedPackets;
            unsigned long int FifoOverruns;
            unsigned long int FrameErrors;
            unsigned long int CompressedPackets;
            unsigned long int MulticastPackets;
            unsigned long int CarrierErrors;
            unsigned long int Collitions;
         };
         typedef struct t_NetworkStatistics NetworkStatistics;
         
         struct t_InterfaceInformation
         {
            std::string InterfaceName;
            NetworkStatistics InputInfo;
            NetworkStatistics OutputInfo;
            // TODO: Sockets
         };
         typedef struct t_InterfaceInformation InterfaceInformation;
         
         NetworkAgent ( std::string monitoring_folder );
         ~NetworkAgent ( void );
         
         bool update ( void );
         
         std::vector< std::string > getAvailableInterfaces ( void );
         
         InterfaceInformation* getInterfaceInformation ( std::string interface_name );
         
      private:
         enum ColumnContents
         {
            Input = 0 ,
            Output = 1
         };
         
         void cleanInformation ( void );
         void processOrderOfColumns ( std::string& input_line );
         void processOrderOfData ( std::string& input_line );
         void processLineOfData ( std::string& input_line );
         void storeValue ( const Base::NetworkAgent::ColumnContents& column_type , const std::string& column_data , const unsigned long int& value );
         void storeValue ( NetworkStatistics& statistics , const std::string& column_data , const unsigned long int& value );
                  
      private:         
         std::map< std::string , InterfaceInformation* > mInterfaceInformationMap;
         std::vector< std::string > mAvailableInterfaces;
         std::vector< std::string > mFirstColumnContents;
         std::vector< std::string > mSecondColumnContents;
         ColumnContents mFirstColumnType;
         ColumnContents mSecondColumnType;
   };
}

# endif
