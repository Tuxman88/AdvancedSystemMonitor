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
   
   
   return ( true );
}

Base::ExtendedAgent::ExtendedInformation* Base::ExtendedAgent::getIdentificationInformation ( void )
{
   return ( mExtendedInformation );
}
