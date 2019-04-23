//image_procczor_mrk_1001.cpp

//#include "Objkfactory.h"
      //#include "img_obkj.h"

/*
      void image_procczor_mrk_1001::apply_erode(image_Byte8* inimg)

      {


      }

      void image_procczor_mrk_1001::apply_dilate(image_Byte8* inimg)

      {

      }

    void image_procczor_mrk_1001::open_morph(image_Byte8* inimg)
        {
            apply_dilate(inimg);
            apply_erode(inimg);

        }

    void image_procczor_mrk_1001::close_morph(mage_Byte8* inimg)
        {
          apply_erode(inimg);
          apply_dilate(inimg);

        }



*/



#include "image_procczor_mrk_1001.h"

          


      image_Byte8*  image_procczor_mrk_1001::thresholdImg( image_Byte8* img_to_th)
        {

          printf(" Running_threadholding_ imagprocessor \n" );
          int r, c;
          int threshold;
        //  int **image_tmp=NULL;
          image_Byte8* temp_iimg = new image_Byte8();

    //        printf(" improz_01 \n" );
          temp_iimg->img_height_rows =  img_to_th->img_height_rows;
          temp_iimg-> img_width_colums= img_to_th->img_width_colums;
          temp_iimg->maxPixelValue =    img_to_th->maxPixelValue;
          temp_iimg->image_area_pix =   img_to_th->image_area_pix;

        //  printf(" improz_02 \n" );

           threshold = calculate_threashold(img_to_th);
        //   printf(" improz_03 \n" );

            for(r=0;r<temp_iimg->img_height_rows+1; r++)
            {   // printf(" loopouter1proz \n" );

              	std::vector<int> temp_thresh_vec;

              for(c=0;c<temp_iimg->img_width_colums+1; c++)
                {
                //  printf(" inloopouter2proz \n" );
                  if(img_to_th->b_imgArray[r].at(c) > threshold)
                  {  temp_thresh_vec.push_back(-1);}

                 if(img_to_th->b_imgArray[r].at(c) < threshold)
                 { temp_thresh_vec.push_back(0);}
             }

              temp_iimg->b_imgArray.push_back(temp_thresh_vec);

           }
                	printf("Threadolingcompleate returning pointer!\n");
               return(temp_iimg);
    }



      void image_procczor_mrk_1001::union_obj(int parent_label, int conect_laebl)
         {        printf("uncion_callz\n");

           std::vector<int>* prt_vec_parent;
           std::vector<int>* prt_vec_currnt;

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




        void image_procczor_mrk_1001::conected_comp_labler(image_Byte8* scanab_img)
        {
          int current_label;
          int  next_label=1;
          int i,j;
                      //    int pix_par[2];
                        //    std::list<int[2]>* pix_cord_comp_num_prt;
         std::vector<int>* prt_vec_intpix;

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


                            std::vector<int> temp_inp_new_comp_vec;

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

                                std::vector<int> temp_inp_new_comp_vec;

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


    //  void Object_creator()
  //    {
    //     for (cons_itor_pix_lib = lb_count_pair_pixloc.begin(); cons_itor_pix_lib !=lb_count_pair_pixloc.end(); cons_itor_pix_lib++)
    //     {

        //          cons_itor_pix_lib->second;

    //     }
  //    }




                        //  cons_itor_pix_lib.find(current_label->second);

                          //  pix_cord_comp_num_prt = std::get<1>(;
                          //  pix_cord_comp_num_prt->push_back(pix_par);

                          //  current_label = scanab_img->pixelz[i,j-1];

                        //    pix_par[1]=j;
                        //    pix_par[0]=i;
                          //  else {printf("error,inlabelr_cannotfindlabeldata\n"); break;}
                            //std::get<0>()=+1;


                                                           //    else {printf("error,inlabelr_cannotfindlabeldata\n"); break;}
                                                           //  pix_par[1]=j;
                                                         //    pix_par[0]=i;

                                                           //  std::get<0>(cons_itor_pix_lib.find(current_label)->second)=+1;

                                                           //  std::pair<int,std::list<int[2]>*>* prt_temppare;

                                                       //    prt_temppare*  =  std::get<1>(cons_itor_pix_lib.find(current_label);

                                                       //    pix_cord_comp_num_prt = prt_temppare->second);

                                                             //pix_cord_comp_num_prt->push_back(pix_par);
                                                             //  pix_par[1]=j;
                                                           //    pix_par[0]=i;

                                                           //    std::list<int[2]>* temPrt_new_pixloc = new std::list<int[2]>(pix_par);
                                                               //lb_count_pair_pixloc.insert(next_label,std::make_pair(1, temPrt_new_pixloc));



      // do object creation of vaild objctz

    /*



            //  std::get<1>(cons_itor_pix_lib.find(parent_label)->second).merge(std::get<1>(cons_itor_pix_lib.find(conect_laebl)->second));

            //  std::get<0>(cons_itor_pix_lib.find(parent_label)->second)=+ std::get<0>(cons_itor_pix_lib.find(conect_laebl)->second);

    void image_procczor_mrk_1001::cal_centriod(img_obkj* scn_obj_cer)
    {
      int centroid_r;
      int centroid_c;
      int r_sum;
      int  c_sum;
      map<int, int[2]> list_par_obj;
        list_par_obj::const_iterator cons_itor;

      for (cons_itor.begin(); cons_itor.end();cons_itor++)
      {
      int[2] tempintarray;
      tempintarray = cons_itor->second;
      r_sum  =+ tempintarray[0];
      c_sum  =+ tempintarray[0];

      }
      centroid_r  = r_sum/cons_itor->first;
      centroid_c =  r_sum/cons_itor->first;

      scn_obj_cer->img_objk_prop.centrod[0]=centroid_r;
      scn_obj_cer->img_objk_prop.centrod[0]=centroid_c;

    }






                    //    =2*(std::cos(thad))
                // std::vector<int[2]> parent_label_array;

  //    std::unordered_map<vertex_type,std::unordered_set<vertex_type>>,

                      lb_count_pair_pixloc.insert()
                        buffer {

                          std::make_pair(current_label,)

                      for ( p =0; p< pix_cord_comp_num_vec.size()+1; p++ )
                        {
                        }
                  }
                    r_cpar_map_lb.insert(std::make_pair(current_label,pix_par);
                    }

                    if  (scanab_img->pixelz[i,j-1] !=0)
                    {

                      scanab_img->pixelz[i,j] = pixelz[i,j-1];
                      current_label = pixelz[i,j-1];

                      pix_par[1]=j;
                      pix_par[0]=i;

                      r_cpar_map_lb.insert(std::make_pair(current_label,pix_par);

                    }

                      scanab_img->pixelz[i,j]    =  current_label;

                       r_cpar_map_lb.insert(std::make_pair(current_label,pix_par);             }


                      next_label--;

                  temp_onjc  = img_obj_fac.create_img_obk(next_label);
                    ojk_labl_mapinst.insert(std::make_pair(next_label,pix_par);

                    }

                  }
                  img_obkj
              for ()
               {
               }

        }

    }






    void image_procczor_mrk_1001::cal_perimeter(img_obkj* in_objk)
    {



      in_objk->img_objk_prop.perimeter =
    }

    void image_procczor_mrk_1001::circularity(img_obkj* in_objk)
    {

      in_objk->img_objk_prop.circularity = (in_objk->perimeter * in_objk->perimeter) / (4 * PI * in_objk->img_objk_prop.Arra_size);

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




    /*/
