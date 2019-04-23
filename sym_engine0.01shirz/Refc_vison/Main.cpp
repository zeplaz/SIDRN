


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

          istream input_img_file (file_img_name, std::ios::binary);

          std::vector<std::uint_8> imag_raw_1;



          std::vector<imagkjz_RGB*> imag_ptr_stoge;

          imagkjz_RGB* img_1 = new imagkjz_RGB();
          imagkjz_RGB* mean_imgshift = new imagkjz_RGB();


          double bandwithspace=6;
          double bandithcolour =2;

          img_1.load_image_RGB(input_img_file,&imag_raw_1);
          img_1.linilzatfeture_space();

          Mean_shifts meanshif_ojk(bandwithspace,bandithcolour);
          *mean_imgshift =  *img_1;


        //  imagkjz_RGB* meanshiftedprt = new imagkjz_RGB(meanshif_ojk.meanshift_seg_RGB(img_1));





          //cleanup
          delete img_1;
          delete meanshiftedprt;
    return 0;
  }
