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

          int image_procczor_mrk_1001::calculate_threashold(image_Byte8* img_to_th)
        {
           uint8_t tempthrsh_cal = 200;
           printf("calcute threshold at200 \n");
           return (tempthrsh_cal);
        }


      image_Byte8*  image_procczor_mrk_1001::thresholdImg( image_Byte8* img_to_th)
        {

          printf(" Running_threadholding_ imagprocessor \n" );
          int r, c;
          int threshold;
        //  int **image_tmp=NULL;
          image_Byte8* temp_iimg = new image_Byte8();

            printf(" improz_01 \n" );
          temp_iimg->img_height_rows =  img_to_th->img_height_rows;
          temp_iimg-> img_width_colums= img_to_th->img_width_colums;
          temp_iimg->maxPixelValue =    img_to_th->maxPixelValue;
          temp_iimg->image_area_pix =   img_to_th->image_area_pix;

          printf(" improz_02 \n" );

           threshold = calculate_threashold(img_to_th);
           printf(" improz_03 \n" );

            for(r=0;r<temp_iimg->img_height_rows+1; r++)
            {   // printf(" loopouter1proz \n" );

              	std::vector<int> temp_thresh_vec;

              for(c=0;c<temp_iimg->img_width_colums+1; c++)
                {
                //  printf(" inloopouter2proz \n" );
                  if(img_to_th->b_imgArray[r].at(c) < threshold)
                  temp_thresh_vec.push_back(0);
                 else temp_thresh_vec.push_back(1);
             }
              temp_iimg->b_imgArray.push_back(temp_thresh_vec);

           }
                	printf("Threadolingcompleate returning pointer!\n");
               return(temp_iimg);
    }



    /*


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

    void image_procczor_mrk_1001::union_obj(int parent_label, int conect_laebl);
        {
          std::get<1>(cons_itor_pix_lib.find(parent_label)->second).merge(std::get<1>(cons_itor_pix_lib.find(conect_laebl)->second));

          std::get<0>(cons_itor_pix_lib.find(parent_label)->second)=+ std::get<0>(cons_itor_pix_lib.find(conect_laebl)->second);

          lb_count_pair_pixloc.erase(conect_laebl);
        }
    void image_procczor_mrk_1001::conected_comp_labler(image_Byte8* scanab_img);
    {
      uint8_t current_label;
      uint8_t  next_label=0;
      uint16_t i,j;
      int pix_par[2];
      std::list<int[2]>* pix_cord_comp_num_prt;

        for (i=0 ;  i< scanab_img->get_h_rs()+1; i++)
        {
          for (j =1; j < scanab_img->get_W_cs()+1;j++)
              {
                if (scanab_img->pixelz[i,j] !=0)
                  {
                      if ( j>1 && scanab_img->pixelz[i,j-1]!=0)
                      {
                        scanab_img->pixelz[i,j] = pixelz[i,j-1];
                      //  current_label = scanab_img->pixelz[i,j-1];

                        pix_par[1]=j;
                        pix_par[0]=i;

                        std::get<0>(cons_itor_pix.find(current_label)->second)=+1;

                        pix_cord_comp_num_prt = std::get<1>(cons_itor_pix_lib.find(current_label)->second);
                        pix_cord_comp_num_prt->push_back(pix_par);

                      }

                      if (i>1 && scanab_img->pixelz[i-1,j]!=0)
                      {
                        scanab_img->pixelz[i,j] = pixelz[i-1,j];
                        current_label = scanab_img->pixelz[i-1,j];

                        pix_par[1]=j;
                        pix_par[0]=i;

                        std::get<0>(cons_itor_pix.find(current_label)->second)=+1;

                        pix_cord_comp_num_prt = std::get<1>(cons_itor_pix.find(current_label)->second);
                        pix_cord_comp_num_prt->push_back(pix_par);

                          if(scanab_img->pixelz[i,j-1]!=0)
                          {
                            union_obj(current_label,scanab_img->pixelz[i,j-1]);
                          }
                      }

                      if (scanab_img->pixelz[i,j-1] ==0 && scanab_img->pixelz[i-1,j] ==0)
                      {

                        scanab_img->pixelz[i,j] = next_label;
                        pix_par[1]=j;
                        pix_par[0]=i;

                        std::list<int[2]>* temPrt_new_pixloc = new  std::list<int[2]>(pix_par);

                        std::make_pair(1,temPrt_new_pixloc) in_par_necon;

                        lb_count_pair_pixloc.insert(next_label,in_par_necon);
                        current_label = next_label;
                        next_label++;
                      }

                    }}}

  // do object creation of vaild objctz



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
