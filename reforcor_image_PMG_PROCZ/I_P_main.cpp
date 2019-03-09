


#include "libs_modfied/glew_img_dislay.h"


//utilize sfml lib for dispalys and render as well as event loops.
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
//#include <SFML/OpenGL.hpp>


//libs sorcelibs
#include "Image_PGM_P2.h"
#include "image_procczor_mrk_1022.h"




//inlined render Thread for window_img_dispy for sfm work.

  void renderingThread(sf::RenderWindow* window)
    {
        // the rendering loop
        while (window->isOpen())
        {
            // draw...

            // end the current frame
            window->display();
        }
    }


    int main(int argc, char* argv[])

    {//startup create log stream
      bool quit_t=false;
      std::fstream log_file_stream;
      time_t now = time(0);
      tm* localtm = localtime(&now);



      printf(" SUDRN_0.00.01 Image_process::_ANlaizer0.02.0 \n" );
      log_file_stream.open("log_file.txt", std::fstream::in | std::fstream::out | std::fstream::app);
      log_file_stream << "SIDRN begain exuection::I_P_ANlaizer0.02.0:" << asctime(localtm) << "\n";


      std::ifstream in_img;
      std::ofstream outf_stream;

  //inlization proccedures

      glew_img_dislay glewoutortor;
    //  Image_PGM_P2 new_img2;

      Image_PGM_P2* new_img1 = new Image_PGM_P2();
      image_procczor_mrk_1022 new_proz;

      new_img1->Image_Procees_inlizar(in_img);



    //  std::vector<std::vector<uint32_t>>* prt__img_rawvec_data= new  std::vector<std::vector<uint32_t>>(new_img1->b_imgArray);

//


  std::string commissaire_c;
  //std::string commissaire_pass;


      printf(" Enter your Orgburo commissaire Code: \n");
      std::cin >>  commissaire_c;
      std::getline(std::cin, commissaire_c);

      log_file_stream << commissaire_c << " hasLogedON at: " << asctime(localtm) << "\n";
    //  printf(" To Quit enter q and press enter:\n");



    //    sf::RenderWindow window_img_dispy_main (sf::VideoMode(255,255), "Image_display_window");
      //  window_img_dispy_main.setFramerateLimit(60);

        //activethread
        //call setActive(false); beforepassingthred

            // deactivate its OpenGL context
        //    window.setActive(false);

            // launch the rendering thread
          //  sf::Thread rednder_thread(&renderingThread, &window);
        //    rednder_thread.launch();

            //event/logic/loop

        //    while (!quit_t){
          //  }
          new_proz.hisagramcal_(new_img1,0);
          new_img1->write_image(outf_stream);

            glewoutortor.displayImage(new_img1->b_imgArray, new_img1->get_W_cs(),new_img1->get_h_rs());


            //cleanuo
            delete new_img1;
          return 0;
          }
