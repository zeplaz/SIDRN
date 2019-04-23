



      //vrt_image.h
      #ifndef VRT_IMAGE_H
      #define VRT_IMAGE_H


#include <iostream>

      class vrt_image{



private :
int dimention;

if(typed==colour_RGB)
{
  dimention = 3;
 }
      public :


      vrt_image() {}
    virtual  ~vrt_image(){ };

    virtual  void Image_Procees_inlizar(std::ifstream& in_img) =0;

    virtual  void write_image(std::ofstream& out_img)  =0;

    virtual void update()= 0;

      };



      #endif
