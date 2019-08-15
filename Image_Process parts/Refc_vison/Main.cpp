


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
                    << "|->Please enter fileName to be Loaded:" << "\n";

                    //std::cin >> file_img_name;
                    //
                    file_img_name ="cmd_coven_text_01.ppm";
        //  std::fstream input_img_file;
        //  input_img_file.open(file_img_name,std::fstream::in | std::ios::binary);



          //std::vector<std::uint_8> imag_raw_1;
          //std::vector<imagkjz_RGB*> imag_ptr_stoge;

          imagkjz_RGB* img_1 = new imagkjz_RGB();
          imagkjz_RGB* mean_imgshift = new imagkjz_RGB();

          double bandwithspace = 6;
          double bandithcolour = 2;


          // Load image and setup inal_intezity feture space
          img_1->load_image_RGB(file_img_name);
          img_1->inilzatfeture_space();


          // begin meanshift requerments
         //*mean_imgshift =  *img_1;

          Mean_shifts meanshif_ojk(bandwithspace,bandithcolour);
          meanshif_ojk.meanshift_seg_RGB(*img_1,*mean_imgshift);

          //imagkjz_RGB* meanshiftedprt = new imagkjz_RGB(meanshif_ojk.meanshift_seg_RGB(img_1));


          // output
      //  mean_imgshift->write_image(outfile_strm_img);
        mean_imgshift->write_image();

        //outfile_strm_img.close();

          //cleanup
          delete img_1;
        //  delete mean_imgshift;

    return 0;
  }
