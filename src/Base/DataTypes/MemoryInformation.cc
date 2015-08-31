# include "MemoryInformation.hh"

Base::DataTypes::t_MemoryInformation::t_MemoryInformation ( void )
{
   reset ();
}  

void Base::DataTypes::t_MemoryInformation::reset(void)
{
   TotalProgramSize = 0;
   ResidentSetSize  = 0;
   SharedPages      = 0;
   Text             = 0;
   Library          = 0;
   DataAndStack     = 0;
   DirtyPages       = 0;
   
   return;
}

std::istream& operator>> ( std::istream& input , struct Base::DataTypes::t_MemoryInformation& data )
{
   input >> data.TotalProgramSize;
   input >> data.ResidentSetSize;
   input >> data.SharedPages;
   input >> data.Text;
   input >> data.Library;
   input >> data.DataAndStack;
   input >> data.DirtyPages;
   
   return ( input );
}