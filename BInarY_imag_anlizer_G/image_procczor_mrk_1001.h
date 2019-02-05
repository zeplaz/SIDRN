
//Img_processing

class image_procczor_mrk_1001

{

public :
StructuringElement;

int num_img_columns, Num_img_rows, max_pixal,totalpix, head_int;

uint8_t *imga *hista *outimageHistogram;
void calc_hista();
void write_hista(int );
void thresholdImg();

void apply_erode(image_Byte8* inimg);
void apply_dilate(image_Byte8* inimg);

void open_morph(image_Byte8* inimg);
void close_morph(image_Byte8* inimg);


conected_comp_labler();

{


}
float obj_centrod();

char object_iditifer();


struct obj_propertiez{
  int obj_id;
  int Arra_size;
  foat centrod;
    uint8_t[4] lagest_4_rowsvalue;
  uint8_t[4] smallest_4_rowsvalue;
  uint8_t[4]  lagest_4_columvalue;
  uint8_t[4] smallest_4_columvalue;

  char type;
int next_label;

const int drc_rowxNESW[] = {1,0,-1,0};
const int drc_rowyNESW[] = {0,1,0,-1};
}

std::vector<int> object_comp;
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
    if (y2 < uni_img_pix-get_h_rs() && x2 < uni_img_pix-get_w_cs() && uni_img_pix->pixelz[x][y] && input[x2][y2])
        doUnion(x*h + y, x2*h + y2);
}


for (int i = 0; i < w*h; i++)
       component[i] = i;
   for (int x = 0; x < w; x++)
   for (int y = 0; y < h; y++)
   {
       unionCoords(x, y, x+1, y);
       unionCoords(x, y, x, y+1);
   }


};



void image_procczor_mrk_1001:: open_morph(image_Byte8* inimg)
    {
      apply_dilate(inimg);
      apply_erode(inimg);

    }

    void image_procczor_mrk_1001::close_morph()
        {
          apply_erode(inimg);
          apply_dilate(inimg);

        }
//image_procczor_mrk_1001.cpp

#include <iostream>
#include <cstdlib>
#include <cstdio>

uint8_t image_procczor_mrk_1001::calculate_threashold(image_Byte8* img_to_th);


void image_procczor_mrk_1001::conected_comp_labler(image_Byte8* scanab_img);

{
    uint16_t i,j;


    for (i=0 ;  i< scanab_img->get_h_rs()+1; i++)

    {
      for (j =0; j < scanab_img->get_W_cs()+1;j++)
            {

              if (scanab_img->pixelz[i,j] !=0)
                {


                  next_label++;

                }
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
             else image_tmp[r][c] = 255;
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
