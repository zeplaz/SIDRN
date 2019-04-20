
#ifndef MEAN_SHIFTS_H
#define MEAN_SHIFTS_H


//stdlibz
#include <utility>
#include <tuple>
#include <iostream>
#include <vector>


#include "imagkjz_RGB.h"
#include "pixel_feture_xy_RGB.h"

class imagkjz_RGB;

class Mean_shifts
{
  public :
  double spc_bandwith;
  double h_bandwith;
  image_colour_RGB* prt_meanshift_img;

  public :
  Mean_shifts(double, double);
  image_colour_RGB meanshift_seg_RGB(image_colour_RGB&);

};
#endif




void split_xyfrom_ID_Lamda( int& widx, int& hty, const int &pix_ID)
[pix_ID]
{}


Mean_shifts::Mean_shifts(double sband, double cband)
{
spc_bandwith =sband;
h_bandwith = cband;
}

//meanshiftseg


void meanshift_seg_RGB(imagkjz_RGB& img_ref)
    {
      int rowz = reinterpret_cast<int> img_ref->img_header.widthx;                   //raw_img_wfet.x_size;
      int colmz =reinterpret_cast<int> img_ref->img_header.highty;



      pixel_feture_xy_RGB cur_pix_fetrz;
      pixel_feture_xy_RGB prev_pix_fetrz;
      pixel_feture_xy_RGB pix_sum;
      pixel_feture_xy_RGB point;

      int east;
      int west;
      int north;
      int south;

      int total_pointz;
      int itrationz;

      for(int i = 0; i < rowz; i++){
		for(int j = 0; j < colmz; j++){
			east = (j - hs) > 0 ? (j - hs) : 0;
			west = (j + hs) < colmz ? (j + hs) : colmz;
			north = (i - hs) > 0 ? (i - hs) : 0;
      south = (i + hs) < rowz ? (i + hs) : rowz;

      cur_pix_fetrz.point_setter(img_ref,i,j);
      step = 0;

      do {
        prev_pix_fetrz.copyer(cur_pix_fetrz);


      } while();
                   //raw_img_wfet.y_size;
    }



size_t img_int_byte_size;

int reg_num =0;
int label_ID=-1;

img_int_byte_size = (rowz*colmz*sieof(int));

double *mode_ptr = new double [rowz*colmz*3];
int *number_of_modez = new int[rowz*colmz];

memset(number_of_modez,0,img_int_byte_size);

//settup labelz
int **label_array_spacefet= new int *[rowz];

// inazing the lables to -1


  for (int i =0; i<rowz; i++)
    {
       for (int j =0; i< colmz; j++)
       {

         int
         label_array_spacefet[i][j]=-1;

       }

    }

    for (int i=0; i<rowz; i++)
    {
      for (int j=0;j<colmz; j++)
      {
        if(label_array_spacefet[i][j]<0)
        {
          label_array_spacefet[i][j] = ++label_ID;
          //find locaion of point


//modezassbfz
          mode_ptr[label_ID*3+0]  = prtfet.red;
          mode_ptr[label_ID*3+1]  = prtfet.green;
          mode_ptr[label_ID*3+2]  =prtfet.blue;


// 8nabour expantion
      std::vector<pixel_feture_xy_RGB> nabourhoodPointz;
      nabourhoodPointz.push_back(prtfet);

      pixel_feture_xy_RGB current_pixl_fet;

      //aure lock
      for(int k =0; k<8; k++)
      {
        int bandwith_x = current_pixl_fet.x_fet+; nabourhoodoffset[k][0];
        int bandwith_y =current_pixl_fet.y_fet+ nabourhoodoffset[k][1];



          if((bandwith_x>=0)&&(bandwith_y>=0) &&
            (bandwith_x<rowz)&& (bandwith_y<colmz) &&
            ([bandwith_x][bandwith_y]<0))
        {
          pixel_feture_xy_RGB temp_pix_fet;

          (double)img_ref->feturespace.at()  RGB_tuple.get<0> .at<uchar>(bandwith_x,bandwith_y)
          (double)img_ref->RGB_tuple.get<1>.at<uchar>(bandwith_x,bandwith_y)
          (double)img_ref->get<2>.at<uchar>(bandwith_x,bandwith_y)
        }
        auto
        std::get<0>()
        auto pixel_feture_xy_RGB std::make_from_tuple<pixel_feture_xy_RGB>(rgb_chanell_tuple);
std::tie(red,green,blue)

          ) )

      }
      const int nabourhoodoffset[8][2] =
       {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}}; // Region Growing
  std::unordered_map

        }

      }

    }

}
