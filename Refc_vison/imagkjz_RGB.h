


//img

#ifndef IMAGKJZ_H
#define IMAGKJZ_H

//libz
#include <iostream>
#include <fstream>
#include <cstdint>

  namespace image_realm {
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



         inline void write_head(std::ostream out_stream, img_header const& out_head)
         {

           out_stream << out_head.majic_numz << "\n"
                      << out_head.widthx << "\n"
                      << out_head.highty << "\n"
                      <<out_head.rgb_max_intity << "\n";
         }

         inline void write_raw_pix_data(std::ostream& out_strem,
                                        std::uint8_t const* const pix_raw_dat,
                                        std::size_t const size)
           {
             out_strem.write(reinterpret_cast<char const*>(pix_raw_dat),size);
           }



       inline  void read_pix_rgb_raw(std::istream& in_img_stream, std::vector<uint8_t>* const pixel_raw_RGB)
        {
         in_img_stream.read(reinterpret_cast<char*>(pixel_raw_RGB->data()), pixel_raw_RGB->size());

          if(!in_img_stream)
          {
           printf("!@ERROR::datainticity read falure\n");
          }
         }


      inline    void write_image(std::ostream& out_stream,std::size_t const x_with
                                  std::size_t const y_high, std::uint8_t const* const pixdata)
                                  {
                                    auto out_header = img_header{};
                                    out_header.majic_numz = "P6";
                                    out_header.widthx = x_with;
                                    out_header.highty = y_high;

                                    image_realm::write_head(out_stream,out_header);
                                    image_realm::write_raw_pix_data(out_stream,pixdata,out_header.x_with,out_header.y_high*3);
                                  }

};
}

#endif
