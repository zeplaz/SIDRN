
//class img_obkj.h

#pragma once

#include <utility>
#include <vector>

//3rdparty sfml lib for displays
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

//

  class img_obkj
  {



 private :
   int be_id;
   static int be_NextValidID;

   void set_id(int val);
   img_objk_prop.obj_id= label;
  public :



  std::vector<int[2]> obj_pixel_pars

  //std::vector<std::pair<int,int[2]>> object_pixel_;

      img_obkj(int label)
        {set_id(label);}

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
      double perimeter;



      uint8_t[4] lagest_4_rowsvalue;
      uint8_t[4] smallest_4_rowsvalue;
      uint8_t[4]  lagest_4_columvalue;
      uint8_t[4] smallest_4_columvalue;
      char type;
    }img_objk_prop;
