

//class img_obkj.h

#pragma once

class img_obkj
{



public :

    img_obkj(int label){ obj_id =img_objk_prop.label;}


    ~img_obkj(){}

    struct obj_propertiez{
      int obj_id;
      int Arra_size;
      foat centrod;
      long circularity;
      uint8_t bbox2[2][3];
      second_momnent;
        uint8_t[4] lagest_4_rowsvalue;
      uint8_t[4] smallest_4_rowsvalue;
      uint8_t[4]  lagest_4_columvalue;
      uint8_t[4] smallest_4_columvalue;
      char type;};
      int label;

} img_objk_prop;
