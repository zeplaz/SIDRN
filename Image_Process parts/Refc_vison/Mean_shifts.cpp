

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
    {
      //meanshift data inlizlations...what...oh deary
      std::vector<std::tuple<double,double,double>> filterd_pix_vec;
      int rowz  = (int) img_ref.img_header.widthx;                   //raw_img_wfet.x_size;
      int colmz = (int) img_ref.img_header.highty;
      meshift_img.img_header= img_ref.img_header;
      // need dummy pixel spaces, expaned or rather likyl parce out to types. of thigns later
      pixel_feture_xy_RGB cur_pix_fetrz;
      pixel_feture_xy_RGB prev_pix_fetrz;
      pixel_feture_xy_RGB fetur_sum;
      pixel_feture_xy_RGB point;

      RGB_pix_intzity* cur_pix_intezy_RGB;

      // la nabourhood
      int east;
      int west;
      int north;
      int south;

      // statz
      int total_pointz;
      int itrationz=0;

      // copy to temp working image should use(move?)
      //imagkjz_RGB meanshifted_image;
      //meanshifted_image = img_ref;
      //meshift_img = img_ref;

      filterd_pix_vec.resize(img_ref.img_size);
        std::cout <<"##BEGIN::meanshift processing setup bandwith" << '\n';
      //narberhood space setup
      for(int i = 0; i < rowz; i++){
          //std::cout << "loop nabsetupz i"<< '\n';
		     for(int j = 0; j < colmz; j++){
          // std::cout << "loop nabsetupz j"<< '\n';
            //process nabourhood
          	east = (j - spc_bandwith) > 0 ? (j - spc_bandwith) : 0;
      			west = (j + spc_bandwith) < colmz ? (j + spc_bandwith) : colmz;
      			north = (i - spc_bandwith) > 0 ? (i - spc_bandwith) : 0;
            south = (i + spc_bandwith) < rowz ? (i + spc_bandwith) : rowz;

          //  RGB_pix_intzity* cur_pix_intezy_RGB;

            if(j!=0)
              {
               prev_pix_fetrz.pcopyer(cur_pix_fetrz);
              }

              RGB_pix_intzity*  prt_instysturc = img_ref.locat_pixel_fet_data((j*i)+j);

            cur_pix_fetrz.point_setter(prt_instysturc,i,j);
            int step = 0;

            //avoid 1st pixel
      if(j>0)
        {   //run bandwith and point total
            do {
              //std::cout << "doloop!Z"<< '\n';
              fetur_sum.pmaual_feture_set(0,0,0,0,0);

              total_pointz=0;

              for(int windx=north; windx<south;windx++ ){
                for(int windy=east; windy<west; windy++)
                  {
                    int id=(windx*windy)+windy;
                    double r,g,b;

                     cur_pix_intezy_RGB = img_ref.locat_pixel_fet_data(id);

                    r  = cur_pix_intezy_RGB->img_colour_intisity_double[0];
                    g  = cur_pix_intezy_RGB->img_colour_intisity_double[1];
                    b  = cur_pix_intezy_RGB->img_colour_intisity_double[2];

                     point.pmaual_feture_set((double)windx,(double)windy,r,g,b);

                     if (point.point_RGB_distance(cur_pix_fetrz)>h_bandwith)
                     {
                       std::cout << "distance: " <<point.point_RGB_distance(cur_pix_fetrz) << "hband:" <<h_bandwith <<'\n';

                       fetur_sum.fetureaccumalor(point);
                       //std::cout << "fetsumz:" << fetur_sum.fetureaccumalor(point) <<'\n';
                       total_pointz++;
                       std::cout <<"toalpointz:" << total_pointz;
                     }
                   }
                 }
                 //scale to normliz
                 fetur_sum.pointscaler(1.0/total_pointz);
                 cur_pix_fetrz.pcopyer(fetur_sum);
                 itrationz++;
                 std::cout<< "iterazionz:" << itrationz <<'\n';
               } while((cur_pix_fetrz.point_RGB_distance(prev_pix_fetrz)>SHIFT_RGB_ELPZON) &&
                        (cur_pix_fetrz.point_spatial_distance(prev_pix_fetrz)>SHIFT_SPACE_ELPZON) &&
                        (itrationz <MAX_CONVRG_ITRATIONZ));
                    pixel_feture_xy_RGB* prt_cur =&cur_pix_fetrz;
                    meshift_img.set_feture_space(prt_cur,(j*i)+j);
              //    filterd_pix_vec.at((i*j)+j) = cur_pix_fetrz.rgb_chanell_tuple;
              //    nabrhood_xy_RGB  = img_ref.locat_pixel_fet_data((i*j)+j);
            //  std::cout << "val at touple" << std::get<0>(cur_pix_fetrz.rgb_chanell_tuple) << " val at inzty:"  <<cur_pix_intezy_RGB->img_colour_intisity_double[0];

                //  cur_pix_intezy_RGB->img_colour_intisity_double[0] =  std::get<0>(cur_pix_fetrz.rgb_chanell_tuple);
              //    cur_pix_intezy_RGB->img_colour_intisity_double[1] =  std::get<1>(cur_pix_fetrz.rgb_chanell_tuple);
              //    cur_pix_intezy_RGB->img_colour_intisity_double[2] =  std::get<2>(cur_pix_fetrz.rgb_chanell_tuple);
                //  meshift_img.
            //    int temp_id =((i*j)+j);
            //    pixel_feture_xy_RGB*  tmp_pix_rgb  = &cur_pix_fetrz;
            //    meshift_img.set_feture_space(tmp_pix_rgb,temp_id);

               }
             }
             }
            // meshift_img.set_pixel_raw_data();

             std::cout <<"->meanshift reached end pointsetup and inalization of channelz" << '\n';
}
                         //raw_img_wfet.y_size;
///dooimz

  size_t img_int_byte_size;
  int reg_num =0;
  int label_ID=-1;

  img_int_byte_size = (rowz*colmz*sizeof(int));

  double *mode_ptr = new double [rowz*colmz*3];
  int *number_of_modez = new int[rowz*colmz];

  memset(number_of_modez,0,img_int_byte_size);

  //settup labelz
  int *label_array_spacefet= new int [rowz*colmz];

  // inazing the lables to -1

    for (int i =0; i<=rowz; i++)
      {
         for (int j =0; j< colmz; j++)
         {
          label_array_spacefet[(i*j)+j]=-1;
        //  std::cout << "add-fetspace:" << (i*j)+j << " maxsize:" << rowz*colmz << '\n';
         }
       }

      // for (int del=0; del< rowz; del++)
      //   {
          // delete label_array_spacefet[del];
      //   }


    for (int i=0; i<rowz; i++)
    {
      for (int j=0;j<colmz; j++)
      {
        if(label_array_spacefet[(i*j)+j]<0)
        {
          label_array_spacefet[(i*j)+j] = ++label_ID;
          //find locaion of point
          std::cout << "POINTSETTER CALL::2" <<'\n';
          cur_pix_fetrz.point_setter(meshift_img.locat_pixel_fet_data((i*j)+j),i,j);
          std::tuple<double,double,double>* prt_cur_tuple = cur_pix_fetrz.getptr_channl_touple();
//modezassbfz
          mode_ptr[label_ID*3+0]  = std::get<0>(*prt_cur_tuple);
          mode_ptr[label_ID*3+1]  = std::get<1>(*prt_cur_tuple);
          mode_ptr[label_ID*3+2]  = std::get<2>(*prt_cur_tuple);


// 8nabour expantion
      std::stack<pixel_feture_xy_RGB> nabourhoodPointz;

      //std::vector<pixel_feture_xy_RGB> nabourhoodPointz;
      nabourhoodPointz.push(cur_pix_fetrz);



            //pixel_feture_xy_RGB current_pixl_fet;
            while(!nabourhoodPointz.empty())
            {
              point = nabourhoodPointz.top();
              nabourhoodPointz.pop();

              for(int k =0; k<8; k++)
              {
                int bandwith_x = point.pix_xy_fet[0]+ nabourhoodoffset[k][0];
                int bandwith_y = point.pix_xy_fet[1]+ nabourhoodoffset[k][1];

                if((bandwith_x>=0)&&(bandwith_y>=0) &&
                  (bandwith_x<rowz)&& (bandwith_y<colmz))
                  {
                //   &&  ([bandwith_x][bandwith_y]<0))
                  pixel_feture_xy_RGB tempPoint;
                  std::cout << "POINTSETTER CALL::3" <<'\n';

                //pixel_feture_xy_RGB* prt_tmp_pt=&tempPoint;

                tempPoint.point_setter(img_ref.locat_pixel_fet_data((bandwith_x*bandwith_y)+bandwith_y),bandwith_x,bandwith_y);

                if(cur_pix_fetrz.point_RGB_distance(tempPoint)<h_bandwith)
                {
                  std::cout <<"insize setlabelnew:" <<cur_pix_fetrz.point_RGB_distance(tempPoint) << "h_band:" <<h_bandwith <<'\n';
                  label_array_spacefet[(bandwith_x*bandwith_y)+bandwith_y] = label_ID;
                  nabourhoodPointz.push(tempPoint);
                  number_of_modez[label_ID]++;

                  mode_ptr[label_ID*3+0]  = std::get<0>(tempPoint.rgb_chanell_tuple);
                  mode_ptr[label_ID*3+1]  = std::get<1>(tempPoint.rgb_chanell_tuple);
                  mode_ptr[label_ID*3+2]  = std::get<2>(tempPoint.rgb_chanell_tuple);
                }
              }// end bandwich ifz

            }//end nabhordscan
          }



            number_of_modez[label_ID]++;

            mode_ptr[label_ID*3+0]  /= number_of_modez[label_ID];
            mode_ptr[label_ID*3+1]  /= number_of_modez[label_ID];
            mode_ptr[label_ID*3+2]  /= number_of_modez[label_ID];

         }
         }
        }


        reg_num= label_ID+1;


      //place in meshift image for final reulz
        for(int i = 0; i< rowz;i++)
        { for (int j = 0; j < colmz; j++)
         {
           label_ID = label_array_spacefet[(i*j)+j];

           double red   = mode_ptr[label_ID*3+0];
           double green = mode_ptr[label_ID*3+1];
           double blue  = mode_ptr[label_ID*3+2];

           pixel_feture_xy_RGB pixl_point;

           pixl_point.pmaual_feture_set(i,j,red,green,blue);

            std::tuple<double,double,double>* temp_touple_RGB;
            temp_touple_RGB  = pixl_point.getptr_channl_touple();

            meshift_img.raw_img_rgb_vec.at(label_ID)   = (uint8_t)(std::get<0>(*temp_touple_RGB));
            meshift_img.raw_img_rgb_vec.at(label_ID+1) = (uint8_t)(std::get<1>(*temp_touple_RGB));
            meshift_img.raw_img_rgb_vec.at(label_ID+2) = (uint8_t)(std::get<2>(*temp_touple_RGB));
            std::cout << "covertduint8:" << meshift_img.raw_img_rgb_vec.at(label_ID) << '\n'
            << "touple:" << std::get<2>(*temp_touple_RGB)  << '\n';
          //        }
        }
        }
        //meshift_img = meanshifted_image;

}
//cleanupmemory
/*
    delete[] mode_ptr;
    delete[] number_of_modez;


*/
//delete[] label_array_spacefet;

    //  }*/
