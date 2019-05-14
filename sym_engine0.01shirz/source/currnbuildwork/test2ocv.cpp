
/* compile with
g++ -I/usr/local/include/opencv4/opencv2 -I/usr/local/include/opencv4 -I/usr/include -I/usr/local/lib/pkgconfig -g -o binarycv test2ocv.cpp -L/usr/local/lib -lopencv_shape -lopencv_videoio  -lopencv_core -lopencv_imgproc -lopencv_highgui
*/

/*
static const Color Black;
   84     static const Color White;
   85     static const Color Red;
   86     static const Color Green;
   87     static const Color Blue;
   88     static const Color Yellow;
   89     static const Color Magenta;
   90     static const Color Cyan;
   91     static const Color Transparent;*/

//#include "highgui.h"
#include "opencv2/videoio.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <SFML/Graphics.hpp>

#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath.h>

//mysufdz
#include "USB_controler.h"
#include "curve.h"





  int main(int argc, char* argv[])

{ bool load_controlUSB = false;
  bool load_video = false;
  bool debug_st=false;
  bool is_video_loaded=false;

  switch ((char)argv[i])
    {
        case 'h' :
        printf("help: progam take a flags v and or j, v to state intent of loading videos, j to load the control, \n
        keybord controls, esc will exit video, closing sfml window currnlty will terminate programe \n
        ]: key will move selcable inxez \n
        [: move down index \n
        w: move \n
        s: \n");

      case 'v' :
      load_video = true;
      break;

      case  'j' :
      load_controlUSB = true;
      break;

      case 'd' :
      debug_st=true;
      break;

      default :
      "unknown cmd, try v conferm a load vidoe, j for a confrrm useb,and d for debug. -h for more help";
    }
/*
    auto MenuMain_cmd = [argc,argv,filenamestring] mutable ()
    {      if (argc > 0)
      {        for (i=0; i<argc,i++)
        {          }        }      }
    };*/
    std::string filenamestring;

   if (load_video == true) //transfer to a video object? perhpz, a struct lamda for call
    {  std::cout << "input_video_filename:";
       std::cin >>filenamestring;

       float hue_range[]={0.180};
       float saturation_range[]={0.256};
       int hue_bins;
       int saturation_bins;

       std::cout << "input: hue bins;";
       std::cin >> hue_bins;

       std::cout <<" \n input:saturan bins;";
       std::cin >> saturation_bins;

       if( hue_bins> 255 || hue_bins< 0 ||
           saturation_bins > 179|| saturation_bins<0)

       std::cerr << "invaild bins data";

      int hista_size[]={hue_bins,saturation_bins};

    }
//create sfml  main widnwo  and event obejcz
  sf::RenderWindow sfmlwindow(sf::VideoMode(800, 600, 32), "Cmd_dispaly", sf::Style::Default);
  sf::Event e;

  //sf::ParticleSystem particles(1000);
//load the USB cotrnlz
   if(load_controlUSB == true)
    {
      USB_controler usb_cmd_ctlz;
      usb_cmd_ctlz.load_controlr();
    }

//cvbeing
  cv::Mat vframe;
  cv::Mat v_fram_hsv;
  std::string windowname = "newwin";

  cv::namedWindow (windowname, cv::WINDOW_KEargcEPRATIO);
  cv::VideoCapture vid_cap(filenamestring);

    //  TileMap map;
    if(vid_cap.isOpened())
      is_video_loaded =true;
    else
      std::cerr << "video laod faild to load";

  if(is_video_loaded)
    {
      std::cout << "Frame width: " << vid_cap.get(cv::CAP_PROP_FRAME_WIDTH) << '\n';
      std::cout << " height: " << vid_cap.get(cv::CAP_PROP_FRAME_HEIGHT) << '\n';
      std::cout << "Capturing FPS: " << vid_cap.get(cv::CAP_PROP_FPS) <<'\n';
    }
//cout << "would you like histagram?"
  while (sfmlwindow.isOpen())
  {
    int fmnum= 0;

      while (is_video_loaded)
       {
         vid_cap >>vframe;
         //if(vframe.empty()) break;
         cv::imshow(windowname,vframe);

         cv::cvtColor(vid_cap,v_fram_hsv,cv::COLOR_BGR2HSV);

         char key =(char)cv::waitKey(24);

         if (key ==27) break;
          {cout << "closeing videowindow" <<'\n';}

         fmnum++;

          while (sfmlwindow.pollEvent(e))
           {
              if(e.type == sf::Event::Closed)
               {
                sfmlwindow.close();
                cout << "closeing windowsdml" <<'\n';
               }

               //control polling.
               speed = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));

               if (e.type == sf::Event::JoystickMoved){
                 move = true;
                 std::cout << "X axis: " << speed.x << std::endl;
                 std::cout << "Y axis: " << speed.y << std::endl;
               }

               else{
                 move = false;
               }

               if (sf::Joystick::isButtonPressed(0, 0))
               {//"A" button on the XBox 360 controller
                 std::cout <<"button1" << std::endl;
                 vframe
               }

           }//endpooloop.
                      //auto transfer_window_control = [](windowctl_state,condtion){}
           //render?
            sfmlwindow.clear(sf::Color(0, 0, 0));
            //drawlist
            sfmlwindow.draw();
            sfmlwindow.display();

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
         }//endofvideoloop

         //
       }//endzslfmwindow
            std::cout <<"shuting down..normalzzz" << '\n';
return 0;
}

/*

class texture_tile_display  public sf::Drawable, public sf::Transformable
{
  public : bool load(const std::string& tile_display_name,    )
};
struct windowctl_state{}
template<typename t, sttae_type>

auto State_wrapAPI_trzformr(sttae_type&& state)
{return [state =]}

return [callable = std::forward<TCallable>(callable)](auto&&... args)
       -> decltype(callable(std::forward<decltype(args)>(args)...)) {
       std::cout << "This is some additional functionality" << std::endl;
       return callable(std::forward<decltype(args)>(args)...);
   };

   auto transfer_window_control = [](windowctl_state,condtion)
   {

   }

    class texture_tile_display  public sf::Drawable, public sf::Transformable
    {
      public : bool load(const std::string& tile_display_name,    )
    };


   */
