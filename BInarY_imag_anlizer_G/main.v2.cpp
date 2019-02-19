//main_0v2


#include <iostream>
#include <math.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <time.h>

#include "image_Byte8.h"
#include "image_procczor_mrk_1001.h"

int main(int argc, char* argv[])

{

std::ifstream in_img;
//std::ofstream outf_stream;
std::fstream log_file_stream;


printf(" IMage_scan Main Execution \n" );

  image_Byte8* new_img1 = new image_Byte8();

    image_Byte8* thesholdimg;

  new_img1->Image_Procees_inlizar(in_img);

//  new_image.Image_Procees_inlizar(in_img);


image_procczor_mrk_1001 image_procs_ins;

printf(" created imagprocessor \n" );


          thesholdimg    =  image_procs_ins.thresholdImg(new_img1);

delete new_img1;

printf("endprogam\n");




return 0;

}
