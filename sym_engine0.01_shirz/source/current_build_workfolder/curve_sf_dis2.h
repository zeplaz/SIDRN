
//curve_sf_dis2.h

#pragma once

#include <SFML/Graphics.hpp>

#include <math.h>
#include <iostream>



#include "polynomial.h"

namespace polyz{
 enum colourznm{white,red,green,blue,yellow,cyan,magenta,transparent = -1};}


using namespace polyz;

class curve_sf_dis : public sf::VertexArray
{
    public :

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

    float paramz_min;
    float paramz_max;
    float interval_depth;
    sf::Color baseColour = colour.transparent;

    //polynomal** ptr_polyarray;

    curve_sf_dis(std::size_t size_line, double step,int base_colour): vertxcount(size_line),interval_depth(step)
        {
            std::cout << "Enter_cuvre genrator\n";


            change_colour(base_colour);

             curve_line.setPrimitiveType(sf::LinesStrip);
             paramz_max= (float)size_line;

             paramz_min = -1*(float)size_line/2;
             vertxcount = std::ceil((paramz_max - paramz_min) /interval_depth);
             curve_line.resize(vertxcount);
             std::cout <<"vertex count" << vertxcount << "parmx maxz" << paramz_max
                       << "parmxz min:" <<paramz_min << '\n';

          }
//auto f=[&](int x){std::cout<<a<<'\n';};
//foo( [](void* ptr, int x){ auto* pf = static_cast<decltype(f)*>(ptr);
// (*pf)(x); }, &f );//inline void genrate_curve([](void*line_func))
  //inline  void genrate_curve(functiontype(*line_func)(paramz...), float scal)


template<typename functiontype,typename... curve_gen_parmz>

 inline void genrate_curve (auto interval,  auto indeptz, functiontype&& line_func)
//  inline void genrate_curve (functiontype&& line_func,curve_gen_parmz* curv_pakprmz)
    {   //interval = std::index_sequence_for<Types...>());
       sf::Color next_colour= baseColour;
       bool b;
       for (auto x = paramz_min; x < paramz_max ; x+=interval)
         {
          //    std::cout << "value:" << x << '\n';
                //   if( b == true)
                ///   { b= false;
              //       next_colour =next_colour + sf::Color::Magenta;
            //       }
            //       else { b= true;
              //        next_colour =next_colour -(sf::Color::Yellow+sf::Color::Cyan);}

          sf::Vector2f newtem_vec = line_func(x+indeptz);
          sf::Vertex tempvrtx(newtem_vec);

          tempvrtx.color = next_colour;
          curve_line.append(tempvrtx);

        }
    }

  //  template <typename bastype>


  inline void genrate_curve (auto poly, auto parm_var,double interval)
  {
        sf::Color next_colour= baseColour;


        for (auto x = paramz_min; x < paramz_max ; x+=interval)
           {

              float temp_point_y= static_cast<float>(poly->solutionval(parm_var+x));
              //std::cout <<"currentyvale for curve: " << poly->solutionval(x) << '\n';
               sf::Vector2f cur_point (temp_point_y,x);
              sf::Vertex tempvrtx(cur_point);

              tempvrtx.color = next_colour;
              curve_line.append(tempvrtx);

           }

  }

  template<typename functiontype>
      inline void genrate_curve (functiontype&& line_func, auto poly, auto parm_var,auto interval)
      {
            sf::Color next_colour= baseColour;


            for (auto x = paramz_min; x < paramz_max ; x+=interval)
               {


                  //std::cout <<"currentyvale for curve: " << poly->solutionval(x) << '\n';
                  float tempval= static_cast<float>(poly->solutionval(parm_var+x));
                  if(tempval<0)
                  {tempval=tempval*-1.f;}
                   sf::Vector2f cur_point= line_func(tempval);
                  sf::Vertex tempvrtx(cur_point);

                  tempvrtx.color = next_colour;
                  curve_line.append(tempvrtx);

               }

      }


    //  inline void gen_poly(int numpli,int(&cofi_array)[numpli] ,int (&par_cons_ary)[numpli]);
  //    {

  //    }

    inline void change_colour(int base_colour)
    {
      switch(base_colour)
      {
        case white:    baseColour = colour.white;   break;
        case  red:     baseColour = colour.red;     break;
        case  green:   baseColour = colour.green;   break;
        case  blue:    baseColour = colour.blue;    break;
        case  yellow:  baseColour = colour.yellow;  break;
        case  cyan:    baseColour = colour.cyan;    break;
        case  magenta: baseColour = colour.magenta; break;

        default :  baseColour = colour.transparent;
       }
    }

    };


/*


class curve_handler()
{
  private :

};
/*
    template <typename ... tyed_covr_fuc>
    void function_plot(const tyed_covr_fuc&... args)
    {
        (handle_val(args),...)
        cout << var1 << endl ;
        using cuvr_func_prt = sf::Vector2f(*)(const  )
        print(var2...) ;
    }


  inline  sf::Vector2f sin_curve(float x)
    {
      return (sf::vector2f(x,-sin(x)));
    }

};
*/


/*static const Color Black;
   84     static const Color White;
   85     static const Color Red;
   86     static const Color Green;
   87     static const Color Blue;
   88     static const Color Yellow;
   89     static const Color Magenta;
   90     static const Color Cyan;
   91     static const Color Transparent;*/
