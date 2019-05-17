
#include <SFML/Graphics.hpp>

#include <functional>
#include <iostream>

#include <math.h>
#include <stdio.h>
#include <string>



#include "curve_sf_dis.h"


auto curve_sin_ptr=[&](auto indpend)->sf::Vector2f
{
        //using Type = decltype(indpend);
  //    std::function<sf::Vector2f(param...)>
           float x = indpend;
           float y= -std::sin(indpend)*100;
           //std::cout << "x:" << x <<'\n' << " y:" << y << '\n';
           sf::Vector2f temp_vec(x,y);
  return (temp_vec);
};

auto curve_othz_ptr=[&](auto indpend)->sf::Vector2f
{
        //using Type = decltype(indpend);
  //    std::function<sf::Vector2f(param...)>
           float x = indpend;
           float y= (-std::sin(indpend)/(std::sin(indpend)*std::sin(indpend)))*100;
           //std::cout << "x:" << x <<'\n' << " y:" << y << '\n';
           sf::Vector2f temp_vec(x,y);
  return (temp_vec);
};


int main(int argc, char* argv[])
{
  size_t curvesiz=1000;
  float intvral= 0.5f;
  float modifer = 2;
  float  indepentvar = 3;
  sf::RenderWindow sfmlwindow(sf::VideoMode(1000,1000, 32), "Cmd_dispaly", sf::Style::Default);
  sf::Event e;

  curve_sf_dis curve_type_ojk_A1(curvesiz,intvral);

while (sfmlwindow.isOpen())
{
  int fmnum= 0;

while (sfmlwindow.pollEvent(e))
 {
    if(e.type == sf::Event::Closed)
     {
      sfmlwindow.close();
      std::cout << "closeing windowsdml" <<'\n';
     }
       }
indepentvar++;
//sf::Vector2f test_sinlabda= curve_sin_ptr(indepentvar);

//std::cout << test_sinlabda.x  << " now why: "<< test_sinlabda.y <<'\n';

//printf("loop of mianwind\n");
curve_type_ojk_A1.genrate_curve(curve_sin_ptr,indepentvar,intvral);
curve_type_ojk_A1.genrate_curve(curve_othz_ptr,indepentvar,intvral);

sfmlwindow.clear(sf::Color(0, 0, 0));
//drawlist
sfmlwindow.draw(curve_type_ojk_A1.curve_line);
sfmlwindow.display();

if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    sfmlwindow.close();
}//endofvideoloop

//
//endzslfmwindow
std::cout <<"shuting down..normalzzz" << '\n';
return 0;

}
