
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
#include "Data_StreamLOader.h"
#include "image_Byte8.h"
#include "vrt_mask.h"
#include "image_procczor_mrk_1001.h"
/////////////////////////////////////////////////////////////


//local processordeclrations
//Image_Procees_inlizar();

report();
Process_cycle(image_Byte8* org_img ,image_Byte8* thsh_img);


//MainProgramthread

  int main(int argc, char* argv[])

  {
      //fileStreamz and other ilgizationz
      std::ifstream in_img;
      std::ofstream outf_stream;

            Data_StreamLOader->Image_Procees_inlizar(in_img,outf_stream);
            Data_StreamLOader->iz_Binary_T_ASCI_F(in_img);

            start_clock = std::clock();
            end_clock;


     std::fstream log_file_stream;
     //time_t now = time(0);
    // tm* localtm = localtime(&now);



     //processor inlzation and running objz creation

     image_procczor_mrk_1001 improz1;

// begin main img process squenxez.

    printf(" IMage_scan Main Execution \n" );

        image_byte8* new_img1 = new image_Byte8();

        new_img1->readImage(in_img);

        printf("Image Read Compleate\n");

        image_byte8* threshold_image = new image_Byte8();

        threshold_image = improz1.thresholdImg(new_img1);

        image_byte8* proccedz_image = new image_Byte8();

        proccedz_image = Process_cycle(threshold_image,new_img1);



        improz1.(proccedz_image);
        improz1.(proccedz_image);



      in_img.close();
      outf_stream.close();

      report();


      delete [] threshold_image;
      delete [] new_img1;

      return 0;

}

  inline int report()
      { int oi=0;


    printf("-------------------------------------\n");
    printf("-----------IMAGE REPORT--------------\n");
    printf("----ProceszorBINARYIMAG_ANLIZR_G-----\n");
    printf("-------------------------------------\n");
    printf("--Object COUNT::- %s ----------------\n",image_procczor_mrk_1001.get());

    for ( oi; oi< object_count; oi++)
    {
      cout << "Object_number:" << oi << "Centriod:" << obj.Centriod << ", circularity:" << obj.circularity
           <<", BBox:" << obj.box << ", Area:" << obj.area << ", Second Moment:" obj.secondmont;

      printf(" ObjectNum: %s %s -------------------------------\n",image_procczor_mrk_1001.get());

    }


    printf("--TYPEII---- %s -----------------------------\n",image_procczor_mrk_1001.get());
    printf("--TYPEIII-- %s ----------------------------\n",image_procczor_mrk_1001.get());
    printf("-------------------------------------\n");
    printf("-------------------------------------\n");
    printf("-------------------------------------\n");

}



inline image_byte8* Process_cycle(image_Byte8* org_img ,image_Byte8* thsh_img)
{



   open_morph(thsh_img);
   close_morph(thsh_img);

  image_procczor_mrk_1001.conected_comp_labler(thsh_img);

    apply_erode(thsh_img);
    apply_dilate(thsh_img);

  image_procczor_mrk_1001.conected_comp_labler(thsh_img);


  //comepare comected take <

  return ()
}
