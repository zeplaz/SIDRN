//Pixel_1xbyte.cpp

#include <iostream>
#include "Pixel_1xbyte.h"
    Pixel_1xbyte::Pixel_1xbyte(){}
    Pixel_1xbyte::~Pixel_1xbyte(){}

    Pixel_1xbyte::(const Pixel_1xbyte& pix)
    {
      _x=pix._x;
      _y=pix._y;
      _intensity_value = pix._intensity_value;
    }

    uint8_t Pixel_1xbyte::get_intensity() const
        {return _intensity_value;}

    void  Pixel_1xbyte::set_intensity_value( uint8_t inzt)
    {
      _intensity_value = inzt;
    }

    void Pixel_1xbyte::set_loc(uint8_t x uint8_t y)
    {
      _x=x;
      _y=y;
    }

  std::ostream& operator<<(std::ostream& os, const Pixel_1xbyte& pix)
   {
      os << pix._intensity_value; // Outputs the intencitty
      return os;
    }

  std::istream& operator>>(std::istream& is, Pixel_1xbyte& pix)
    {
      is >> pix._intensity_value;
      return is;
    }
