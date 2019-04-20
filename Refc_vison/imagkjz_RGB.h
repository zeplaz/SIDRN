



//img

#ifndef IMAGKJZ_H
#define IMAGKJZ_H

//libz
#include <iostream>
#include <fstream>
#include <cstdint>


//strucz? move to include?
    typedef struct {
      double img_colour_intisity_double[3];
      uint16_t colour_rgb_Raw[3];
    } RGB_pix_intzity;


class  imagkjz_RGB{

    public :
     size_t img_size;
     std::vector<uint8_t> raw_img_rgb_vec;

    //loacl header imag struc
     struct img_header {
      std::string majic_numz ="";
      std::size_t  widthx=0;
      std::size_t  highty=0;
      std::uint32_t  rgb_max_intity = 255;};

    //mapstuff for feture locations
      std::unordered_map<int,RGB_pix_intzity> img_RGB_intzty_map;
      std::unordered_map<int,RGB_pix_intzity>::iterator incity_map_iter;




    public:
      void load_image_RGB();
      void inilzatfeture_space();

      image_intcity_struc*  locat_pixel_fet_data(int id_pixloc);


      inline img_header read_header(std::istream& instream)
         {
          auto i_header = img_header{};
          instream >> i_header.majic_numz >> i_header.widthx >> i_header.highty >>  i_header.rgb_max_intity;
          instream.ignore(256, '\n');

          return header;
         }

       inline  void read_pix_rgb_raw(std::istream& in_img_stream, std::vector<uint8_t>* const pixel_raw_RGB)
        {
         in_img_stream.read(reinterpret_cast<char*>(pixel_raw_RGB->data()), pixel_raw_RGB->size());

          if(!in_img_stream)
          {
           printf("!@ERROR::datainticity read falure\n");
          }
         }
};

#endif

// imagjka.cpp.

#include "imagkjz_RGB.h"

  void imagkjz_RGB::linilzatfeture_space()
  {
      int Pix_id;

      for(Pix_id=0; Pix_id<raw_img_rgb_vec.size(),Pix_id++)
      {
        RGB_pix_intzity image_intcity_struc;
      //.image_intcity_struc.colour_rgb_Raw
        image_intcity_struc.img_colour_intisity_double[Pix_id]  = reinterpret_cast<double>(raw_img_rgb_vec.at(Pix_id));
        image_intcity_struc.img_colour_intisity_double[Pix_id+1]= reinterpret_cast<double>(raw_img_rgb_vec.at(Pix_id+1));
        image_intcity_struc.img_colour_intisity_double[Pix_id+2]= reinterpret_cast<double>(aw_img_rgb_vec.at(Pix_id+2));

        img_RGB_intzty_map.insert(Pix_id,image_intcity_struc);
      }
      //reinterpret_cast<uint16_t>
   }

  image_intcity_struc* imagkjz_RGB::locat_pixel_fet_data(int id_pixloc)
   {
      incity_map_iter = img_RGB_intzty_map.find(id_pixloc);

    if(img_RGB_intzty_map.end())
     {
      printf("||_NOTFOUND_DATA_ORPIXEL UKNOWN>\n");
      return nullptr;
     }

     else {
         return (*incity_map_iter.second);
     }
   }



void imagkjz_RGB::load_image_RGB(std::istream& input_strm,
                                std::vector<std::uint8_t>* const pixel_raw_RGB)
                              //  std::size_t* const wx,
                              //     ::size_t* const hy,
    {
        auto img_header = read_header(input_strm);

      //  *wx  =  ;
      //  *hy  =  img_header.highty;

//        std::string file_name;
  //      std::string img_header;

        pixel_raw_RGB->resize((img_header.widthx)*(img_header.highty)*3);

        read_pix_rgb_raw(input_strm,pixel_raw_RGB);


      }


/*



    std::fstream in_fstream;

    uint8_t input_byte;

    std::cout << "\n |/>|Please Input fileName to Load: VAILD PPM RGB byteplz:\n";
    std::cin >> file_name;

    in_fstream.open(file_name, std::ios_base::in | std::ios_base::binary);

    if (in_fstream.is_open())
      {
      in_fstream>> img_header;

         if (strcmp(header.c_str(), "P6") != 0)
          {
            printf("ERROR:NOT P6\n");
          }

        in_fstream >> widthx;
        in_fstream >> highty;
        in_fstream >>rgb_max_intity;

        img_size = widthx*highty*3;

          while(!in_fstream.eof())
          in_fstream.read((char*)   )
        }
      }



      std::istream& operator >>(std::istream &inputStream, imagkjz_RGB &other)
      {

      }


      */
