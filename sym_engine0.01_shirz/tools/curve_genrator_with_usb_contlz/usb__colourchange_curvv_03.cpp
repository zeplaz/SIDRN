#include <SFML/Graphics.hpp>


//#include "opencv2/videoio.hpp"
//#include <opencv2/highgui.hpp>
//#include <opencv2/imgproc.hpp>

#include <functional>
#include <iostream>

#include <math.h>
#include <stdio.h>
#include <string>
#include <chrono>

#include "curve_sf_dis.h"
#include "USB_controler.h"




///lamdaz for now livinz here to teszt

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




  // defind in curve enum colourznm{white,red,green,blue,yellow,cyan,magenta,transparent = -1};



int main(int argc, char* argv[])
{
  std::chrono::steady_clock::time_point Program_lanch = std::chrono::steady_clock::now();
  //basic paramz for curive ovlzy not goina lvie here.
  struct curve_base_parmz {
    size_t curvesiz=1000;
    float intvral= 0.5f;
    float modifer = 2;
    float firiction = -1.2;
     }curve_base_parmz;

     //create render windowz that will be  existinn at lanch...

  sf::RenderWindow sfmlwindow(sf::VideoMode(1000,1000, 32), "Cmd_dispaly", sf::Style::Default);
  //sf::RenderWindow _2ndarycmdwindo(sf::VideoMode(500,700, 32), "2ndary_dislcmd", sf::Style::Default);


      //main event capure for main window
      sf::Event e_main;


  //load the USB cotrnlz
        USB_controler usb_cmd_ctlz;
        usb_cmd_ctlz.load_controlr();


// load a video
        //std::cout << "input_video_filename:";
      //  std::cin >>filenamestring;

  curve_sf_dis curve_type_ojk_A1(curve_base_parmz.curvesiz,curve_base_parmz.intvral,3);
  curve_sf_dis curve_type_ojk_A2(curve_base_parmz.curvesiz,curve_base_parmz.intvral,6);

  float  indepentvar = 3;
  int colourcycle;

  while (sfmlwindow.isOpen())
  {
    int fmnum= 0;

      while (sfmlwindow.pollEvent(e_main))
       {
          //shutdown events,
          if(e_main.type == sf::Event::Closed)
            {
              sfmlwindow.close();
              std::cout << "closeing windowsdml" <<'\n';
            }

    //controler_sub polling.
          usb_cmd_ctlz.ctrlin_speed = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X),
                                     sf::Joystick::getAxisPosition(0, sf::Joystick::Y));

           if (e_main.type == sf::Event::JoystickMoved)
             {
               usb_cmd_ctlz.move = true;
               std::cout << "X axis: " << usb_cmd_ctlz.ctrlin_speed.x << std::endl;
               std::cout << "Y axis: " << usb_cmd_ctlz.ctrlin_speed.y << std::endl;
               indepentvar= +usb_cmd_ctlz.ctrlin_speed.y*usb_cmd_ctlz.ctrlin_speed.x;

             }
           else
              {
                usb_cmd_ctlz.move = false;
                indepentvar -= curve_base_parmz.firiction;
              }

            if (sf::Joystick::isButtonPressed(0, 0))
              {//"A" button on the XBox 360 controller
                std::cout <<"Changeing colour:" << '\n';
                colourcycle++;
                if(colourcycle > 7)
                  {
                   colourcycle=0;
                  }
                std::cout << colourcycle << " is Selected," << '\n';


                curve_type_ojk_A2.change_colour(colourcycle);
                //vframe
              }
          }//end of pollibg



          // curive updatez.!
    //curve_type_ojk_A1.genrate_curve(curve_sin_ptr,indepentvar,curve_base_parmz.intvral);
  //  curve_type_ojk_A1.genrate_curve(curve_othz_ptr,indepentvar,curve_base_parmz.intvral);
    curve_type_ojk_A2.genrate_curve(curve_othz_ptr,indepentvar,curve_base_parmz.intvral);



    sfmlwindow.clear(sf::Color(0, 0, 0));
    //drawlist
    //sfmlwindow.draw(curve_type_ojk_A1.curve_line);
    sfmlwindow.draw(curve_type_ojk_A2.curve_line);
    sfmlwindow.display();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))

    sfmlwindow.close();

  }//endofvideoloop

  //
  //endzslfmwindow
    std::cout <<"shuting down..normalzzz" << '\n';
  return 0;

}
