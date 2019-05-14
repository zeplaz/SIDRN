
#include <SFML/VertexArray.hpp>

class curve_sf_dis public : sf::VertexArray
{
    public :

    sf::PrimitiveType::LineStrip curve_line;
    std::size_t vertxcount;

    float paramz_min;
    float paramz_max;
    float interval_depth;
    sf::Color next_colour=Red;

 curve_sf_dis(std::size_t size_line, float step): vertxcount(size_line),interval_depth(step)
        {

             sf::setPrimitiveType(curve_line);
             paramz_max= size_line;
             paramz_min =-1*(float)size_line/2;
             vertexCount =   std::ceil((paramz_max - paramz_min) /interval_depth);

          for (int x = paramz_min; x < paramz_max ; x++)
          {
            sf::Vertex tempvrtx(sf::Vector2f(x,- sin(x)));

            tempvrtx.color =nextcolour;
            curve.append(tempvrtx);
          }

          nextcolour =+ Magenta*(Yellow-Cyan);
      }
};
