# include "MountInformation.hh"

Base::DataType::t_MountInformation::t_MountInformation ( void )
{
   reset ();
}

void Base::DataType::t_MountInformation::reset ( void )
{
   ID = 0;
   Parent = 0;
   MajorMinor = "";
   RootPath = "";
   MountPoint = "";
   MountOptions.clear ();
   OptionalFields.clear ();
   FileSystemType.reset ();
   Source = "";
   SuperOptions.clear ();
   
   return;
}
