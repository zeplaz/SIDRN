
//Objkfactory.h

#include "img_obkj.h"
#include "img_obkj.cpp"

class Objkfactory

{
  private :
      img_obkj *Img_obkj;

  public :

    img_obkj* create_img_obk(int label)
      {
       return new img_obkj(label);
      }

    int destry_img_obk(img_obkj* iob);

    int Objkfactory::destry_img_obk(img_obkj* iob)
     {
         if (iob)
           {
           delete iob;
           iob = nullptr;
           return 0;
           }
       }

      ~Objkfactory(){}
       Objkfactory(){}

};
