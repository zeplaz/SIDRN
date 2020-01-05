
#pragma once

auto curve_sin_ptr=[&](auto indpend)->sf::Vector2f
    {              //using Type = decltype(indpend);
            //    std::function<sf::Vector2f(param...)>
        float x = indpend;
        float y= -std::sin(indpend)*100;
               //std::cout << "x:" << x <<'\n' << " y:" << y << '\n';
        sf::Vector2f temp_vec(x,y);
      return (temp_vec);
    };

auto curve_othz_ptr=[&](auto indpend)->sf::Vector2f
  {
     float x = indpend;
     float y= (-std::sin(indpend)/(std::sin(indpend)*std::sin(indpend)))*100;
     sf::Vector2f temp_vec(x,y);
    return (temp_vec);
  };
