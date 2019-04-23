

// pixel_feture_xy_RGB.h
#ifndef PIX_FET_XY_RGB_H
#define PIX_FET_XY_RGB_H

//std libz
#include <utility>
#include <touple>

//localincluz
#include "imagkjz_RGB.h"

  class pixel_feture_xy_RGB
  {
    public:
    std::touple<double,double,double> rgb_chanell_tuple;
    double pix_xy_fet[2];

    public :

    pixel_feture_xy_RGB();

    std::touple<double,double,double>* getptr_channl_touple();

    void pcopyer(pixel_feture_xy_RGB);
    void pmaual_feture_set(double,double,double,double,double);
    void point_setter(imagkjz_RGB&,int,int);
    void fetureaccumalor(pixel_feture_xy_RGB);
    void pointscaler(double);

    double point_RGB_distance(pixel_feture_xy_RGB);
    double point_spatial_distance(pixel_feture_xy_RGB);
};

#endif
