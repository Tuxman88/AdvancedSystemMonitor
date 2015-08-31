# include "FileSystemAgent.hh"

Base::FileSystemAgent::FileSystemAgent ( std::string monitoring_folder )
   : Agent ( monitoring_folder )
{
   mFilesInformation = new std::vector< Base::DataType::FileInformation > ();
}

Base::FileSystemAgent::~FileSystemAgent ( void )
{
   mFilesInformation->clear ();
   delete mFilesInformation;
}

std::vector< Base::DataType::FileInformation >* Base::FileSystemAgent::getFilesInformation ( void )
{
   return ( mFilesInformation );
}

bool Base::FileSystemAgent::update ( void )
{
   return ( true );
}
