


#include <istream>
#include <fstream>
#include <vector>
#include <string>
#include <tuple>
#include <iostream>


#include "imagkjz_RGB.h"
#include "Mean_shifts.h"
#include "pixel_feture_xy_RGB.h"

int main(int argc, char* argv[])

  {//startup create log stream


        std::string file_img_name;


          std::cout << "||WELCOME::TO MEANSHIFT_PROCESSORZ||" << "\n" << "\n"
                    << |\->Please enter fileName to be Loaded: << "\n"

                    std::cin >> file_img_name;
                    




          istream


         image_prt_array[]
          imagkjz_RGB* img_1 = new(imagkjz_RGB);

          double bandwithspace=6;
          double bandithcolour =2;



          Mean_shifts meanshif_ojk(bandwithspace,bandithcolour);



          imagkjz_RGB* meanshiftedprt = new imagkjz_RGB(meanshif_ojk.meanshift_seg_RGB(img_1));








          //cleanup
          delete img_1;
          delete meanshiftedprt;
    return 0;
  }
