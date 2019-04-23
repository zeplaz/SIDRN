
// imagkjz_RGB.cpp

#include "imagkjz_RGB.h"

  void imagkjz_RGB::linilzatfeture_space()
  {
      int Pix_id;

      for(Pix_id=0; Pix_id<raw_img_rgb_vec.size(),Pix_id++)
      {
        image_realm::RGB_pix_intzity image_intcity_struc;
      //.image_intcity_struc.colour_rgb_Raw
        image_intcity_struc.img_colour_intisity_double[Pix_id]   = reinterpret_cast<double>(raw_img_rgb_vec.at(Pix_id));
        image_intcity_struc.img_colour_intisity_double[Pix_id+1] = reinterpret_cast<double>(raw_img_rgb_vec.at(Pix_id+1));
        image_intcity_struc.img_colour_intisity_double[Pix_id+2] = reinterpret_cast<double>(aw_img_rgb_vec.at(Pix_id+2));

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


    void imagkjz_RGB::load_image_RGB(std::istream& input_strm)
     {
        std::vector<std::uint8_t>* const pixel_raw_RGB  = &raw_img_rgb_vec;
                              //     ::size_t* const hy,
        auto img_header = read_header(input_strm);

        pixel_raw_RGB->resize((img_header.widthx)*(img_header.highty)*3);
        img_size = img_header.widthx*img_header.highty;
        imagkjz_RGB::read_pix_rgb_raw(input_strm,pixel_raw_RGB);

              //  *wx  =  ;
              //  *hy  =  img_header.highty;
        //        std::string file_name;
          //      std::string img_header;
            //  std::size_t* const wx,
      }
