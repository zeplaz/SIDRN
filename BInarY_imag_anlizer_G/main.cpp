
//main.cpp

/*
Magic number	89 50 4e 47 0d 0a 1a 0a
*/



// included std libraryz
#include <iostream>
#include <math.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <time.h>

//3rdparty


//offical_ISAMYZ headers

//

//local processordeclrations
Image_Procees_inlizar();



int main(int argc, char* argv[])

{
  std::ifstream in_img;
  std::ofstream outf_stream;

        Data_StreamLOader->Image_Procees_inlizar(in_img,outf_stream);
        Data_StreamLOader->iz_Binary_T_ASCI_F(in_img);

        start_clock = std::clock();
        end_clock;


std::fstream log_file_stream;
time_t now = time(0);
tm* localtm = localtime(&now);

printf(" IMage_scan Main Execution \n" );

in_img.close();
outf_stream.close();

return 0;
}
