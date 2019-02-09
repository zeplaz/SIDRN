
//Img_processing



#include <cstdlib>
#include <cstdio>

#include <iostream>
#include <cmath>
#include <vector>
#include "image_Byte8.h"


class image_procczor_mrk_1001

{

  private :
  typedef std::map<int[2], int> obj_labl_map;

  private :
  Objkfactory img_obj_fac;

public :
          //StructuringElement;
  //  int num_img_columns, Num_img_rows, max_pixal,totalpix, head_int;

    uint8_t *imga *hista *outimageHistogram;
  //  void calc_hista(image_Byte8* inimg);
//    void write_hista(image_Byte8* inimg );

    std::map<int,int[2]>  Row_first ;
    std::map<int,int[2]>  Row_second ;

    std::vector<int> object_comp;

    bj_labl_map ojk_labl_mapinst;


    image_Byte8* thresholdImg(image_Byte8* inimg);

    void apply_erode(image_Byte8* inimg);
    void apply_dilate(image_Byte8* inimg);

    void open_morph(image_Byte8* inimg);
    void close_morph(image_Byte8* inimg);

    void cal_centriod(image_Byte8* inimg);

    void conected_comp_labler(image_Byte8* scanab_img);

    double obj_centrod();
                        //char object_iditifer();


const int drc_rowxNESW[] = {1,0,-1,0};
const int drc_rowyNESW[] = {0,1,0,-1};

//image_procczor_mrk_1001.cpp

#include "Objkfactory.h"
#include "img_obkj.h"


void image_procczor_mrk_1001::open_morph(image_Byte8* inimg)
    {
      apply_dilate(inimg);
      apply_erode(inimg);

    }

    void image_procczor_mrk_1001::close_morph()
        {
          apply_erode(inimg);
          apply_dilate(inimg);

        }



uint8_t image_procczor_mrk_1001::calculate_threashold(image_Byte8* img_to_th);

{
  uint8_t tempthrsh_cal = 40;
 return (tempthrsh_cal);
}



void image_procczor_mrk_1001::conected_comp_labler(image_Byte8* scanab_img);

{

  int current_label;
  int  next_label;
  int pix_par[2];
      =2*(std::cos(thad))
 std::vector<int> parent_label_array;

    uint16_t i,j;

    for (i=0 ;  i< scanab_img->get_h_rs()+1; i++)

    {
      for (j =0; j < scanab_img->get_W_cs()+1;j++)
            {

              if (scanab_img->pixelz[i,j] !=0)
                {
                  while (i>1 && i < scanab_img->get_h_rs())

                  {if (scanab_img->pixelz[i-1,j]!=0)}
                  pix_par[1]=j;
                  pix_par[0]=i;

                  ojk_labl_mapinst.insert(std::make_pair(pix_par,current_label);



                  if (scanab_img->pixelz[i,j-1] !=0)
                  {next_label++;

                temp_onjc    = img_obj_fac.create_img_obk(next_label);

                  }
                  current_label = <int,int[2]>

                }

                img_obkj

            for ()
             {


             }


      }

  }





  void image_procczor_mrk_1001::thresholdImg( image_Byte8* img_to_th ,int rows,int cols );
  { int r, c;

  uint8_t threshold
  uint8_t **image_tmp=NULL;
   threshold = calculate_threashold(img_to_th);

    for(r=0;r<rows;r++){
          for(c=0;c<cols;c++){
             if(img_to_th[r][c] < threshold) image_tmp[r][c] = 0;
             else image_tmp[r][c] = 1;
          }
       }

  }




  void image_procczor_mrk_1001::calc_hista()
  {

    //  bool flag_b = false;
    int i, j;
    int highist_alha;

   this->hista = (uint8_t char*) maloc(this->maxpix);

    highist_alha = this->imagez[0];

  for (i = 0; i< toal_pix ; i++)
  {
      this->hista[this->image_gry] +=1;

    }

  for (i =0; i < this->max_pixal; i++)

          if (this->hista[i]> highist_alha)
          {
              highist_alha = this->hista[i];
          }

}



void image_procczor_mrk_1001::write_hista(int )

{

  std::FILE * hisa_fpOut;


}


}


void Union_(int a, int b)
{
    // get the root component of a and b, and set the one's parent to the other
    while (object_comp[a] != a)
        a = object_comp[a];
    while (object_comp[b] != b)
        b = object_comp[b];
    object_comp[b] = a;
}

void unionCoords(image_byte8* uni_img_pix ,int x, int y, int x2, int y2)
{
    if (y2 < uni_img_pix->get_h_rs() && x2 < uni_img_pix->get_w_cs() && uni_img_pix->pixelz[x][y] && input[x2][y2])
        doUnion(x*h + y, x2*h + y2);
}


for (int i = 0; i < uni_img_pix->get_w_cs()*uni_img_pix->get_h_rs(); i++)
       component[i] = i;
   for (int x = 0; x < w; x++)
   for (int y = 0; y < h; y++)
   {
       unionCoords(x, y, x+1, y);
       unionCoords(x, y, x, y+1);
   }


};
