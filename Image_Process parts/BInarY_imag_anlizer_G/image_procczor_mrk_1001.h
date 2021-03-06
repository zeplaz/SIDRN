
//Img_processing
#ifndef IMAGE_PROZ_MKI_H
#define IMAGE_PROZ_MKI_H



#include <cstdlib>
#include <cstdio>

#include <iostream>
#include <cmath>
#include <vector>

#include <list>
#include <map>


#include "image_Byte8.h"

//#include "Objkfactory.h"



static long double PI = 3.141592653589793238462643383279502884197169399375105820974944592307816406286;

class image_procczor_mrk_1001
{
  //image_Byte8;

  private :
    typedef std::map<int,std::vector<int>> label_count_pair_pixloc;
    typedef std::map<uint8_t,int[2]>    cordnt_labl_map;
    //typedef std::map<uint8_t,img_obkj*> obj_labl_map;

    private :
     //Objkfactory img_obj_fac;

     label_count_pair_pixloc lb_count_pair_pixloc;
      label_count_pair_pixloc::iterator itor_pix_lib;
     label_count_pair_pixloc::const_iterator cons_itor_pix_lib;

     //std::list<int[2]>* obcj_corn_list_prt;

    public :

      int Obj_total;

      //obj_labl_map ojk_labl_mapinst;
      cordnt_labl_map r_cpar_map_lb;

      image_Byte8* thresholdImg(image_Byte8* inimg);
      int calculate_threashold(image_Byte8* img_to_th);

      void apply_erode(image_Byte8* inimg);
      void apply_dilate(image_Byte8* inimg);
      void open_morph(image_Byte8* inimg);
      void close_morph(image_Byte8* inimg);

      void conected_comp_labler(image_Byte8* scanab_img);


      //void cal_centriod(img_obkj* img_obk_in);
      //void cal_bbox(img_obkj* img_obk_in);

    void  union_obj(int parent_label, int conect_laebl);

    //  double get_obj_centrod();
      //  get_obj_bbox();
      //  get_second_moment();
};
#endif

/*
                        //char object_iditifer();
cal_bbox(img_obkj* img_obk_in)
{


}

const int drc_rowxNESW[] = {1,0,-1,0};
const int drc_rowyNESW[] = {0,1,0,-1};

//StructuringElement;
//  int num_img_columns, Num_img_rows, max_pixal,totalpix, head_int;

//  uint8_t *imga *hista *outimageHistogram;
//  void calc_hista(image_Byte8* inimg);
//    void write_hista(image_Byte8* inimg );

//  std::map<int,int[2]>  Row_first ;
//  std::map<int,int[2]>  Row_second ;

//std::vector<int> object_comp;
*/
