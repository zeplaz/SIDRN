

//image_processor


//Pixel_1xbyte.h
#ifndef PIXELxbyte_H
#define PIXELxbyte_H

    class Pixel_1xbyte
    {

    private :
      uint8_t  _x, _y;
      uint8_t  off_zero = 0;
      uint8_t  _intensity_value;

    public :

      Pixel_1xbyte();
      virtual ~Pixel_1xbyte();
      Pixel_1xbyte(const Pixel_1xbyte& pix_1);

      uint8_t get_intensity() const;

      void set_intensity_value( uint8_t inzt);
      void set_loc (uint8_t x uint8_t y);

      void apply_intensity_scaler(const uint8_t& ref_cons_intensity, int scaler);


      friend std::ostream& operator<<(std::ostream& os, const Pixel& pix);
      friend std::istream& operator>>(std::istream& is, Pixel& pix);

    };

#endif



//

//GRAPHICIMG_1byte.h
#ifndef GRAPHICIMG_1byte_H
#define GRAPHICIMG_1byte_H


  class Graphic_img_shkalla_gri_1byte_d
  {
  protected:

  uint8_t _width, _hight,Max_size;

  Pixel_1xbyte** pix_ptr_array;


  public:

    Graphic_img_shkalla_gri_1byte_d();
    Graphic_img_shkalla_gri_1byte_d();
    Graphic_img_shkalla_gri_1byte_d(
                            const Graphic_img_shkalla_gri_1byte_d& gh_img);
    virtual ~Graphic_img_shkalla_gri_1byte_d();

    uint8_t get_width() const;
    uint8_t get_hight() const;
    Pixel_1xbyte** get_pix_ptr_array() const;

    void set_pixel(uint8_t i,uint8_t j,uint8_t intez);

    uint8_t at_intensity(uint8_t i , uint8_t j);

    void set_pix_array();

    void set_pix_array_frprt(Pixel_1xbyte**);



  };

#endif



//thresholder

class Thresholder()

{

}


evaluate_input_and_mask_ANDbit(uint8_t input_byte)
{
  if ((input_byte & Mask_on_1) !=0)

  {return true;}

  else
  {return false;}


}
/*class gph_image

{ protected :

public :

}*/

class image_processor()

{
//nabourhoodscanz

class 4N_mask()
{
/*North = 20 = 1
West = 21 = 2
East = 22 = 4
South = 23 = 8*/
uint8_t bitmask_0 = 0;
uint8_t Mask_on_1 = 1;

uint8_t input_bit = ;






uint8_t north4 =1;
uint8_t west4 =2;
uint8_t east4 =4;
uint8_t south4 =8;

uint64_t

};




n4_scan();
{





}

n4_scan();

};
