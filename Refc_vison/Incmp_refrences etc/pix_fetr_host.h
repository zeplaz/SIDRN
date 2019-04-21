
#ifndef PIX_FET_TYPE_H
#define PIX_FET_TYPE_H
#define intvec_f = 0;
#define dubvec_f = 1;
#include <list>
#include ""

template< class T >
class pix_Feture_type{

protected:
int extable_feturelistz;

  public :
  pix_Feture_type();
  ~pix_Feture_type();

  bool add_fetur_to_type(T fetur, int type )
  {
    if(type =)
  }
  bool Create_feture_type(int f_type)
  {
    switch (f_type)
    {
      case intvec_f :
      {
        std::vector<int>* STD_int_ferturez = new std::vector<int>*();
        break;
      }
      case dubvec_f :
      {

        std::vector<double>* STD_int_ferturez = new std::vector<double>*();

        break;
      }

      case 2 :
      {

        break;
      }
      default :
      {

      break;
      }

    }


    return true;
  }

  bool destory_clean(){

  }
};


#endif


//pixel_feturez
#ifndef PIXEL_FTR_H
#define PIXEL_FTR_H
#include "pix_Feture_type.h"

class pix_fetr_host{

    protected:
    int total_types_of_feturz;




      public :
          std::vector<pix_Feture_type> picel_feture_data_t_vec ;

        pix_fetr_host(){}
        ~pix_fetr_host(){}


} ;
#endif
