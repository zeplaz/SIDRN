


#include "image_procczor_mrk_1022.h"

//  Histagramz();

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
