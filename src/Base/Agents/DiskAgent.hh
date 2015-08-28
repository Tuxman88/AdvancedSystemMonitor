# ifndef DISKAGENT_HH_
# define DISKAGENT_HH_

# include <iostream>
# include <string>

# include "Agent.hh"

namespace Base
{
   class DiskAgent : public Base::Agent
   {
      public:
         struct t_DiskInformation
         {
            t_DiskInformation ()
            {
               reset ();
            }
            
            void reset ( void )
            {
               BytesRead = 0;
               BytesWriten = 0;
               WriteCalls = 0;
               ReadCalls = 0;
               RealBytesRead = 0;
               RealBytesWriten = 0;
               CancelledBytes = 0;
               
               return;
            }
            
            unsigned long int BytesRead;
            unsigned long int BytesWriten;
            unsigned long int WriteCalls;
            unsigned long int ReadCalls;
            unsigned long int RealBytesRead;
            unsigned long int RealBytesWriten;
            unsigned long int CancelledBytes;
         };
         typedef struct t_DiskInformation DiskInformation;
         
         DiskAgent ( std::string monitoring_folder );
         ~DiskAgent ( void );
         
         bool update ( void );
         
         DiskInformation* getDiskInformation ( void );
         
      private:
         void storeValue ( std::string line_loaded );
         
      private:
         DiskInformation* mDiskInformation;
   };
}

# endif
