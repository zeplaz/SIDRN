
#ifndef MEAN_SHIFTS_H
#define MEAN_SHIFTS_H


//stdlibz
#include <utility>
#include <tuple>
#include <iostream>
#include <vector>

#include "imagkjz_RGB.h"
#include "pixel_feture_xy_RGB.h"

#define MAX_CONVRG_ITRATIONZ 5
#define SHIFT_RGB_ELPZON 0.41786991919
#define SHIFT_SPACE_ELPZON 0.2801065834

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


//Mean_shifts.cpp

  Mean_shifts::Mean_shifts(double sband, double cband)
    {
      spc_bandwith = sband;
      h_bandwith   = cband;
    }

//meanshiftseg
  void Mean_shifts::meanshift_seg_RGB(imagkjz_RGB& img_ref)
    {
      int rowz  = reinterpret_cast<int> img_ref->img_header.widthx;                   //raw_img_wfet.x_size;
      int colmz = reinterpret_cast<int> img_ref->img_header.highty;

      pixel_feture_xy_RGB cur_pix_fetrz;
      pixel_feture_xy_RGB prev_pix_fetrz;
      pixel_feture_xy_RGB fetur_sum;
      pixel_feture_xy_RGB point;

      int east;
      int west;
      int north;
      int south;

      int total_pointz;
      int itrationz;

      for(int i = 0; i < rowz; i++){
		      for(int j = 0; j < colmz; j++){

          	east = (j - spc_bandwith) > 0 ? (j - spc_bandwith) : 0;
      			west = (j + spc_bandwith) < colmz ? (j + spc_bandwith) : colmz;
      			north = (i - spc_bandwith) > 0 ? (i - spc_bandwith) : 0;
            south = (i + spc_bandwith) < rowz ? (i + spc_bandwith) : rowz;

            cur_pix_fetrz.point_setter(img_ref,i,j);
            step = 0;

            do {
              prev_pix_fetrz.copyer(cur_pix_fetrz);
              fetur_sum.pmaual_feture_set(0,0,0,0,0);

              total_pointz=0;

              for(int windx=north; windx<south;windx++ ){
                for(int windy=east; windy<west; windy++)
                  { int id=(windx*windy)+windy;
                    double r,g,b;
                     image_intcity_struc* cur_feture_stc= locat_pixel_fet_data(id);

                    r  = cur_feture_stc->img_colour_intisity_double[0];
                    g  = cur_feture_stc->img_colour_intisity_double[1];
                    b  = cur_feture_stc->img_colour_intisity_double[2];

                     point.pmaual_feture_set((double)windx,(double)windy,r,g,b);

                     if (point.point_RGB_distance(cur_pix_fetrz)<h_bandwith)
                     {
                       fetur_sum.fetureaccumalor(point);
                       total_pointz++;
                     }
                   }
                 }
                 //scale to normliz
                 fetur_sum.pointscaler(1.0/total_pointz);
                 cur_pix_fetrz.pcopyer(fetur_sum);
                 itrationz++;
               } while((cur_pix_fetrz.point_spatial_distance(prev_pix_fetrz)>SHIFT_RGB_ELPZON) &&
               (cur_pix_fetrz>)
                         //raw_img_wfet.y_size;
          }

	}while((PtCur.MSPoint5DColorDistance(PtPrev) > MS_MEAN_SHIFT_TOL_COLOR)
  && (PtCur.MSPoint5DSpatialDistance(PtPrev) > MS_MEAN_SHIFT_TOL_SPATIAL) &&
   (step < MS_MAX_NUM_CONVERGENCE_STEPS));

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
