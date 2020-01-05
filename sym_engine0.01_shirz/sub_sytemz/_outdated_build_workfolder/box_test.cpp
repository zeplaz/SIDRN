//boxtestz
#include <SFML/Graphics.hpp>
#include <functional>
#include <iostream>
#include <chrono>
#include <math.h>
#include <stdio.h>
#include <string>
#include <list>
//#include <unordered_map>

#include "USB_controler.h"
#include "polynomial.h"
#include "Math_lamdaz.hpp"
#include "B_box.hpp"
#include "clock_utility.hpp"


#define steady 0U
#define high_rez 1U
#define sytm 2U

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
  clock_utility clockz;

  //load the USB cotrnlz
  USB_controler usb_cmd_ctlz;
  usb_cmd_ctlz.load_controlr();
  int currnet_colour;
  int live_colour;
  box_functions newBox;
  box_functions newBox2;


  // box setupz
  newBox.set_offset(100,100);
  newBox.set_dimetions(300,300);

  newBox2.set_offset(100,400);
  newBox2.set_dimetions(300,300);



    //int cubed[2]= {3,1};
  //  p_nomi<float> d2cubed(1,cubed,2.f);

    //polynomial<float> d2cubed_poly(1,d2cubed);
    //polynomial<float>* prt_d2cubed_poly = new polynomial<float>(d2cubed_poly);
    //newBox.construct_poly(prt_d2cubed_poly,red,2.f,2.f,false);



  newBox.construct_poly(curve_sin_ptr,red,2.f,2.f,false);
  std::list<box_func_node*> box_fun_list;

                box_func_node box_node_1;
                box_func_node box_node_2;
                box_func_node* box_ptr_n1  =box_node_1.newbox_f_node(newBox);
        //box_node_2.newbox_f_node(newBox2);
  box_fun_list.push_front(box_ptr_n1);
  box_fun_list.push_front(box_node_2.newbox_f_node(newBox2));

clockz.activate_timepointz();

clockz.set_checkpoint_now(steady);

std::chrono::duration<uint64_t, std::milli> four_hundz(400);

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
                    live_colour=(int)(usb_cmd_ctlz.ctrlin_speed.x+usb_cmd_ctlz.ctrlin_speed.y)%7;
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


                   if (sf::Joystick::isButtonPressed(0, 0))
                     {//"A" button on the XBox 360 controller
                       std::cout <<"Changeing colour:" << '\n';
                       currnet_colour++;
                       if(currnet_colour > 7)
                         {
                          currnet_colour=0;
                         }
                       std::cout << currnet_colour << " is Selected," << '\n';

                                     //vframe
                     }
               }

              //
              //boxupdatez
              newBox2.construct_poly(curve_sin_ptr,live_colour,2.f,2.f,false);


              //setup render stuff
               auto prt_to_boxfuncdrawable = newBox.drawable();
               auto prt_to_boxfuncdrawable2 = newBox2.drawable();
               run_render(sfmlwindow,*prt_to_boxfuncdrawable,*prt_to_boxfuncdrawable2);

              // if (clockz.duration_met(four_hundz,steady))
              // {printf("met at %s\n", std::chrono::steady_clock::now());}
          }

  //delete[] prt_d2cubed_poly;
  std::cout <<"shuting down..normalzzz" << '\n';

return 0;

}
