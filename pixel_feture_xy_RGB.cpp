//pixel_feture_xy_RGB.cpp

#include "pixel_feture_xy_RGB.h"



  pixel_feture_xy_RGB::pixel_feture_xy_RGB()
    {
      pix_xy_fet[0]=-1;
      pix_xy_fet[1]=-1;
    }

// tuple feture pointer genrtz
  std::touple<double,double,double>* pixel_feture_xy_RGB::getptr_channl_touple()
    {
      return *rgb_chanell_tuple;
    }

  void pixel_feture_xy_RGB::pcopyer(pixel_feture_xy_RGB pointfet)
    {
      rgb_chanell_tuple = pointfet.rgb_chanell_tuple;
      pix_xy_fet[0]= pointfet. pix_xy_fet[0];
      pix_xy_fet[1]= pointfet.pix_xy_fet[1];
    }
// maualty set point data
  void pixel_feture_xy_RGB::pmaual_feture_set(double x, double y,
                        double r,double g,double b)
    {
      rgb_chanell_tuple = std::make_tuple(r,g,b);
      pix_xy_fet[0]= x;
      pix_xy_fet[1]= y;
    }

//load image raw data to feture space
    void pixel_feture_xy_RGB::point_setter(imagkjz_RGB& load_pix, int x,int y)
      {
          double red,green,blue;
          int Pix_id = (x*y)+y;
          image_intcity_struc*  prt_instysturc =
                                newimage_intcity_struc(load_pix->locat_pixel_fet_data(Pix_id));

          pix_xy_fet[0] = x;
          pix_xy_fet[1] = y;

          red   = prt_instysturc->[0];
          green = prt_instysturc->[1];
          blue  = prt_instysturc->[2];

           rgb_chanell_tuple = std::make_tuple(red,green,blue);
      }

//summz
  void pixel_feture_xy_RGB::fetureaccumalor(pixel_feture_xy_RGB point_in)
  {
     pix_xy_fet[0] =+ point_in.pix_xy_fet[0];
     pix_xy_fet[1] =+ point_in.pix_xy_fet[1];
     std::get<0>(rgb_chanell_tuple) =+ std::get<0>(point_in.rgb_chanell_tuple);
     std::get<1>(rgb_chanell_tuple) =+ std::get<1>(point_in.rgb_chanell_tuple);
     std::get<2>(rgb_chanell_tuple) =+ std::get<2>(point_in.rgb_chanell_tuple);
  }

  //ascalerr for whole intenizy
  void pixel_feture_xy_RGB::pointscaler(double scale)
    {
      pix_xy_fet[0]*=scale;
      pix_xy_fet[1]*=scale;
      std::get<0>(rgb_chanell_tuple)*=scale;
      std::get<1>(rgb_chanell_tuple)*=scale;
      std::get<2>(rgb_chanell_tuple)*=scale;
    }

  //feturespacecalulations
  double pixel_feture_xy_RGB::point_RGB_distance(pixel_feture_xy_RGB point_in)
    {
        return sqrt(
         (std::get<0>(rgb_chanell_tuple)-std::get<0>(point_in.rgb_chanell_tuple))*
         (std::get<0>(rgb_chanell_tuple)-std::get<0>(point_in.rgb_chanell_tuple))+

         (std::get<1>(rgb_chanell_tuple)-std::get<1>(point_in.rgb_chanell_tuple))*
         (std::get<1>(rgb_chanell_tuple)-std::get<1>(point_in.rgb_chanell_tuple))+

         (std::get<2>(rgb_chanell_tuple)-std::get<2>(point_in.rgb_chanell_tuple))*
         (std::get<2>(rgb_chanell_tuple)-std::get<2>(point_in.rgb_chanell_tuple))
         );
    }

  double pixel_feture_xy_RGB::point_spatial_distance(pixel_feture_xy_RGB point_in)
    {
      return sqrt(
        (pix_xy_fet[0]-point_in.pix_xy_fet[0])*(pix_xy_fet[0]-point_in.pix_xy_fet[0])+
        (pix_xy_fet[1]-point_in.pix_xy_fet[1])*(pix_xy_fet[1]-point_in.pix_xy_fet[1)
        );
    }
