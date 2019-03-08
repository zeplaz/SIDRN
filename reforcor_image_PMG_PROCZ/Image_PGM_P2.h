
#ifndef Image_PGM_P2_H
#define Image_PGM_P2_H


//clibs
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>
#include <istream>


//sfml libs

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
//sorcelibs

#include "vrt_image.h"



  class Image_PGM_P2: public vrt_image
  {
    private :
       int _image_ID;
       static int s_Next_vaild_ID;

       void set_id();

       std::string user_input_img_name;

    public :


        Image_PGM_P2(){};

        int rtn_img_id()const
        {return _image_ID;}

      ~Image_PGM_P2(){};
       virtual  void  Image_Procees_inlizar(std::ifstream& in_img);
       virtual void update();
       virtual  void write_image(std::ofstream& out_img);

       std::vector<std::vector<uint32_t>> b_imgArray;

       uint32_t get_h_rs()
       {return img_height_rows;}

       uint32_t get_W_cs()
       {return img_width_colums;}

        int get_MaxPixVal()
       {return maxPixelValue;}

 protected:
  // uint8_t readbytechar = ' ';
   uint32_t img_height_rows;
   uint32_t img_width_colums;

   uint32_t maxPixelValue;
   uint32_t  image_area_pix;


       //sfml display objects
       sf::Texture     sf_image_texture_obj;        // the texture which will contain our pixel data
       sf::Sprite      sf_image_texture_sprite_obj;         // the sprite which will actually draw it
      //void  sf_loadImage_for_display(const char* pathname, sf::Texture& img_textur, sf::Sprite& img_sprite);





  };

  #endif

  /*
  void loadImage(const char* pathname, sf::Texture& texture, sf::Sprite& sprite)
  {
      texture.loadFromFile(pathname);     // load it from the file
      sprite.setTexture(texture);         // put that texture in our sprite
      sprite.setTextureRect( sf::IntRect(0,0,screenSize_X,screenSize_Y) );    // the rectangle of the texture to use for this sprite
}
*/
