



//sorcelibs
#include "Image_PGM_P2.h"


       void Image_PGM_P2::set_id()
       {
         printf("latr\n");
       }

         void  Image_PGM_P2::Image_Procees_inlizar(std::ifstream& in_img)
       {
          std::string linez;

          std::string tempdimetion[2];

          printf("please Enter file image Name:\n");

  				std::cin >> user_input_img_name;

  				in_img.open(user_input_img_name.c_str(), std::ifstream::in);

  				printf("ImageOPen\n");


          if (in_img)
          {
            std::getline(in_img, linez);

            if(linez == "P2")
              { printf("vaild p2 file found!\n");

                 getline(in_img, linez);

                 while (linez.at(0) == '#')
                  {
			              std::getline(in_img, linez);
                  }

                  std::stringstream string_imgstrm(linez);
                           
                 int d=0;
                 while (string_imgstrm && d<2)
                  {
                    string_imgstrm  >>  tempdimetion[d];
                    d++;
                  }

                  img_height_rows =std::strtoul(tempdimetion[1].c_str(),NULL,0);
                  img_width_colums= std::strtoul(tempdimetion[0].c_str(),NULL,0);
                  image_area_pix = img_width_colums*img_height_rows;
                  std::cout << "image area: " << image_area_pix <<std::endl;

                  getline(in_img, linez);

                  maxPixelValue = strtoul(linez.c_str(),NULL,0);//String to int conversion

               std::cout << "The grayscale range for this image is 0 to " << maxPixelValue << "." << std::endl;

          //Store numbers into the 2D int array
                for (uint32_t i = 0; i < img_height_rows; i++)
                {   std::vector<uint32_t> tempvec;
                   for (uint32_t j = 0; j < img_width_colums; j++)
                   {
                      in_img >> std::ws;//Extracts as many whitespace characters as possible from the current position in the input sequence.
                      std::getline(in_img, linez, ' ');
                      tempvec.push_back(strtoul(linez.c_str(),NULL,0));
                    }
                      b_imgArray.push_back(tempvec);
                  }

                }// end of ifvaild p2;
          in_img.close();
          printf("file is closed and hopefully loaded! int a image object for processing acess via the raw vec<vec_uint32> or processor effects and display optionz\n");
        }//end of fileread

 }


        void Image_PGM_P2::update()
       {
        printf("could be useful\n");

       }


         void Image_PGM_P2::write_image(std::ofstream& out_img)
       {
          std::string img_nam;
          printf("enter expotfilename:\n");

          std::cin >> img_nam;


         std::cout << "image being writen to file: " << img_nam << std::endl;

         out_img.open("output/"+ img_nam + "_outim.pgm",std::fstream::out);
         out_img << "P2" << std::endl;
         out_img << "#outimagefromprocessor P2ascIIpgm" << std::endl;
         out_img << std::to_string(img_width_colums)+ " "+  std::to_string(img_height_rows) << std::endl;
         out_img << std::to_string(maxPixelValue) << std::endl;


         for (uint32_t i =0; i<img_height_rows;  i++)
         {
         for (uint32_t j =0; j<img_width_colums; j++ )
         {
                  //b_imgArray[i].at(j);
             if (b_imgArray[i].at(j) < 0)
             {// edgepiblmz
    			       out_img << std::to_string(0) + " ";
             }

            else
              {
    			       out_img << std::to_string(b_imgArray[i].at(j)) + " ";
              }

            if (j >= 16)
            {//Tfixoutputinlinetext formate.
			        out_img << std::endl;
			      }

          } }// close scanloopz
          out_img.close();
          printf("image has been saved:\n");
              }

            //sfml display objects
/*
     void Image_PGM_P2::sf_loadImage_for_display(const char* pathname, sf::Texture& img_textur, sf::Sprite& img_sprite)
     {
         sf_image_texture_obj.loadFromFile(pathname);     // load it from the file
         img_sprite.setTexture(img_textur);         // put that texture in our sprite
         img_sprite.setTextureRect( sf::IntRect(0,0,screenSize_X,screenSize_Y) );    // the rectangle of the texture to use for this sprite
   }*/
