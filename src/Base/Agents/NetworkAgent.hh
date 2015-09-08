# ifndef NETWORKAGENT_HH
# define NETWORKAGENT_HH

# include <iostream>
# include <string>
# include <vector>
# include <map>

# include "Agent.hh"
# include "../DataTypes/InterfaceInformation.hh"

namespace Base
{
   class NetworkAgent : public Base::Agent
   {
      public:         
         explicit NetworkAgent ( std::string monitoring_folder );
         virtual ~NetworkAgent ( void );
         
         bool update ( void );
         
         std::vector< std::string >             getAvailableInterfaces  ( void );
         Base::DataTypes::InterfaceInformation* getInterfaceInformation ( std::string interface_name );
         
      private:
         enum ColumnContents
         {
            Input = 0 ,
            Output = 1
         };
         
         void cleanInformation      ( void );
         void processOrderOfColumns ( std::string& input_line );
         void processOrderOfData    ( std::string& input_line );
         void processLineOfData     ( std::string& input_line );
         void storeValue            ( const Base::NetworkAgent::ColumnContents& column_type , const std::string& column_data , const unsigned long int& value );
         void storeValue            ( Base::DataTypes::NetworkStatistics& statistics , const std::string& column_data , const unsigned long int& value );
                  
      private:         
         std::map< std::string , Base::DataTypes::InterfaceInformation* > mInterfaceInformationMap;
         std::vector< std::string >                                       mAvailableInterfaces;
         std::vector< std::string >                                       mFirstColumnContents;
         std::vector< std::string >                                       mSecondColumnContents;
         ColumnContents                                                   mFirstColumnType;
         ColumnContents                                                   mSecondColumnType;
   };
}

# endif
