

//testmainforSIDRN


//libz from std

#include <cstdio>
#include <fstream>
#include <iostream>
#include <ctime>
#include <limits>
#include <string>
  //libs thirdparty


  //libs our project

  //macos and debug stuff
  #define DEBUGZ

  //gloabal-staticz


  //gobal varbz

  bool quit = false;


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


  std::string commissaire_c;
  std::string commissaire_pass;


      printf(" Enter your Orgburo commissaire Code \n");
      std::getline(std::cin, commissaire_c);

      printf(" Enter your Orgburo commissaire pass \n");
      std::getline(std::cin, commissaire_pass);

      log_file_stream << commissaire_c << " hasLogedON at: " << asctime(localtm) << "\n";
      printf(" To Quit enter q and press enter:\n");



//connectionz

//mainloop

      while(!quit)
    { printf("must input a char and enter to step loop:\n");
        //local varz
        char userinput;


    //grab a char from concelz
        std::cin >> userinput;

          if (userinput == 'q')
            {
              quit = true;
            }


  //wipes the stream if not vaild
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    }






      //shutdown//final notes

    printf(" SUDRN_ Shutdown_return Normal \n" );
    log_file_stream << "SIDRN ended exuection: "  << asctime(localtm) << "\n";

    log_file_stream.close();

return 0;
}
