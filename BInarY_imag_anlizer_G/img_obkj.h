
//class img_obkj.h

#pragma once

#include <utility>
#include <vector>

  class img_obkj
  {

  public :
  std::vector<int[2]> obj_pixel_pars

  //std::vector<std::pair<int,int[2]>> object_pixel_;
      img_obkj(int label){ img_objk_prop.obj_id= label;}
      ~img_obkj(){}

    //  std::list<int[2]>
    //  std::list<int[2]>::iterator it;

    struct obj_propertiez
    {
      int obj_id;
      int Arra_size;
      std::vector<int> centrod;
      long circularity;
      uint8_t bbox2[2][3];
      double second_momnent;



      uint8_t[4] lagest_4_rowsvalue;
      uint8_t[4] smallest_4_rowsvalue;
      uint8_t[4]  lagest_4_columvalue;
      uint8_t[4] smallest_4_columvalue;
      char type;
    }img_objk_prop;
