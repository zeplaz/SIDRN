
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
            vector<int>pixelz[][];

    ~image_Byte8(){  delete[] byte_Array_pix;}

     virtual void readImage(ifstream &inFile) = 0;
	   virtual void writeImage(ofstream &outFile) = 0;

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


}
