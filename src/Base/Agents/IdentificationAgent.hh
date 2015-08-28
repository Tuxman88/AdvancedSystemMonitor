# ifndef IDENTIFICATIONAGENT_HH
# define IDENTIFICATIONAGENT_HH

# include <iostream>
# include <string>

# include "Agent.hh"

namespace Base
{
   class IdentificationAgent : public Base::Agent
   {
      public:
         struct t_IdentificationInformation
         {
            t_IdentificationInformation ( void )
            {
               reset ();
            }
            
            void reset ( void )
            {
               CommandLine = "";
               LoginUID = 0;
               PID = 0;
               Command = "";
               State = ' ';
               ParentPID = 0;
               ProcessGroupID = 0;
               SessionID = 0;
               ControllingTerminal = 0;
               ForegroundProcessGroupID = 0;
               
               return;
            }
            
            std::string CommandLine;
            unsigned long int LoginUID;
            unsigned long int PID;
            std::string Command;
            char State;
            unsigned long int ParentPID;
            unsigned long int ProcessGroupID;
            unsigned long int SessionID;
            unsigned long int ControllingTerminal;
            unsigned long int ForegroundProcessGroupID;
         };
         typedef struct t_IdentificationInformation IdentificationInformation;
         
         IdentificationAgent ( std::string monitoring_folder );
         ~IdentificationAgent ( void );
         
         bool update ( void );
         
         IdentificationInformation* getIdentificationInformation ( void );
         
      private:
         bool loadCommandLine ( void );
         bool loadLoginUID ( void );
         bool loadStat ( void );
         
      private:
         IdentificationInformation* mIdentificationInformation;
   };
}

# endif
