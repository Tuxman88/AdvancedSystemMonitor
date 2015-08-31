# include "IdentificationInformation.hh"

Base::DataTypes::t_IdentificationInformation::t_IdentificationInformation ( void )
{
   reset ();
}

void Base::DataTypes::t_IdentificationInformation::reset ( void )
{
   CommandLine              = "";
   LoginUID                 = 0;
   PID                      = 0;
   Command                  = "";
   State                    = ' ';
   ParentPID                = 0;
   ProcessGroupID           = 0;
   SessionID                = 0;
   ControllingTerminal      = 0;
   ForegroundProcessGroupID = 0;
   
   return;
}
