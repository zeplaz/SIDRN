



#include <SFML/Graphics.hpp>

#include <math.h>
#include <iostream>

class curve_sf_dis : public sf::VertexArray
{
    public :

    sf::VertexArray curve_line;
    std::size_t vertxcount;

    float paramz_min;
    float paramz_max;
    float interval_depth;

    curve_sf_dis(std::size_t size_line, float step): vertxcount(size_line),interval_depth(step)
        {     std::cout << "Enter_cuvre genrator\n";
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
// (*pf)(x); }, &f );
template<typename functiontype>
//inline void genrate_curve([](void*line_func))
  //inline  void genrate_curve(functiontype(*line_func)(paramz...), float scal)
  inline void genrate_curve (functiontype&& line_func,float indeptz, float interval)
    {
       sf::Color next_colour=sf::Color::Red;
       bool b;
       for (auto x = paramz_min; x < paramz_max ; x+=interval)
         {

          //    std::cout << "value:" << x << '\n';
 if( b == true)
 { b= false;
   next_colour =next_colour + sf::Color::Magenta;
 }
 else { b= true;
          next_colour =next_colour -(sf::Color::Yellow+sf::Color::Cyan);}
          sf::Vector2f newtem_vec = line_func(indeptz+x);
          sf::Vertex tempvrtx(newtem_vec);

          tempvrtx.color = next_colour;
          curve_line.append(tempvrtx);

        }
    }

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
