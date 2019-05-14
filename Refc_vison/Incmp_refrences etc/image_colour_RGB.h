


#include <vector>
#include <stdio.h>
#include<stdlib.h>

//use template for map type.
typedef struct {
  unsigned char  red,green,blue;
} pix_intzity;


typedef struct {
  std::vector<double> pix_fetur_duble;
  std::unordered_map<int,pix_fetur_duble*> PIx_fet_map_id;
} pix_feturez_strc;

  typedef struct {

    int x_size, y_size;
    pix_intzity* ary_intencty;
    pix_feturez_strc* arry_pIx_feturez;

  } image_RGB_wfet;


class image_colour_RGB
{

  private :
    char cha_buffer[16];
    //char**
    image_RGB_wfet* raw_img_wfet;
    int _c_int, rgb_inticy_col, _Image_ID;
    FILE *in_FILE;

  public :

    image_colour_RGB()(int new_id){_Image_ID =new_id;}

    bool read_rgb_img(const char *file_load_nm);
    bool write_RGB_img(const char *out_filename,image_RGB_wfet* out_img);


    inline char** alloc_raw_input_array(size_t x_dimention, size_t y_dimention)
    {
      char** base_array = new char*[x_dimention];
      for (size_t i =0; i<x_dimention)
      {

      }
    }
  inline  void relase_base_array(char** array_in, size_t xdimention)
  {

  }
};



























  }
