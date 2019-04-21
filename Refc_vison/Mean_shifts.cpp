

//Mean_shifts.cpp

#include "Mean_shifts.h"


#define MAX_CONVRG_ITRATIONZ 7
#define SHIFT_RGB_ELPZON 0.41786991919
#define SHIFT_SPACE_ELPZON 0.2801065834

      const int nabourhoodoffset[8][2] =
        {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}}; // Region Growing

  Mean_shifts::Mean_shifts(double sband, double cband)
    {
      spc_bandwith = sband;
      h_bandwith   = cband;
    }

//meanshiftseg
  void Mean_shifts::meanshift_seg_RGB(imagkjz_RGB& img_ref, imagkjz_RGB& meshift_img)
    {// imagkjz_RGB meanshifted_image;

    //  meanshifted_image = *img_ref;
    std::vector<std::touple<double,double,double>> filterd_pix_vec;
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

      filterd_pix_vec.resize(img_ref->img_size);
      meshift_img = img_ref;


      for(int i = 0; i < rowz; i++){
		      for(int j = 0; j < colmz; j++){

          	east = (j - spc_bandwith) > 0 ? (j - spc_bandwith) : 0;
      			west = (j + spc_bandwith) < colmz ? (j + spc_bandwith) : colmz;
      			north = (i - spc_bandwith) > 0 ? (i - spc_bandwith) : 0;
            south = (i + spc_bandwith) < rowz ? (i + spc_bandwith) : rowz;

            cur_pix_fetrz.point_setter(img_ref,i,j);
            step = 0;
            image_intcity_struc* cur_feture_stc;
            do {
              prev_pix_fetrz.copyer(cur_pix_fetrz);
              fetur_sum.pmaual_feture_set(0,0,0,0,0);

              total_pointz=0;

              for(int windx=north; windx<south;windx++ ){
                for(int windy=east; windy<west; windy++)
                  { int id=(windx*windy)+windy;
                    double r,g,b;
                    cur_feture_stc= meshift_img.locat_pixel_fet_data(id);

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
               } while((cur_pix_fetrz.point_RGB_distance(prev_pix_fetrz)>SHIFT_RGB_ELPZON) &&
                        (cur_pix_fetrz.point_spatial_distanc(prev_pix_fetrz)>SHIFT_SPACE_ELPZON) &&
                        (itrationz <MAX_CONVRG_ITRATIONZ));


              //    filterd_pix_vec.at((i*j)+j) = cur_pix_fetrz.rgb_chanell_tuple;
                  cur_feture_stc  = meshift_img.locat_pixel_fet_data((i*j)+j);
                  *cur_feture_stc = cur_pix_fetrz.rgb_chanell_tuple;
               }
             }
                         //raw_img_wfet.y_size;
///dooimz

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
          cur_pix_fetrz.point_setter(meshift_img,i,j);
          std::touple<double,double,double> prt_cur_tuple = cur_pix_fetrz.getptr_channl_touple();
//modezassbfz
          mode_ptr[label_ID*3+0]  = std::get<0>(prt_cur_tuple);
          mode_ptr[label_ID*3+1]  = std::get<1>(prt_cur_tuple);
          mode_ptr[label_ID*3+2]  = std::get<2>(prt_cur_tuple);


// 8nabour expantion
      std::vector<pixel_feture_xy_RGB> nabourhoodPointz;
      nabourhoodPointz.push_back(cur_pix_fetrz);

            //pixel_feture_xy_RGB current_pixl_fet;
            while(!nabourhoodPointz.empty())

            {
              point = nabourhoodPointz.back();
              nabourhoodPointz.pop_back();

              for(int k =0; k<8; k++)
              {
                int bandwith_x = point.pix_xy_fet[0]+ nabourhoodoffset[k][0];
                int bandwith_y = point.pix_xy_fet[1]+ nabourhoodoffset[k][1];

                if((bandwith_x>=0)&&(bandwith_y>=0) &&
                  (bandwith_x<rowz)&& (bandwith_y<colmz) &&
                  ([bandwith_x][bandwith_y]<0))
              {
                pixel_feture_xy_RGB tempPoint;

                tempPoint.point_setter(meshift_img,i,j);

                if(cur_pix_fetrz.point_RGB_distance(tempPoint)<h_bandwith)
                {
                  label_array_spacefet[bandwith_x][bandwith_y] = label_ID;
                  nabourhoodPointz.push_back(tempPoint);
                  number_of_modez[label_ID]++;

                  mode_ptr[label_ID*3+0]  = std::get<0>(tempPoint.rgb_chanell_tuple);
                  mode_ptr[label_ID*3+1]  = std::get<1>(tempPoint.rgb_chanell_tuple);
                  mode_ptr[label_ID*3+2]  = std::get<2>(tempPoint.rgb_chanell_tuple);
                }
                }
              }
            }
            number_of_modez[label_ID]++;

            mode_ptr[label_ID*3+0]  /= number_of_modez[label_ID];
            mode_ptr[label_ID*3+1]  /= number_of_modez[label_ID];
            mode_ptr[label_ID*3+2]  /= number_of_modez[label_ID];

          }
        }

        }
        reg_num= label_ID+1;

        //
        //place in meshift image for final reulz
        for(int i = 0; i< rowz;i++)
        { for (int j = 0; j < colmz; j++)
         {
           label_ID = label_array_spacefet[i][j];

           double red   = mode_ptr[label_ID*3+0];
           double green = mode_ptr[label_ID*3+1];
           double blue  = mode_ptr[label_ID*3+2];

           pixel_feture_xy_RGB pixl_point;

           pixl_point.pmaual_feture_set(i,j,red,green,blue);
           meshift_img.

          // pixl_point.
           //std::tie();
          // image_intcity_struc.img_colour_intisity_double[Pix_id]
            std::touple<double,double,double>* temp_touple_RGB;
            temp_touple_RGB  = pixl_point.getptr_channl_touple()

            raw_img_rgb_vec.at(Pix_id)   = reinterpret_cast<uint8_t>(std::get<0>(temp_touple_RGB));
            raw_img_rgb_vec.at(Pix_id+1) = reinterpret_cast<uint8_t>(std::get<1>(temp_touple_RGB));
            raw_img_rgb_vec.at(Pix_id+2) = reinterpret_cast<uint8_t>(std::get<2>(temp_touple_RGB));

        }
      }

//cleanupmemory

    delete[] mode_ptr;
    delete[] number_of_modez;

    for (int del=0; del< rowz, del++)
      {
        delete[]label_array_spacefet[i];
      }
        delete[] label_array_spacefet;
      }
