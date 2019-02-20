
//image_Byte8.h

#ifndef IMAGE_BYTE8_H
#define IMAGE_BYTE8_H



#include <iostream>
#include <math.h>
#include <fstream>
#include <vector>
#include <sstream>


#include "vrt_image.h"
//#include <time.h>
//  #include <bitset>


class image_Byte8 : public vrt_image
{

    public :

   std::vector< std::vector<int>> b_imgArray;

   std::stringstream string_imgstrm;
   std::string linez;
   std::string user_input_img_name;

      image_Byte8() {}
      ~image_Byte8(){ }

    //std::vector<int>pixelz[][];

  //    void read_image_to_matrex(std::ifstream &in_img);

	 //   void writeImage(std::ofstream &outFile);

     //void readHeader(std::ifstream &inimg);

  //   bool iz_Binary_T_ASCI_F(std::ifstream &in_img);

    virtual void Image_Procees_inlizar(std::ifstream& in_img);

    virtual void write_image(std::ofstream& out_img);

      int get_h_rs()
      {return img_height_rows;}

      int get_W_cs()
      {return img_width_colums;}

     	int get_MaxPixVal()
      {return maxPixelValue;}


      int img_height_rows;
      int img_width_colums;

      int maxPixelValue;
      int  image_area_pix;

    protected :

    	uint8_t readbytechar = ' ';


//
    //  void edgeDection();
     	//void scaleImage();

};

#endif
