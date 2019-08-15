
#ifndef MEAN_SHIFTS_H
#define MEAN_SHIFTS_H


//stdlibz
#include <utility>
#include <tuple>
#include <iostream>
#include <vector>
#include <math.h>
#include <cstring>
#include <stack>


#include "imagkjz_RGB.h"
#include "pixel_feture_xy_RGB.h"


//class imagkjz_RGB;

class Mean_shifts
{
  public :
  double spc_bandwith;
  double h_bandwith;
  imagkjz_RGB* prt_meanshift_img;

  public :
  Mean_shifts(double, double);
  void meanshift_seg_RGB(imagkjz_RGB&,imagkjz_RGB&);

};
#endif
