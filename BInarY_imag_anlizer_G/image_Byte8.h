
//image_Byte8.h

#ifndef IMAGE_BYTE8_H
#define IMAGE_BYTE8_H



#include <iostream>
#include <math.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <time.h>
  #include <bitset>


class image_Byte8
{

    public :

      image_Byte8() :
            img_height(0),
      	  	img_width(0),
      	  	img_maxPixelValue(0),
          	imageSize(0)
        	minpix(0),
      		maxpix(0),
	        {}

      ~image_Byte8(){  delete[] byte_Array_pix;}

    vector<int>pixelz[][];

      void read_image_to_matrex(ifstream &in_img);

	    void writeImage(ofstream &outFile);

     void readHeader(ifstream &inimg);

      uint16_t get_h_rs()
      {return img_height_rows;}

      uint16_t get_W_cs()
      {return img_width_colums;}

     	int get_MaxPixVal()
      {return maxPixelValue;}

    protected :

      uint16_t img_height_rows;
      uint16_t img_width_colums;

      uint8_t maxPixelValue;
      uint8_t minpix;
      uint8_t maxpix;

      uint16_t  image_area_pix;

//
    //  void edgeDection();
     	//void scaleImage();

};
