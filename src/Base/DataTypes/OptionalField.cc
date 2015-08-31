# include "OptionalField.hh"

Base::DataType::t_OptionalField::t_OptionalField ( void )
{
   reset ();
}

void Base::DataType::t_OptionalField::reset ( void )
{
   Value = 0;
   Tag   = "";
   
   return;
}
