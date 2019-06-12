
#pragma once

#include <SFML/Graphics.hpp>

#include <math.h>
#include <iostream>



#include "polynomial.h"


using namespace polyz;

class B_box {

  private :
 size_t box_pixel_dimetions[2] = {0,0};
 size_t offsetxy[2] = {0,0};

public :
virtual void set_size(size_t width, size_t hight) = 0;
virtual void set_offset(size_t x, size_t y) = 0;

};



class box_functions_sqr public : B_box
{
  private :
  struct curve_forBox{
    struct colour {
    sf::Color   white=sf::Color::White;
    sf::Color   red=sf::Color::Red;
    sf::Color   green=sf::Color::Green;
    sf::Color   blue=sf::Color::Blue;
    sf::Color   yellow=sf::Color::Yellow;
    sf::Color   cyan=sf::Color::Cyan;
    sf::Color   magenta=sf::Color::Magenta;
    sf::Color   transparent=sf::Color::Transparent;
    }colour;

    sf::VertexArray curve_line;
    std::size_t vertxcount;

    float paramz_min_x;
    float paramz_min_y;

    float paramz_max_x;
    float paramz_max_y;

    float interval_depth;
    sf::Color baseColour = colour.transparent;
  }curve_forBox;


  public :
  virtual void set_size(size_t max_size)
  {
    box_pixel_dimetions[0]= max_size;
    box_pixel_dimetions[1] = max_size;
  }
  virtual void set_offset(size_t x, size_t y)
  {
    offsetxy[0]=x;
    offsetxy[1]=y;
  }

inline  void construct_poly(polynomal* prt_poly, int base_colour, float interv, bool invert)
  {
    size_t size_min;
    size_t size_max;
    float max_solutionbounded;
    curve_forBox.vertxcount = box_pixel_dimetions[0];
    curve_forBox.paramz_min_x = offsetxy[0];
    curve_forBox.paramz_min_y = offsetxy[1];
    curve_forBox.paramz_max_x = offsetxy[0]+box_pixel_dimetions[0];
    curve_forBox.paramz_max_y = offsetxy[1]+box_pixel_dimetions[1];

    change_colour(base_colour);
    curve_forBox.interval_depth = interv;

    if (invert)
    {
      size_min = curve_forBox.paramz_min_y;
      size_max = curve_forBox.paramz_max_y;
      max_solutionbounded = (float)urve_forBox.paramz_max_x;
    }
    else
      {
       size_min = curve_forBox.paramz_min_x;
       size_max = curve_forBox.paramz_max_x;
       max_solutionbounded = (float)urve_forBox.paramz_max_y;
      }


    for (auto x = size_min; x<size_max; x+=interv )
    {
      float tempval= static_cast<float>(poly->solutionval(x));
      if(tempval<0)
        {tempval=tempval*-1.f;}

      if(tempval<max_solutionbounded)
        {
          if(invert)
          {sf::Vector2f cur_point(x,tempval);}
          else {sf::Vector2f cur_point(tempval,x)}

          sf::Vertex tempvrtx(cur_point);
          curve_forBox.tempvrtx.color = next_colour;
          curve_forBox.curve_line.append(tempvrtx);
        }

    }
  }

  inline void change_colour(int base_colour)
  {
    switch(base_colour)
    {
      case white:    curve_forBox.baseColour = colour.white;   break;
      case  red:     curve_forBox.baseColour = colour.red;     break;
      case  green:   curve_forBox.baseColour = colour.green;   break;
      case  blue:    curve_forBox.baseColour = colour.blue;    break;
      case  yellow:  curve_forBox.baseColour = colour.yellow;  break;
      case  cyan:    curve_forBox.baseColour = colour.cyan;    break;
      case  magenta: curve_forBox.baseColour = colour.magenta; break;

      default :  curve_forBox.baseColour = colour.transparent;
     }
  }


};
