


#include "image_procczor_mrk_1022.h"

//  Histagramz();

  image_procczor_mrk_1022::~image_procczor_mrk_1022()
  {
  //  delete samp_log;
  }

   void image_procczor_mrk_1022::run_masks(int nummask, std::vector<int>* type,Image_PGM_P2* img_inz ,Image_PGM_P2* samp_log)
  {
     printf("->runmaskProcess:\n");



          Vrt_mask mask_data_sets;
          uint32_t new_max =0;

          samp_log->img_height_rows =  img_inz->img_height_rows-2;
          samp_log-> img_width_colums= img_inz->img_width_colums-2;
          samp_log->image_area_pix = (samp_log-> img_width_colums*samp_log->img_height_rows);

          printf("->setingUpmap:\n");



          for ( int i = 0; i < img_inz->img_height_rows; i++)
          {   //printf("seupfolo1: \n");
              for (int j = 0; j < img_inz->img_width_colums; j++)
              {
                  int temp_pix_loc;
                  std::vector<double> temp_vec;
                  int at=(i*img_inz->img_width_colums)+j;
                  img_inz->pix_fetur_dub_vec.push_back(temp_vec);
                  temp_pix_loc = (at);
                  temp_vec.push_back(i);
                  temp_vec.push_back(j);

                  if(i ==0 || j ==0 || j> img_inz->img_width_colums-1|| i> img_inz->img_width_colums-1)
                  {temp_vec.push_back(255);}

                  pix_img_fetr_map.insert(std::pair<int,std::vector<double>>(temp_pix_loc,temp_vec));
              }
           }
          printf("|pixmap_inilz_compleate:\n");

            switch (type->at(0))
            {
             case 0 :
               printf("Gauss_blurr_3x3:\n");
               std::cout << "image size to be vecotized in prtmapthing:" << img_inz->image_area_pix << std::endl;
               std::cout << "iwitdth: " << img_inz->img_width_colums  << " ihihgtz: " << img_inz->img_height_rows << std::endl;
                 std::cout <<  "size of pixmapempty:" << pix_img_fetr_map.size() << std::endl;
             for (int r=1; r < img_inz->img_height_rows-1; r++)
             {
             //  printf("forloopfor row maskrun\n");
                for (int c =1; c< img_inz->img_width_colums-1; c++)
               {//printf("forloopfor row colomz\n");
               //std::cout << "c:" << c << " r:" << r << std::endl;
                 double temp_val;
                  temp_val=(double)img_inz->b_imgArray[r-1].at(c-1);
           //       std::cout << "tempval1.1"<< temp_val << std::endl;
               temp_val  =temp_val *mask_data_sets.Gauss_blurr_3x3[0][0];
             //     std::cout << "tempval1.2"<< temp_val << std::endl;

                 temp_val=+(((double)img_inz->b_imgArray[r-1].at(c))    *mask_data_sets.Gauss_blurr_3x3[0][1]);
               //  std::cout << "tempval2"<< temp_val << std::endl;
              temp_val=+  (((double)img_inz->b_imgArray[r-1].at(c+1))  *mask_data_sets.Gauss_blurr_3x3[0][2]);
             temp_val=+  (((double)img_inz->b_imgArray[r].at(c-1))  *mask_data_sets.Gauss_blurr_3x3[1][0]);
             temp_val=+    (((double)img_inz->b_imgArray[r].at(c))    *mask_data_sets.Gauss_blurr_3x3[1][1]);
             temp_val=+    (((double)img_inz->b_imgArray[r].at(c+1))  *mask_data_sets.Gauss_blurr_3x3[1][2]);
           //      std::cout << "tempvalmany"<< temp_val << std::endl;
             temp_val=+    (((double)img_inz->b_imgArray[r+1].at(c-1))    *mask_data_sets.Gauss_blurr_3x3[2][0]);
             temp_val=+    (((double)img_inz->b_imgArray[r+1].at(c))    *mask_data_sets.Gauss_blurr_3x3[2][1]);
             temp_val=+      (((double)img_inz->b_imgArray[r+1].at(c+1))  *mask_data_sets.Gauss_blurr_3x3[2][2]);

             temp_val= temp_val/16;
            //   std::cout << "tempvaltotal"<< temp_val << std::endl;
                 if (temp_val < 0)
                 {temp_val = temp_val*-1;}
                  if (temp_val < 1)
                  {
                    temp_val=255;
                  }
                 if (static_cast<uint32_t>(temp_val) >new_max )
                 {   printf("NewMaxpix established:%s\n",temp_val);
                   new_max= static_cast<uint32_t>(temp_val);
                 }

                 std::vector<double>* ptr_temp_db_vec;
                 int at = (r*samp_log->img_width_colums)+c;
               //  std::cout << "looking at:" <<at <<std::endl;
                       pix_fet_itr = pix_img_fetr_map.find(at);
                         if(pix_fet_itr != pix_img_fetr_map.end())
                       {        //              printf("addtomaplopfind:\n");

                          ptr_temp_db_vec = &pix_fet_itr->second;
                         ptr_temp_db_vec->push_back(temp_val);
                       //  std::cout << "tempvalpushed back:"<<ptr_temp_db_vec->at(2) << std::endl;
                       }
                         else {printf("where is it goin! map out of range for mix_feturz\n");}
                 }}
                 printf("endofMask_convloaded to Vector\n");
                 /*
                   //   printf("goingtoaddmix:\n");
                          //       std::vector<double>* ptr_temp_db_vec;

                                 int at = (r*img_inz->img_width_colums-2)+c;
                                 std::cout << "looking at:" <<at <<std::endl;
                              std::vector<std::vector<double>>* ptr_temp_db_vec;

                                ptr_temp_db_vec = &img_inz->pix_fetur_dub_vec;
                            //    ptr_temp_db_vec[at].push_back(temp_val);
                                            //  pix_img_fetr_map[at].push_back(temp_val);

                                    //   pix_fet_itr = pix_img_fetr_map.find(at);
                                  //       if(pix_fet_itr != pix_img_fetr_map.end())
                                //       {                      printf("addtomaplopfind:\n");

                            //              ptr_temp_db_vec = &pix_fet_itr->second;
                            //             ptr_temp_db_vec->push_back(temp_val);}
                          //               else {printf("where is it goin! map out of range for mix_feturz\n");}
                                 }}
                                 printf("endofMask_convloaded to Vector\n");
                                 */
               break;


             break;
              case 1 :
                printf("edge_8cent:\n");
                std::cout << "image size to be vecotized in prtmapthing:" << img_inz->image_area_pix << std::endl;
                std::cout << "iwitdth: " << img_inz->img_width_colums  << " ihihgtz: " << img_inz->img_height_rows << std::endl;
                std::cout <<  "size of pixmapempty:" << pix_img_fetr_map.size() << std::endl;

                  std::cout << "newimng size to be vecotized in prtmapthing:" << samp_log->image_area_pix << std::endl;
                  std::cout << "logiwitdth: " << samp_log->img_width_colums  << " loihihgtz: " << samp_log->img_height_rows << std::endl;
                  std::cout <<  "size of pixmapempty:" << pix_img_fetr_map.size() << std::endl;

               for (uint32_t r=1; r < img_inz->img_height_rows-1; r++)
               {
                  //  printf("forloopfor row maskrun\n");
                 for (uint32_t c =1; c< img_inz->img_width_colums-1; c++)
                {   //printf("forloopfor row colomz\n");
                    //  std::cout << "c:" << c << " r:" << r << std::endl;
                  double temp_val;
                  temp_val=(double)img_inz->b_imgArray[r-1].at(c-1);
                    //       std::cout << "tempval1.1"<< temp_val << std::endl;
                 temp_val  =temp_val *mask_data_sets.edge_8cent[0][0];
                  //     std::cout << "tempval1.2"<< temp_val << std::endl;
                 temp_val=+(((double)img_inz->b_imgArray[r-1].at(c))    *mask_data_sets.edge_8cent[0][1]);
                //  std::cout << "tempval2"<< temp_val << std::endl;
                 temp_val=+  (((double)img_inz->b_imgArray[r-1].at(c+1))  *mask_data_sets.edge_8cent[0][2]);
                 temp_val=+  (((double)img_inz->b_imgArray[r].at(c-1))  *mask_data_sets.edge_8cent[1][0]);
                 temp_val=+    (((double)img_inz->b_imgArray[r].at(c))    *mask_data_sets.edge_8cent[1][1]);
                 temp_val=+    (((double)img_inz->b_imgArray[r].at(c+1))  *mask_data_sets.edge_8cent[1][2]);
            //      std::cout << "tempvalmany"<< temp_val << std::endl;
                 temp_val=+    (((double)img_inz->b_imgArray[r+1].at(c-1))    *mask_data_sets.edge_8cent[2][0]);
                 temp_val=+    (((double)img_inz->b_imgArray[r+1].at(c))    *mask_data_sets.edge_8cent[2][1]);
                 temp_val=+      (((double)img_inz->b_imgArray[r+1].at(c+1))  *mask_data_sets.edge_8cent[2][2]);
                std::cout << "tempvaltotal"<< temp_val << std::endl;
                  if (temp_val < 0)
                  {temp_val = temp_val*-1;}
                  if (temp_val == 0)
                  {  temp_val=254; }

                  if (temp_val > 255)
                  {  temp_val=255; }
                  std::cout << "tempvaltotal"<< temp_val << std::endl;

                  if (static_cast<uint32_t>(temp_val) >new_max )
                  {   printf("NewMaxpix established:%s\n",temp_val);
                      new_max= static_cast<uint32_t>(temp_val);
                  }

                    //   printf("goingtoaddmix:\n");
                  std::vector<double>* ptr_temp_db_vec;
                  int at = (r*samp_log->img_width_colums)+c;
                                //  std::cout << "looking at:" <<at <<std::endl;
                  pix_fet_itr = pix_img_fetr_map.find(at);

                  if(pix_fet_itr != pix_img_fetr_map.end())
                  {        //              printf("addtomaplopfind:\n");
                   ptr_temp_db_vec = &pix_fet_itr->second;
                   ptr_temp_db_vec->push_back(temp_val);
                                        //  std::cout << "tempvalpushed back:"<<ptr_temp_db_vec->at(2) << std::endl;
                  }
                    else {printf("where is it goin! map out of range for mix_feturz\n");}
                  }}

               printf("endofMask_convloaded to Vector\n");
        break;

        case 3 :

        printf("sobelx:\n");
        std::cout << "image size to be vecotized in prtmapthing:" << img_inz->image_area_pix << std::endl;
        std::cout << "iwitdth: " << img_inz->img_width_colums  << " ihihgtz: " << img_inz->img_height_rows << std::endl;
        std::cout <<  "size of pixmapempty:" << pix_img_fetr_map.size() << std::endl;

          std::cout << "newimng size to be vecotized in prtmapthing:" << samp_log->image_area_pix << std::endl;
          std::cout << "logiwitdth: " << samp_log->img_width_colums  << " loihihgtz: " << samp_log->img_height_rows << std::endl;
          std::cout <<  "size of pixmapempty:" << pix_img_fetr_map.size() << std::endl;

       for (uint32_t r=1; r < img_inz->img_height_rows-1; r++)
       {
          //  printf("forloopfor row maskrun\n");
         for (uint32_t c =1; c< img_inz->img_width_colums-1; c++)
        {   //printf("forloopfor row colomz\n");
        //      std::cout << "c:" << c << " r:" << r << std::endl;
          double temp_val;
      //    std::cout << "val in orgialimg" << img_inz->b_imgArray[r-1].at(c-1) << "val afrer doublez:" << (double)img_inz->b_imgArray[r-1].at(c-1)<< std::endl;

          temp_val=(double)img_inz->b_imgArray[r-1].at(c-1);
            //       std::cout << "tempval1.1"<< temp_val << std::endl;
         temp_val  =temp_val *mask_data_sets.Sobel_x[0][0];
          //     std::cout << "tempval1.2"<< temp_val << std::endl;
         temp_val=+(((double)img_inz->b_imgArray[r-1].at(c))    *mask_data_sets.Sobel_x[0][1]);
        //  std::cout << "tempval2"<< temp_val << std::endl;
         temp_val=+  (((double)img_inz->b_imgArray[r-1].at(c+1))  *mask_data_sets.Sobel_x[0][2]);
         temp_val=+  (((double)img_inz->b_imgArray[r].at(c-1))  *mask_data_sets.Sobel_x[1][0]);
         temp_val=+    (((double)img_inz->b_imgArray[r].at(c))    *mask_data_sets.Sobel_x[1][1]);
         temp_val=+    (((double)img_inz->b_imgArray[r].at(c+1))  *mask_data_sets.Sobel_x[1][2]);
    //      std::cout << "tempvalmany"<< temp_val << std::endl;
         temp_val=+    (((double)img_inz->b_imgArray[r+1].at(c-1))    *mask_data_sets.Sobel_x[2][0]);
         temp_val=+    (((double)img_inz->b_imgArray[r+1].at(c))    *mask_data_sets.Sobel_x[2][1]);
         temp_val=+      (((double)img_inz->b_imgArray[r+1].at(c+1))  *mask_data_sets.Sobel_x[2][2]);
        //  std::cout << "tempvaltotal"<< temp_val << std::endl;

          if (temp_val < 0)
          {temp_val = temp_val*-1;}

          if (temp_val == 0)
          {
            temp_val=254;
          }
          if (static_cast<uint32_t>(temp_val) >new_max )
          {  // printf("NewMaxpix established:%s\n",temp_val);
              new_max= static_cast<uint32_t>(temp_val);
          }

            //   printf("goingtoaddmix:\n");
          std::vector<double>* ptr_temp_db_vec;
          int at = (r*samp_log->img_width_colums)+c;
                        //  std::cout << "looking at:" <<at <<std::endl;
          pix_fet_itr = pix_img_fetr_map.find(at);

          if(pix_fet_itr != pix_img_fetr_map.end())
          {        //              printf("addtomaplopfind:\n");
           ptr_temp_db_vec = &pix_fet_itr->second;
           ptr_temp_db_vec->push_back(temp_val);
                                //  std::cout << "tempvalpushed back:"<<ptr_temp_db_vec->at(2) << std::endl;
          }
            else {printf("where is it goin! map out of range for mix_feturz\n");}
          }}


       printf("endofMask_convloaded to Vector\n");
       break;

       case 4 :
       printf("sobely:\n");
       std::cout << "image size to be vecotized in prtmapthing:" << img_inz->image_area_pix << std::endl;
       std::cout << "iwitdth: " << img_inz->img_width_colums  << " ihihgtz: " << img_inz->img_height_rows << std::endl;
       std::cout <<  "size of pixmapempty:" << pix_img_fetr_map.size() << std::endl;

         std::cout << "newimng size to be vecotized in prtmapthing:" << samp_log->image_area_pix << std::endl;
         std::cout << "logiwitdth: " << samp_log->img_width_colums  << " loihihgtz: " << samp_log->img_height_rows << std::endl;
         std::cout <<  "size of pixmapempty:" << pix_img_fetr_map.size() << std::endl;

       for (uint32_t r=1; r < img_inz->img_height_rows-1; r++)
       {
            //printf("forloopfor row maskrun\n");
         for (uint32_t c =1; c< img_inz->img_width_colums-1; c++)
        {  // printf("forloopfor row colomz\n");
          // std::cout << "c:" << c << " r:" << r << std::endl;
          double temp_val;
         //std::cout << "val in orgialimg" << img_inz->b_imgArray[r-1].at(c-1) << "val afrer doublez:" << (double)img_inz->b_imgArray[r-1].at(c-1)<< std::endl;

          temp_val=(double)img_inz->b_imgArray[r-1].at(c-1);
            //       std::cout << "tempval1.1"<< temp_val << std::endl;
         temp_val  =temp_val *mask_data_sets.Sobel_y[0][0];
          //     std::cout << "tempval1.2"<< temp_val << std::endl;
         temp_val=+(((double)img_inz->b_imgArray[r-1].at(c))    *mask_data_sets.Sobel_y[0][1]);
        //  std::cout << "tempval2"<< temp_val << std::endl;
         temp_val=+  (((double)img_inz->b_imgArray[r-1].at(c+1))  *mask_data_sets.Sobel_y[0][2]);
         temp_val=+  (((double)img_inz->b_imgArray[r].at(c-1))  *mask_data_sets.Sobel_y[1][0]);
         temp_val=+    (((double)img_inz->b_imgArray[r].at(c))    *mask_data_sets.Sobel_y[1][1]);
         temp_val=+    (((double)img_inz->b_imgArray[r].at(c+1))  *mask_data_sets.Sobel_y[1][2]);
    //      std::cout << "tempvalmany"<< temp_val << std::endl;
         temp_val=+    (((double)img_inz->b_imgArray[r+1].at(c-1))    *mask_data_sets.Sobel_y[2][0]);
         temp_val=+    (((double)img_inz->b_imgArray[r+1].at(c))    *mask_data_sets.Sobel_y[2][1]);
         temp_val=+      (((double)img_inz->b_imgArray[r+1].at(c+1))  *mask_data_sets.Sobel_y[2][2]);
        std::cout << "tempvaltotal"<< temp_val << std::endl; //AHHH!

          if (temp_val < 0)
          { printf("nonegiveibvertz\n");
            temp_val = temp_val*-1;}

            if (temp_val == 0)
            { printf("nonegiveibvertz\n");
              temp_val = 255;}

          if (static_cast<uint32_t>(temp_val) >new_max )
          {   printf("NewMaxpix established:%s\n",temp_val);
              new_max= static_cast<uint32_t>(temp_val);
          }

            // printf("goingtoaddmix:\n");
          std::vector<double>* ptr_temp_db_vec;
          int at = (r*samp_log->img_width_colums)+c;
                //      std::cout << "looking at:" <<at <<std::endl;
          pix_fet_itr = pix_img_fetr_map.find(at);

          if(pix_fet_itr != pix_img_fetr_map.end())
          {        //              printf("addtomaplopfind:\n");
           ptr_temp_db_vec = &pix_fet_itr->second;
           ptr_temp_db_vec->push_back(temp_val);
                                //  std::cout << "tempvalpushed back:"<<ptr_temp_db_vec->at(2) << std::endl;
          }
            else {printf("where is it goin! map out of range for mix_feturz\n");}
          }}


            case 5:
            printf("laplace_outer:\n");
            std::cout << "image size to be vecotized in prtmapthing:" << img_inz->image_area_pix << std::endl;
            std::cout << "iwitdth: " << img_inz->img_width_colums  << " ihihgtz: " << img_inz->img_height_rows << std::endl;
            std::cout <<  "size of pixmapempty:" << pix_img_fetr_map.size() << std::endl;

              std::cout << "newimng size to be vecotized in prtmapthing:" << samp_log->image_area_pix << std::endl;
              std::cout << "logiwitdth: " << samp_log->img_width_colums  << " loihihgtz: " << samp_log->img_height_rows << std::endl;
              std::cout <<  "size of pixmapempty:" << pix_img_fetr_map.size() << std::endl;

           for (uint32_t r=1; r < img_inz->img_height_rows-1; r++)
           {
              //  printf("forloopfor row maskrun\n");
             for (uint32_t c =1; c< img_inz->img_width_colums-1; c++)
            {   //printf("forloopfor row colomz\n");
            //      std::cout << "c:" << c << " r:" << r << std::endl;
              double temp_val;
          //    std::cout << "val in orgialimg" << img_inz->b_imgArray[r-1].at(c-1) << "val afrer doublez:" << (double)img_inz->b_imgArray[r-1].at(c-1)<< std::endl;

              temp_val=(double)img_inz->b_imgArray[r-1].at(c-1);
                //       std::cout << "tempval1.1"<< temp_val << std::endl;
             temp_val  =temp_val *mask_data_sets.Sobel_x[0][0];
              //     std::cout << "tempval1.2"<< temp_val << std::endl;
             temp_val=+(((double)img_inz->b_imgArray[r-1].at(c))    *mask_data_sets.Laplacian_outer[0][1]);
            //  std::cout << "tempval2"<< temp_val << std::endl;
             temp_val=+  (((double)img_inz->b_imgArray[r-1].at(c+1))  *mask_data_sets.Laplacian_outer[0][2]);
             temp_val=+  (((double)img_inz->b_imgArray[r].at(c-1))  *mask_data_sets.Laplacian_outer[1][0]);
             temp_val=+    (((double)img_inz->b_imgArray[r].at(c))    *mask_data_sets.Laplacian_outer[1][1]);
             temp_val=+    (((double)img_inz->b_imgArray[r].at(c+1))  *mask_data_sets.Laplacian_outer[1][2]);
        //      std::cout << "tempvalmany"<< temp_val << std::endl;
             temp_val=+    (((double)img_inz->b_imgArray[r+1].at(c-1))    *mask_data_sets.Laplacian_outer[2][0]);
             temp_val=+    (((double)img_inz->b_imgArray[r+1].at(c))    *mask_data_sets.Laplacian_outer[2][1]);
             temp_val=+      (((double)img_inz->b_imgArray[r+1].at(c+1))  *mask_data_sets.Laplacian_outer[2][2]);
            //  std::cout << "tempvaltotal"<< temp_val << std::endl;
            temp_val = temp_val/6;
              if (temp_val < 0)
              {temp_val = temp_val*-1;}


              if (temp_val == 0)
              {temp_val = 254;}

              if (static_cast<uint32_t>(temp_val) >new_max )
              {  // printf("NewMaxpix established:%s\n",temp_val);
                  new_max= static_cast<uint32_t>(temp_val);
              }

                //   printf("goingtoaddmix:\n");
              std::vector<double>* ptr_temp_db_vec;
              int at = (r*samp_log->img_width_colums)+c;
                            //  std::cout << "looking at:" <<at <<std::endl;
              pix_fet_itr = pix_img_fetr_map.find(at);

              if(pix_fet_itr != pix_img_fetr_map.end())
              {        //              printf("addtomaplopfind:\n");
               ptr_temp_db_vec = &pix_fet_itr->second;
               ptr_temp_db_vec->push_back(temp_val);
                                    //  std::cout << "tempvalpushed back:"<<ptr_temp_db_vec->at(2) << std::endl;
              }
                else {printf("where is it goin! map out of range for mix_feturz\n");}
              }}


           printf("endofMask_convloaded to Vector\n");
           break;

           case 6:
           printf("laplace_outer:\n");
           std::cout << "image size to be vecotized in prtmapthing:" << img_inz->image_area_pix << std::endl;
           std::cout << "iwitdth: " << img_inz->img_width_colums  << " ihihgtz: " << img_inz->img_height_rows << std::endl;
           std::cout <<  "size of pixmapempty:" << pix_img_fetr_map.size() << std::endl;

             std::cout << "newimng size to be vecotized in prtmapthing:" << samp_log->image_area_pix << std::endl;
             std::cout << "logiwitdth: " << samp_log->img_width_colums  << " loihihgtz: " << samp_log->img_height_rows << std::endl;
             std::cout <<  "size of pixmapempty:" << pix_img_fetr_map.size() << std::endl;

          for (uint32_t r=1; r < img_inz->img_height_rows-1; r++)
          {
             //  printf("forloopfor row maskrun\n");
            for (uint32_t c =1; c< img_inz->img_width_colums-1; c++)
           {   //printf("forloopfor row colomz\n");
           //      std::cout << "c:" << c << " r:" << r << std::endl;
             double temp_val;
         //    std::cout << "val in orgialimg" << img_inz->b_imgArray[r-1].at(c-1) << "val afrer doublez:" << (double)img_inz->b_imgArray[r-1].at(c-1)<< std::endl;

             temp_val=(double)img_inz->b_imgArray[r-1].at(c-1);
               //       std::cout << "tempval1.1"<< temp_val << std::endl;
            temp_val  =temp_val *mask_data_sets.Sobel_x[0][0];
             //     std::cout << "tempval1.2"<< temp_val << std::endl;
            temp_val=+(((double)img_inz->b_imgArray[r-1].at(c))    *mask_data_sets.Laplacian_inter[0][1]);
           //  std::cout << "tempval2"<< temp_val << std::endl;
            temp_val=+  (((double)img_inz->b_imgArray[r-1].at(c+1))  *mask_data_sets.Laplacian_inter[0][2]);
            temp_val=+  (((double)img_inz->b_imgArray[r].at(c-1))  *mask_data_sets.Laplacian_inter[1][0]);
            temp_val=+    (((double)img_inz->b_imgArray[r].at(c))    *mask_data_sets.Laplacian_inter[1][1]);
            temp_val=+    (((double)img_inz->b_imgArray[r].at(c+1))  *mask_data_sets.Laplacian_inter[1][2]);
       //      std::cout << "tempvalmany"<< temp_val << std::endl;
            temp_val=+    (((double)img_inz->b_imgArray[r+1].at(c-1))    *mask_data_sets.Laplacian_inter[2][0]);
            temp_val=+    (((double)img_inz->b_imgArray[r+1].at(c))    *mask_data_sets.Laplacian_inter[2][1]);
            temp_val=+      (((double)img_inz->b_imgArray[r+1].at(c+1))  *mask_data_sets.Laplacian_inter[2][2]);
           //  std::cout << "tempvaltotal"<< temp_val << std::endl;
           temp_val = temp_val/6;
             if (temp_val < 0)
             {temp_val = temp_val*-1;}
             if (static_cast<uint32_t>(temp_val) >new_max )
             {  // printf("NewMaxpix established:%s\n",temp_val);
                 new_max= static_cast<uint32_t>(temp_val);
             }

               //   printf("goingtoaddmix:\n");
             std::vector<double>* ptr_temp_db_vec;
             int at = (r*samp_log->img_width_colums)+c;
                           //  std::cout << "looking at:" <<at <<std::endl;
             pix_fet_itr = pix_img_fetr_map.find(at);

             if(pix_fet_itr != pix_img_fetr_map.end())
             {        //              printf("addtomaplopfind:\n");
              ptr_temp_db_vec = &pix_fet_itr->second;
              ptr_temp_db_vec->push_back(temp_val);
                                   //  std::cout << "tempvalpushed back:"<<ptr_temp_db_vec->at(2) << std::endl;
             }
               else {printf("where is it goin! map out of range for mix_feturz\n");}
             }}


          printf("endofMask_convloaded to Vector\n");
          break;

        default :
        printf("deufklz\n");
      }

      samp_log->maxPixelValue =  new_max;

      //for (int k =0; k<img_inz->image_area_pix; k++ )
     //  {
      //  std::vector<double> vtemp;
     /*
          for (uint32_t i = 0; i < samp_log->img_height_rows; i++)
            { printf("isizelooptoload1\n");
               std::vector<uint32_t> tempvec;

               for (uint32_t j = 0; j < samp_log->img_width_colums; j++)
               {        printf("isizelooptoload2\n");
                        uint32_t tempvalz;
                        int at = (i*samp_log->img_width_colums)+j;
                        std::cout << "loc of stuff:" << at << std::endl;
                        tempvalz = static_cast<uint32_t>(img_inz->pix_fetur_dub_vec[at].at(2));

                }
                  samp_log->b_imgArray.push_back(tempvec);
              }
*/


  int maxloop;
       printf("->stemp_ptr_img_creationfor_feturmap:\n");
      for (pix_fet_itr = pix_img_fetr_map.begin(); pix_fet_itr !=pix_img_fetr_map.end() ||maxloop > samp_log->image_area_pix-1;)
        {
          maxloop++;
          std::vector<double>* vtemp;

            for (int i = 0; i < samp_log->img_height_rows; i++)
              {
                 std::vector<uint32_t> tempvec;

                 for (int j = 0; j < samp_log->img_width_colums; j++)
                 {
                        std::cout << "j:" << j << "i:" << i << "maxloo:" << maxloop << ":width:" << samp_log->img_height_rows << "hight:" << samp_log->img_width_colums << std::endl << "samp_log->image_area_pix" << samp_log->image_area_pix << std::endl;

                         uint32_t tempvalz;
                         vtemp =&pix_fet_itr->second;
                         tempvalz = static_cast<uint32_t>(vtemp->at(2));
                        //  std::cout << "atvtempwhyisrangz"<< vtemp->at(2)  << "tempval goin in" << tempvalz    << std::endl;

                      //   std::cout << "tempvalbing loaded:" << tempvalz << "the double it used:" << vtemp->at(2)<< std::endl;
                         tempvec.push_back(tempvalz);
                         pix_fet_itr++;
                  }
                    samp_log->b_imgArray.push_back(tempvec);
                }

              }// end of whole */
              printf("|newmapArraycompleate:\n");
            //for (int i = 0; i<3290; )
              img_toal++;
              img_prt_map.insert(std::pair<int,Image_PGM_P2*>(img_toal,samp_log));
            std::cout << "Newimagesaved on map at:" << img_toal << std::endl;

  }

   Image_PGM_P2* image_procczor_mrk_1022::return_img_from_map(int id_img)
   {
     img_map_itr = img_prt_map.find(id_img);
     if (img_map_itr != img_prt_map.end())
       {return(img_map_itr->second);}
       else { return nullptr;}

    }

  /*
  void image_procczor_mrk_1022::hisagramcal_(Image_PGM_P2* img_inz, int mode)
  {
    int histagram_binz;
    Histagramz temphista;

    uint32_t min;
    uint32_t max;
    int step;

    printf("Histagram Procuzer activated\n");

      switch (mode)
      {
        case 0 :
          {   printf("insiz some histbaiscz \n");

              histagram_binz =2;
              step =255/histagram_binz;
              temphista.create_empty_hista(histagram_binz);

              for (int k = 0; k< histagram_binz; k++)
              {  for (int i = 0; i<img_inz->b_imgArray.size(); i++)
                  { for (uint32_t j = 0; j< img_inz->get_W_cs(); j++)
                    {
                      if ( img_inz->b_imgArray[i].at(j)<step*i && img_inz->b_imgArray[i].at(j) > step*(i-1))
                            {
                              temphista.insert_to_bin(k);
                            }
              }}}

        break;
          }

        case 1 :
        {
          printf("ef \n");
          histagram_binz = 255;
        break;
        }

        default :
        {
          printf("Defultmode Pleaze set bin number set 2-254:\n");
          std::cin >> histagram_binz;

          if(histagram_binz<3 && histagram_binz>255)
            {
              printf("error number not vaild exiting histagramgenrator\n");
         break;
            }

        }
      }//endswitch
    }

  */
  /*

    void image_procczor_mrk_1022::union_obj(uint32_t parent_label, uint32_t conect_laebl)
       {        printf("uncion_callz\n");

         std::vector<uint32_t>* prt_vec_parent;
         std::vector<uint32_t>* prt_vec_currnt;

         if ( (itor_pix_lib = lb_count_pair_pixloc.find(parent_label) ) != lb_count_pair_pixloc.end())
            {
              prt_vec_parent =  &itor_pix_lib->second;
            }

              if ( (itor_pix_lib = lb_count_pair_pixloc.find(conect_laebl) ) != lb_count_pair_pixloc.end())
                 {
                   prt_vec_currnt =  &itor_pix_lib->second;

                 }

              prt_vec_parent->at(0) =+prt_vec_currnt->at(0);

               for ( int i = 1; i < prt_vec_currnt->size()+1; i++)
                  {

                   prt_vec_parent->push_back(prt_vec_currnt->at(i));
                  }

          lb_count_pair_pixloc.erase(conect_laebl);
      }



      void image_procczor_mrk_1022::conected_comp_labler(Image_PGM_P2* scanab_img)
      {
        uint32_t current_label;
        uint32_t  next_label=1;
        uint32_t i,j;
                    //    int pix_par[2];
                      //    std::list<int[2]>* pix_cord_comp_num_prt;
       std::vector<uint32_t>* prt_vec_intpix;

       printf("begin_conected_componet_calcualtions\n");
       std::cout << "numbber of rows" << scanab_img->get_h_rs() << std::endl; //" "   << ;
        std::cout << "numbber of collomz" << scanab_img->get_W_cs() << std::endl; //

        for (i=1 ;  i< scanab_img->get_h_rs()-1; i++)
        { // printf("in_conetor1ndloop\n");

          // std::cout << "rows iz" << i;
          for (j =1; j < scanab_img->get_W_cs()-1;j++)
              {
                if (scanab_img->b_imgArray[i].at(j) !=0)
                  { // printf("in_the pixel is not nullz\n");

                    if ( j>1 && scanab_img->b_imgArray[i].at(j-1)!=0)
                       {  // printf("in_the pixel at j-1 is also not zero\n");

                        scanab_img->b_imgArray[i].at(j) = scanab_img->b_imgArray[i].at(j-1);

                          if ( (itor_pix_lib = lb_count_pair_pixloc.find(current_label) ) != lb_count_pair_pixloc.end())
                                  {
                                        prt_vec_intpix =  &itor_pix_lib->second;
                                  }

                        prt_vec_intpix->at(0)+1;
                        prt_vec_intpix->push_back(i);
                        prt_vec_intpix->push_back(j);

                      //  printf("New Pixel ADDED to existing row Compt\n");


                        }
                  //      printf("parta_1");
                    if (i>2 && scanab_img->b_imgArray[i-1].at(j)!=0)
                       {

                        // printf("in_the pixel at i-i is also not zero\n");
                        scanab_img->b_imgArray[i].at(j) = scanab_img->b_imgArray[i-1].at(j);
                        current_label = scanab_img->b_imgArray[i-1].at(j);

                          if ((itor_pix_lib = lb_count_pair_pixloc.find(current_label))!=lb_count_pair_pixloc.end())
                                {
                                      prt_vec_intpix =  &itor_pix_lib->second;
                                }

                          prt_vec_intpix->at(0)+1;
                          prt_vec_intpix->push_back(i);
                          prt_vec_intpix->push_back(j);

                        // printf("New Pixel ADDED to upperrow! Compt\n");


                         if(j>1 && scanab_img->b_imgArray[i].at(j-1)!=0  && scanab_img->b_imgArray[i].at(j-1) != current_label )
                         {
                              printf("compolexz pixel at j-1 looping fbakz\n");

                           int k=0;
                           while (j-k!=0 &&scanab_img->b_imgArray[i].at(j-k)!=0)
                             { printf("stuff about unionz\n");
                             union_obj(current_label, scanab_img->b_imgArray[i].at(j-k));
                             k++;

                           //
                           //prt_vec_intpix->push_back(i);
                      //     prt_vec_intpix->push_back(k);
                    //       prt_vec_intpix->at(0)+1;
                             // compute the new pixel array!
                           }

                        }
                    //      printf("parta_2");
                      }//end if i is a componz

                    //    printf("parta_3\n");

                      if ( j == 1 && scanab_img->b_imgArray[i-1].at(j) ==0 ||
                           j>1 && scanab_img->b_imgArray[i].at(j-1) ==0 &&
                           scanab_img->b_imgArray[i-1].at(j) ==0)
                      {
                           printf("compolexz pixel all around zeroz fbakz\n");
                            scanab_img->b_imgArray[i].at(j) = next_label;


                        std::vector<uint32_t> temp_inp_new_comp_vec;

                        temp_inp_new_comp_vec.push_back(1);
                        temp_inp_new_comp_vec.push_back(i);
                        temp_inp_new_comp_vec.push_back(j);

                        lb_count_pair_pixloc.insert(std::make_pair(next_label, temp_inp_new_comp_vec));

                          current_label = next_label;
                          next_label++;
                          printf("New temP-comp!created_temp to upperrow! Compt\n");

                                  std::cout << "currntlabel" << current_label << std::endl;
                          }

                        if (next_label ==1 && i ==1 && j ==1 && scanab_img->b_imgArray[i].at(j) !=0 )
                          {
                                printf("1st! compontz-comp!created_temp to upperrow! Compt\n");

                                scanab_img->b_imgArray[i].at(j) = next_label;

                            std::vector<uint32_t> temp_inp_new_comp_vec;

                            temp_inp_new_comp_vec.push_back(1);
                            temp_inp_new_comp_vec.push_back(i);
                            temp_inp_new_comp_vec.push_back(j);

                            lb_count_pair_pixloc.insert(std::make_pair(next_label, temp_inp_new_comp_vec));

                              current_label = next_label;
                              next_label++;

                            }

                      }

                    }}//two for loops.
                    std::cout <<"number of temp labelz:" <<next_label<<  std::endl;
                    printf("image_compnitzed in Vectorz\n");
                  }



                  Image_PGM_P2*  image_procczor_mrk_1022::thresholdImg( Image_PGM_P2* img_to_th)
                    {

                      printf(" Running_threadholding_ imagprocessor \n" );
                      uint32_t r, c;
                      uint32_t threshold;
                    //  int **image_tmp=NULL;
                      Image_PGM_P2* temp_iimg = new Image_PGM_P2();

                //        printf(" improz_01 \n" );
                      temp_iimg->img_height_rows =  img_to_th->img_height_rows;
                      temp_iimg-> img_width_colums= img_to_th->img_width_colums;
                      temp_iimg->maxPixelValue =    img_to_th->maxPixelValue;
                      temp_iimg->image_area_pix =   img_to_th->image_area_pix;

                    //  printf(" improz_02 \n" );

                      // threshold = calculate_threashold(img_to_th);
                      threshold = 120;
                    //   printf(" improz_03 \n" );

                        for(r=0;r<temp_iimg->img_height_rows+1; r++)
                        {   // printf(" loopouter1proz \n" );

                            std::vector<uint32_t> temp_thresh_vec;

                          for(c=0;c<temp_iimg->img_width_colums+1; c++)
                            {
                            //  printf(" inloopouter2proz \n" );
                              if(img_to_th->b_imgArray[r].at(c) > threshold)
                              {  temp_thresh_vec.push_back(1);}

                             if(img_to_th->b_imgArray[r].at(c) < threshold)
                             { temp_thresh_vec.push_back(0);}
                         }

                          temp_iimg->b_imgArray.push_back(temp_thresh_vec);

                       }
                              printf("Threadolingcompleate returning pointer!\n");
                           return(temp_iimg);
                }

                */
