# ifndef MEMORYAGENT_HH
# define MEMORYAGENT_HH

# include <iostream>
# include <string>
# include <vector>

# include "Agent.hh"

namespace Base
{
   class MemoryAgent : public Agent
   {
      public:
         struct t_MemoryInformation
         {
            t_MemoryInformation ( void )
            {
               reset ();
            }
            
            void reset ( void )
            {
               TotalProgramSize = 0;
               ResidentSetSize = 0;
               SharedPages = 0;
               Text = 0;
               Library = 0;
               DataAndStack = 0;
               DirtyPages = 0;
               
               return;
            }
            
            unsigned long int TotalProgramSize;
            unsigned long int ResidentSetSize;
            unsigned long int SharedPages;
            unsigned long int Text;
            unsigned long int Library;
            unsigned long int DataAndStack;
            unsigned long int DirtyPages;
         };
         typedef struct t_MemoryInformation MemoryInformation;
         
         MemoryAgent ( std::string monitoring_folder );
         ~MemoryAgent ( void );
         
         bool update ( void );
         
   private:
   };
}

# endif
