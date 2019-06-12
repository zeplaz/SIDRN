
#pragma once

#include <SFML/Graphics.hpp>

#include <math.h>
#include <iostream>
#include <memory>


#include "polynomial.h"

namespace polyz{
  enum colourznm{white,red,green,blue,yellow,cyan,magenta,transparent = -1};}
using namespace polyz;


class B_box {

  private :
 size_t box_pixel_dimetions[2] = {0,0};
 size_t offsetxy[2] = {0,0};

public :
virtual void set_dimetions(size_t width, size_t hight) = 0;
virtual void set_offset(size_t x, size_t y) = 0;

};



class box_functions : public  B_box
{
  private :
  size_t box_pixel_dimetions[2] = {0,0};
  size_t offsetxy[2] = {0,0};
  //std::unique_ptr<sf::VertexArray> ptr_drablefunc;
  sf::VertexArray* ptr_drablefunc;

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

  ~ box_functions()
  {
    delete[] ptr_drablefunc;
  }

  virtual void set_dimetions(size_t width, size_t hight)
  {
    box_pixel_dimetions[0]= width;
    box_pixel_dimetions[1] = hight;
  }
  virtual void set_offset(size_t x, size_t y)
  {
    offsetxy[0]=x;
    offsetxy[1]=y;
  }

template<typename functiontype>
  inline  void construct_poly(functiontype&& line_func, int base_colour, float step, float interv, bool invert)
{
  printf("enter box setup \n");

  size_t size_min;
  size_t size_max;
  float max_solutionbounded;

  curve_forBox.paramz_min_x = 1;
  curve_forBox.paramz_min_y = 1;
  curve_forBox.paramz_max_x = box_pixel_dimetions[0];
  curve_forBox.paramz_max_y = box_pixel_dimetions[1];

  curve_forBox.curve_line.setPrimitiveType(sf::LinesStrip);
  change_colour(base_colour);
  curve_forBox.interval_depth = step;

  if (invert)
  {
    size_min = curve_forBox.paramz_min_y;
    size_max = curve_forBox.paramz_max_y;
    curve_forBox.vertxcount = curve_forBox.paramz_max_x;
    max_solutionbounded = (float)curve_forBox.paramz_max_x;
  }
  else
    {
     size_min = curve_forBox.paramz_min_x;
     size_max = curve_forBox.paramz_max_x;
     curve_forBox.vertxcount = curve_forBox.paramz_max_y;
     max_solutionbounded = (float)curve_forBox.paramz_max_y;
    }

    curve_forBox.vertxcount = std::ceil((max_solutionbounded - max_solutionbounded) /curve_forBox.interval_depth);
    printf("setup compleate begin run gen of curve \n");
  for (auto x = size_min; x<size_max; x+=interv)
  {
    float var = (float)x;
      sf::Vector2f cur_point;
      sf::Vector2f newtem_vec = line_func(x);
      std::cout << "point atz:" << newtem_vec.x << " " <<  newtem_vec.y << '\n';
        //float tempval= static_cast<float>(prt_poly->solutionval(var));
    if(newtem_vec.x<0)
      {newtem_vec.x=newtem_vec.x*-1.f;}

    if(newtem_vec.x<max_solutionbounded)
      {
        if(invert)
        {

          cur_point.x=newtem_vec.y+offsetxy[1];
          cur_point.y =newtem_vec.x+offsetxy[0];
        }
        else
        { cur_point.x=newtem_vec.x+offsetxy[0];
          cur_point.y= newtem_vec.y+offsetxy[1];
        }

        sf::Vertex tempvrtx(cur_point);
        tempvrtx.color = curve_forBox.baseColour;
        curve_forBox.curve_line.append(tempvrtx);
      }

  }
}






template <class base_type>
inline  void construct_poly(polynomial<base_type>* prt_poly, int base_colour, float step, float interv, bool invert)
  {
    printf("enter box setup \n");

    size_t size_min;
    size_t size_max;
    float max_solutionbounded;

    curve_forBox.paramz_min_x = 1;
    curve_forBox.paramz_min_y = 1;
    curve_forBox.paramz_max_x = box_pixel_dimetions[0];
    curve_forBox.paramz_max_y = box_pixel_dimetions[1];

    curve_forBox.curve_line.setPrimitiveType(sf::LinesStrip);
    change_colour(base_colour);
    curve_forBox.interval_depth = step;

    if (invert)
    {
      size_min = curve_forBox.paramz_min_y;
      size_max = curve_forBox.paramz_max_y;
      curve_forBox.vertxcount = curve_forBox.paramz_max_x;
      max_solutionbounded = (float)curve_forBox.paramz_max_x;
    }
    else
      {
       size_min = curve_forBox.paramz_min_x;
       size_max = curve_forBox.paramz_max_x;
       curve_forBox.vertxcount = curve_forBox.paramz_max_y;
       max_solutionbounded = (float)curve_forBox.paramz_max_y;
      }

      curve_forBox.vertxcount = std::ceil((max_solutionbounded - max_solutionbounded) /curve_forBox.interval_depth);
      printf("setup compleate begin run gen of curve \n");
    for (auto x = size_min; x<size_max; x+=interv)
    {
      float var = (float)x;
      sf::Vector2f cur_point;
      float tempval= static_cast<float>(prt_poly->solutionval(var));
      if(tempval<0)
        {tempval=tempval*-1.f;}

      if(tempval<max_solutionbounded)
        {
          if(invert)
          { cur_point.x=var+offsetxy[0];
            cur_point.y =tempval+offsetxy[1];
          }
          else
          { cur_point.x=tempval+offsetxy[0];
            cur_point.y= var+offsetxy[1];
          }

          sf::Vertex tempvrtx(cur_point);
          tempvrtx.color = curve_forBox.baseColour;
          curve_forBox.curve_line.append(tempvrtx);
        }

    }
  }

  inline void change_colour(int base_colour)
  {
    switch(base_colour)
    {
      case white:    curve_forBox.baseColour = curve_forBox.colour.white;   break;
      case  red:     curve_forBox.baseColour = curve_forBox.colour.red;     break;
      case  green:   curve_forBox.baseColour = curve_forBox.colour.green;   break;
      case  blue:    curve_forBox.baseColour = curve_forBox.colour.blue;    break;
      case  yellow:  curve_forBox.baseColour = curve_forBox.colour.yellow;  break;
      case  cyan:    curve_forBox.baseColour = curve_forBox.colour.cyan;    break;
      case  magenta: curve_forBox.baseColour = curve_forBox.colour.magenta; break;

      default :  curve_forBox.baseColour = curve_forBox.colour.transparent;
     }
  }

  inline auto drawable()
  {
    //std::unique_ptr<sf::VertexArray> p3 = std::make_unique<sf::VertexArray>(curve_forBox.curve_line);
    // ptr_drablefunc = std::make_unique<sf::VertexArray>(curve_forBox.curve_line);
     ptr_drablefunc = new sf::VertexArray(curve_forBox.curve_line);
    return ptr_drablefunc;
  }


};
