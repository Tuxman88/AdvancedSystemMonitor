# include <iostream>
# include <string>
# include <cstdlib>
# include <cstdio>

using std::string;
using std::endl;
using std::cout;

std::string exec(string cmd) {
    FILE* pipe = popen(cmd.c_str (), "r");
    if (!pipe) return "ERROR";
    char buffer[128];
    std::string result = "";
    while(!feof(pipe)) {
        if(fgets(buffer, 128, pipe) != NULL)
                result += buffer;
    }
    pclose(pipe);
    return result;
}

int main ()
{
   string tmp;
   
   cout << "LS: " << exec ( "ls /proc/" ) << endl;

   return 0;
}