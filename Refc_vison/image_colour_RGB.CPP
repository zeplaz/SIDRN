


#include "image_colour_RGB.h"


bool image_colour_RGB::read_rgb_img(const char *file_load_nm)
{

  in_FILE = fopen(file_load_nm,"rb");

  if(!in_FILE)
  {
    fprintf(stderr, " Unable to open file '%s'\n",file_load_nm);
    return false;

  }


if(!fgets(cha_buffer, sizeof(cha_buffer),in_FILE))
{
  perror(file_load_nm);

}
if (cha_buffer[0]!='P' || cha_buffer[1]!='6')
{
  fprintf(stderr, " file not PPM P6\n");
  return false;
}

//acclate isspace

  raw_img_wfet* img_r = new raw_img_wfet();

  if (!img_r)
  {
     fprintf(stderr, "eror creating emptyfile\n");
     return false;
  }

    _c_int = getc(in_FILE);
    while(_c_int=='#')
    {
      while (getc(in_FILE) != '\n');
      _c_int = getc(in_FILE);
    }

    ungetc(_c_int, in_FILE);


//size of imagec
 if (fscanf(in_FILE, "%d %d", &raw_img_wfet->x_size, &raw_img_wfet->y_size) !=2)
 {
    fprintf(stderr, "error imgald image size error \n");
   return false;

 }

 //read colorintenityz
 if(fscanf(in_FILE, "%d", &rgb_inticy_col) !=1))
 {
   fprintf(stderr, "Invalided intenity comp \n");
  return false;
 }


 //if colorcomnt not 8?

 //
 while (fgetc(in_FILE) !='\n')
 {
   raw_img_wfet->ary_intencty = new pix_intzity()

 }
 if(fread(raw_img_wfet->ary_intencty , 3* raw_img_wfet->x_size, raw_img_wfet->y_size, in_FILE) !=raw_img_wfet->y_size)
 {
   fprintf(stderr, "errloading img data");
   return false;
    }

return true;
}


bool image_colour_RGB:write_RGB_img(const char *out_filename,image_RGB_wfet* out_img)
{
  FILE *out_FILE;
  out_FILE = fopen(out_filename,"wb");

  if(!out_FILE)
  {
    fprintf(stderr,"unable to open file to write\n");
  }

//print the fileeader

    fprintf(out_FILE,"P6\n");

//
fprintf(out_FILE, "# Notez:procezzedimgprocor0.33\n");


  /* code */
    fprintf(out_FILE, "%d %d\n",raw_img_wfet->x_size,raw_img_wfet->y_size);


}
    //send out array to img
    fwrite(out_img->ary_intencty,3*out_img->x_size,out_img->y_size,out_FILE);
    printf("file writen to file '%s'\n",out_filename);
    fclose(out_FILE);

  fprintf(,)
}
