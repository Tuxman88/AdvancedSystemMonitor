# ifndef IDENTIFICATIONINFORMATION_HH_
# define IDENTIFICATIONINFORMATION_HH_

# include <string>

namespace Base
{
   namespace DataTypes
   {
      struct t_IdentificationInformation
      {
         t_IdentificationInformation ( void );
         
         void reset ( void );
         
         std::string       CommandLine;
         unsigned long int LoginUID;
         unsigned long int PID;
         std::string       Command;
         char              State;
         unsigned long int ParentPID;
         unsigned long int ProcessGroupID;
         unsigned long int SessionID;
         unsigned long int ControllingTerminal;
         unsigned long int ForegroundProcessGroupID;
      };
      typedef struct t_IdentificationInformation IdentificationInformation;
   }
}

# endif
