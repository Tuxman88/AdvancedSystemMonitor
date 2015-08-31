# include "FileInformation.hh"

Base::DataType::t_FileInformation::t_FileInformation ( void )
{
   MountInfo = new MountInformation ();
   
   reset ();
}

Base::DataType::t_FileInformation::~t_FileInformation ( void )
{
   delete MountInfo;
}

void Base::DataType::t_FileInformation::reset(void)
{
   FileDescriptorID = 0;
   FilePath = "";
   FileOffset = 0;
   FileFlags = "";
   MountInfo->reset ();
   
   return;
}
