


#include "image_procczor_mrk_1022.h"

//  Histagramz();

void image_procczor_mrk_1022::hisagramcal_(Image_PGM_P2* img_inz, int mode)
{
  int histagram_binz;
  Histagramz temphista;

  uint32_t min;
  uint32_t max;
  int step;

  printf("Histagram Procuzer activated\n");

    switch (mode)
    {
      case 0 :
        {   printf(" \n");

            histagram_binz =2;
            step =255/histagram_binz;
            temphista.create_empty_hista(histagram_binz);

            for (int k = 0; k< histagram_binz; k++)
            {  for (int i = 0; i<img_inz->b_imgArray.size(); i++)
                { for (uint32_t j = 0; j< img_inz->get_W_cs(); j++) 
                  {
                    if ( img_inz->b_imgArray[i].at(j)<step*i && img_inz->b_imgArray[i].at(j) > step*(i-1))
                          {
                            temphista.insert_to_bin(k);
                          }
            }}}

      break;
        }

      case 1 :
      {
        printf(" \n");
        histagram_binz = 255;
      break;
      }

      default :
      {
        printf("Defultmode Pleaze set bin number set 2-254:\n");
        std::cin >> histagram_binz;

        if(histagram_binz<3 && histagram_binz>255)
          {
            printf("error number not vaild exiting histagramgenrator\n");
       break;
          }

      }
    }//endswitch
  }
