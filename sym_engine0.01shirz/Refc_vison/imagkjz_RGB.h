


//img

#ifndef IMAGKJZ_H
#define IMAGKJZ_H

//libz
#include <iostream>
#include <fstream>
#include <cstdint>
#include <vector>
#include <unordered_map>


#include "RGB_pix_intzity.h"

  namespace image_realm {
//strucz? move to include?


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
      RGB_pix_intzity* locat_pixel_fet_data(int id_pixloc);


      inline img_header read_header(std::istream& instream)
        {
          auto i_header = img_header{};
          instream >> i_header.majic_numz >> i_header.widthx >> i_header.highty >>  i_header.rgb_max_intity;
          instream.ignore(256, '\n');
          return i_header;
         }

      inline void write_head(std::ostream out_stream, img_header const& out_head)
         {
           out_stream << out_head.majic_numz << "\n"
                      << out_head.widthx << "\n"
                      << out_head.highty << "\n"
                      <<out_head.rgb_max_intity << "\n";
         }

       inline  void read_pix_rgb_raw(std::istream& in_img_stream,
                                     std::vector<std::uint8_t>* const con_raw_pix_prt)
         {
           //std::vector<std::uint8_t>* const con_raw_pix_prt =&raw_img_rgb_vec;
            in_img_stream.read(reinterpret_cast<char*>(con_raw_pix_prt->data()), con_raw_pix_prt->size());

            if(!in_img_stream)
            {
              printf("!@ERROR::datainticity read falure\n");
              std::cout <<con_raw_pix_prt->size();
            }
          }

        inline void write_raw_pix_data(std::ostream& out_strem,std::uint8_t const* const raw_pixdata, std::size_t const size)
          {
              out_strem.write(reinterpret_cast<char const*>(raw_pixdata),size);
          }

         inline void write_image(std::ostream& out_stream)
           {
               std::uint8_t const* const pixdata = raw_img_rgb_vec.data();

               auto out_header = img_header{};
               out_header.majic_numz = "P6";
               out_header.widthx = img_header.widthx;
               out_header.highty = img_header.highty;

              image_realm::imagkjz_RGB::write_head(out_stream,out_header);
              image_realm::imagkjz_RGB::write_raw_pix_data(out_stream,pixdata,
                 out_header.widthx, out_header.highty*3);
            }

};
}

#endif
