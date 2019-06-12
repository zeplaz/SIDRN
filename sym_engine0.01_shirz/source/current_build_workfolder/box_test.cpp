//boxtestz
#include <SFML/Graphics.hpp>
#include <functional>
#include <iostream>

#include <math.h>
#include <stdio.h>
#include <string>
#include <chrono>
#include <unordered_map>

#include "USB_controler.h"
#include "polynomial.h"
#include "Math_lamdaz.hpp"
#include "B_box.hpp"



template<typename... todrawz>
void run_render(sf::RenderWindow& sfmlwindow,todrawz ...drawlizt)
{
      //printf("processing renderz\n");

      sfmlwindow.clear(sf::Color(0, 0, 0));
      //drawlist unfolder
      (sfmlwindow.draw(drawlizt), ...);

      sfmlwindow.display();
}

int main(int argc, char* argv[])
{

  //create render windowz that will be  existinn at lanch...

  sf::RenderWindow sfmlwindow(sf::VideoMode(1000,1000, 32), "Cmd_dispaly", sf::Style::Default);
      //sf::RenderWindow _2ndarycmdwindo(sf::VideoMode(500,700, 24), "2ndary_dislcmd", sf::Style::Default);


      //main event capure for main window
  sf::Event e_main;

  //load the USB cotrnlz
  USB_controler usb_cmd_ctlz;
  usb_cmd_ctlz.load_controlr();

  box_functions newBox;

  newBox.set_offset(100,100);
  newBox.set_dimetions(300,300);

    int cubed[2]= {3,1};
  //  p_nomi<float> d2cubed(1,cubed,2.f);

    //polynomial<float> d2cubed_poly(1,d2cubed);
    //polynomial<float>* prt_d2cubed_poly = new polynomial<float>(d2cubed_poly);
    //newBox.construct_poly(prt_d2cubed_poly,red,2.f,2.f,false);


  newBox.construct_poly(curve_sin_ptr,red,2.f,2.f,false);
  while (sfmlwindow.isOpen())
    {     //mandory escape
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
          {
            //  _2ndarycmdwindo.close();
              sfmlwindow.close();
            }

            while (sfmlwindow.pollEvent(e_main))
             {
                //shutdown events,
                if(e_main.type == sf::Event::Closed)
                  {
                    //_2ndarycmdwindo.close();
                    sfmlwindow.close();
                    std::cout << "closeing windowsdml" <<'\n';
                  }

                usb_cmd_ctlz.ctrlin_speed = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X),
                                            sf::Joystick::getAxisPosition(0, sf::Joystick::Y));

                 if (e_main.type == sf::Event::JoystickMoved)
                   {
                    usb_cmd_ctlz.move = true;
                   }
                 else
                   {
                    usb_cmd_ctlz.move = false;
                        //curve_base_parmz.indepentvar -= curve_base_parmz.firiction;
                   }

                  if (sf::Joystick::isButtonPressed(0, 1))
                   {
                    std::cout <<"selcted Next curve:" << '\n';
                   }
               }

              //
               auto prt_to_boxfuncdrawable = newBox.drawable();
               run_render(sfmlwindow,*prt_to_boxfuncdrawable);

          }

  //delete[] prt_d2cubed_poly;
  std::cout <<"shuting down..normalzzz" << '\n';

return 0;

}
