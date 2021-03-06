
//Img_processing
#ifndef IMAGE_PROZ_MKI_H
#define IMAGE_PROZ_MKI_H

//clinz
#include <cstdlib>
#include <cstdio>

#include <iostream>
#include <cmath>
#include <vector>

#include <list>
#include <map>


//sorcelibz
//#include "Histagramz.h"
#include "Image_PGM_P2.h"
#include "vrt_mask.h"

//#include "Objkfactory.h"




//static long double PI = 3.141592653589793238462643383279502884197169399375105820974944592307816406286;
#define colum_derv 1
#define laplac_iner 2
#define laplac_outer 3

class image_procczor_mrk_1022
{
  //image_Byte8;

  private :
//  typedef std::map<uint32_t[2],std::vector<uint32_t>> label_count_pair_pixloc;
  typedef std::map<uint32_t,uint32_t[2]>    cordnt_labl_map;
  typedef std::map<int,std::vector<double>> pix_feture_map;
  typedef std::map<int,Image_PGM_P2*> image_ptr_map;
    //typedef std::map<uint8_t,img_obkj*> obj_labl_map;

    private :
    //Objkfactory img_obj_fac;

  //  label_count_pair_pixloc lb_count_pair_pixloc;
  //  label_count_pair_pixloc::iterator itor_pix_lib;
    // label_count_pair_pixloc::const_iterator cons_itor_pix_lib;
    image_ptr_map img_prt_map;
    pix_feture_map pix_img_fetr_map;
     pix_feture_map::iterator pix_fet_itr;
     std::list<uint32_t[2]>* obcj_corn_list_prt;
     void  union_obj(uint32_t parent_label, uint32_t conect_laebl);
     image_ptr_map::iterator img_map_itr;


    public :
        ~image_procczor_mrk_1022();

    Image_PGM_P2* thresholdImg(Image_PGM_P2* inimg);
    uint32_t calculate_threashold(Image_PGM_P2* img_to_th);
    void   hisagramcal_(Image_PGM_P2* img_inz, int mode);
    void run_masks(int nummask, std::vector<int>* type,Image_PGM_P2* img_inz , Image_PGM_P2* samp_log);
    Image_PGM_P2* return_img_from_map(int id_img);

    Image_PGM_P2 combine_avg_imgs(int num_imgz, std::vector<Image_PGM_P2*>);
    

      int Obj_total=0;
      int img_toal=0;
   //obj_labl_map ojk_labl_mapinst;
     cordnt_labl_map r_cpar_map_lb;

    //  image_Byte8* thresholdImg(image_Byte8* inimg);
    //  int calculate_threashold(image_Byte8* img_to_th);

    //  void apply_erode(image_Byte8* inimg);
    //  void apply_dilate(image_Byte8* inimg);
  //    void open_morph(image_Byte8* inimg);
    //  void close_morph(image_Byte8* inimg);

      void conected_comp_labler(Image_PGM_P2* scanab_img);


      //void cal_centriod(img_obkj* img_obk_in);
      //void cal_bbox(img_obkj* img_obk_in);

  //  void  union_obj(int parent_label, int conect_laebl);

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
