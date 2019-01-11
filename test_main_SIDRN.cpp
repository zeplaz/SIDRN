

//testmainforSIDRN


//libz from std

#include <cstdio>
#include <fstream>
#include <ctime>
//libs thirdparty


//libs our project

//macos and debug stuff
#define DEBUGZ





int main(int argc, char* argv[])

{
  //startup create log stream
std::fstream log_file_stream;
time_t now = time(0);
tm* localtm = localtime(&now);

printf(" SUDRN_0.00.01 Main Execution \n" );
log_file_stream.open("log_file.txt", std::fstream::in | std::fstream::out | std::fstream::app);
log_file_stream << "SIDRN begain exuection: " << asctime(localtm) << "\n";

//inlization proccedures


//connections









//shutdown//final notes



printf(" SUDRN_ Shutdown_return Normal \n" );
log_file_stream << "SIDRN ended exuection: "  << asctime(localtm) << "\n";

log_file_stream.close();

return 0;

}
