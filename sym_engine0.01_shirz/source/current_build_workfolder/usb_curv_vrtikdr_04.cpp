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
#include <unordered_map>

#include "curve_sf_dis2.h"
#include "USB_controler.h"
#include "polynomial.h"
/*
typedef struct {
  int curve_id;
  curve_sf_dis* prt_tocouver;
}curve_prt_contr;

static int next_curve_id = 0;

bool curve_factory
{

}
*/
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


//function to run renders, on seific widnows, with varatic parmpackz

    template<typename... todrawz>
    void run_render(sf::RenderWindow& sfmlwindow,todrawz ...drawlizt)
    {
          //printf("processing renderz\n");

          sfmlwindow.clear(sf::Color(0, 0, 0));
          //drawlist unfolder
          (sfmlwindow.draw(drawlizt), ...);

          sfmlwindow.display();
    }


  // defind in curve enum colourznm{white,red,green,blue,yellow,cyan,magenta,transparent = -1};

    struct curve_base_parm {
      //curve_base_parm* next_cuvr_parm;
      size_t curvesiz=1000;
      double intvral= 0.5f;
      double modifer = 2;
      double firiction = -1.2;
      double  indepentvar = 1;
      int colourcycle;
       }curve_base_parmz;

using namespace polyz;
int main(int argc, char* argv[])
{
  std::chrono::steady_clock::time_point Program_lanch_pt = std::chrono::steady_clock::now();
  //basic paramz for curive ovlzy not goina lvie here.
//  std::chrono::steady_clock::duration accumlator{};


    // map setupz
  //  std::unordered_map<int,curve_sf_dis*> curve_map;

    //parmz move!

     curve_base_parm* prt_parm_curve1 = &curve_base_parmz;
     //curve_base_parm* prt_parm_curve2 = new curve_base_parm(curve_base_parmz);
      //curve_base_parm* prt_parm_curve2 = new curve_base_parm(curve_base_parmz);

         //create render windowz that will be  existinn at lanch...

  sf::RenderWindow sfmlwindow(sf::VideoMode(1000,1000, 32), "Cmd_dispaly", sf::Style::Default);
  //sf::RenderWindow _2ndarycmdwindo(sf::VideoMode(500,700, 24), "2ndary_dislcmd", sf::Style::Default);


      //main event capure for main window
      sf::Event e_main;


  //load the USB cotrnlz
        USB_controler usb_cmd_ctlz;
        usb_cmd_ctlz.load_controlr();


// load a video
        //std::cout << "input_video_filename:";
      //  std::cin >>filenamestring;

      //some polyz to teszt

      //std::ratio<3,1> cubedegree;
    //  std::ratio<1,1> base_1;
    int cube_power[2]= {3,2};
      int base_1[2]= {1,2};
      double cofA_6 =1.2;
      double cofA_2 =1.12;

      p_nomi<double> p_6x_3(_x,cube_power,cofA_6);
      p_nomi<double> p_2x_1(_x,base_1,cofA_2);

      polynomial<double> newpoly(2,p_6x_3,p_2x_1);
      polynomial<double>* prt_newpolyz = &newpoly;

  //curve_sf_dis curve_type_ojk_A1(curve_base_parmz.curvesiz,curve_base_parmz.intvral,3);
//  curve_sf_dis curve_type_ojk_A2(curve_base_parmz.curvesiz,curve_base_parmz.intvral,6);
curve_sf_dis curve_type_ojk_A3( prt_parm_curve1->curvesiz,prt_parm_curve1->intvral,green);
curve_sf_dis curve_type_ojk_A4( prt_parm_curve1->curvesiz,prt_parm_curve1->intvral,blue);

  while (sfmlwindow.isOpen())
    {     //mandory escape
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
          {
            //  _2ndarycmdwindo.close();
              sfmlwindow.close();
            }

      //opencvsetupstuff goes here.
      int fmnum= 0;

    //pooling loop
    //run_mainsfml_polling(e_main);
    while (sfmlwindow.pollEvent(e_main))
     {
        //shutdown events,
        if(e_main.type == sf::Event::Closed)
          {
            //_2ndarycmdwindo.close();
            sfmlwindow.close();

            std::cout << "closeing windowsdml" <<'\n';
          }

    //controler_sub polling.
        usb_cmd_ctlz.ctrlin_speed = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X),
                                   sf::Joystick::getAxisPosition(0, sf::Joystick::Y));

         if (e_main.type == sf::Event::JoystickMoved)
           {
             usb_cmd_ctlz.move = true;
            // std::cout << "X axis: " << usb_cmd_ctlz.ctrlin_speed.x << std::endl;
          //   std::cout << "Y axis: " << usb_cmd_ctlz.ctrlin_speed.y << std::endl;
             curve_base_parmz.indepentvar= +usb_cmd_ctlz.ctrlin_speed.y+usb_cmd_ctlz.ctrlin_speed.x;
              std::cout << "new move order:"<< curve_base_parmz.indepentvar << '\n';
              std::cout << "next solution: " << prt_newpolyz->solutionval(prt_parm_curve1->indepentvar) << '\n';


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
              curve_base_parmz.colourcycle++;
              if(curve_base_parmz.colourcycle > 7)
                {
                 curve_base_parmz.colourcycle=0;
                }
              std::cout << curve_base_parmz.colourcycle << " is Selected," << '\n';

              curve_type_ojk_A3.change_colour(curve_base_parmz.colourcycle);
                curve_type_ojk_A4.change_colour(curve_base_parmz.colourcycle);
              //vframe
            }
        }//end of pooling loop

          // curive updatez.!
/*
          for ( auto it = curve_map.begin(); it != curve_map.end(); ++it )
          {
              curve_sf_dis* prt_curve;
              prt_curve=it->second;
              prt_curve->genrate_curve(,prt_parm_curve);


          }
          */

  //  curve_type_ojk_A1.genrate_curve(curve_sin_ptr,curve_base_parmz.indepentvar,curve_base_parmz.intvral);
  //  curve_type_ojk_A1.genrate_curve(curve_othz_ptr,indepentvar,curve_base_parmz.intvral);
  //  curve_type_ojk_A2.genrate_curve(curve_othz_ptr,curve_base_parmz.indepentvar,curve_base_parmz.intvral);
/*


double randox=1;
for(int i =0; i<500; i++)
{ randox++;

}*/
 curve_type_ojk_A4.genrate_curve(curve_base_parmz.intvral,prt_parm_curve1->indepentvar, curve_othz_ptr);
 curve_type_ojk_A3.genrate_curve(prt_newpolyz,prt_parm_curve1->indepentvar,curve_base_parmz.intvral);



      run_render(sfmlwindow,curve_type_ojk_A3.curve_line,curve_type_ojk_A4.curve_line);
      //run_render(_2ndarycmdwindo,curve_type_ojk_A1.curve_line);
    //sfmlwindow.draw(curve_type_ojk_A1.curve_line);
  //  sfmlwindow.draw(curve_type_ojk_A2.curve_line);
      //accumlator =+ ( std::chrono::steady_clock::now()-Program_lanch_pt);
}//eendof sfml window lop

//delete[] prt_parm_curve1;
//delete[]  prt_newpolyz;
//delete[] prt_parm_curve1;
//delete[] prt_parm_curve3;
      std::cout <<"shuting down..normalzzz" << '\n';
  return 0;

}
