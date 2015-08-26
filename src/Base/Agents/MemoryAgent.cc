# include "MemoryAgent.hh"

Base::MemoryAgent::MemoryAgent ( std::string monitoring_folder )
   : Agent ( monitoring_folder )
{
}

Base::MemoryAgent::~MemoryAgent ( void )
{
}

bool Base::MemoryAgent::update ( void )
{
   /*
    * The memory can be monitored using the file statm, which has a format like this:
    * 
    * "172494 43393 11339 31 0 133622 0"
    * 
    */
   
   return ( true );
}
