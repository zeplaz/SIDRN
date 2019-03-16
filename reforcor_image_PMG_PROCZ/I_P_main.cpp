


//#include "libs_modfied/glew_img_dislay.h"


//utilize sfml lib for dispalys and render as well as event loops.
//#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>
//#include <SFML/System.hpp>
//#include <SFML/OpenGL.hpp>
#include <vector>
#include <GL/glew.h>
#include <SFML/Window.hpp>
#include <iostream>


#include <fstream>
//libs sorcelibs
#include "Image_PGM_P2.h"
#include "image_procczor_mrk_1022.h"




//inlined render Thread for window_img_dispy for sfm work.

  //void renderingThread(sf::RenderWindow* window)
  //  {
        // the rendering loop
    //    while (window->isOpen())
  //      {
            // draw...

            // end the current frame
    //        window->display();
    //    }
//    }


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

    //  glew_img_dislay glewoutortor;
    //  Image_PGM_P2 new_img2;

      Image_PGM_P2* new_img1 = new Image_PGM_P2();



        Image_PGM_P2* samp_log = new Image_PGM_P2();
        Image_PGM_P2* samp_log2 = new Image_PGM_P2();
        Image_PGM_P2* samp_log3 = new Image_PGM_P2();

        Image_PGM_P2* masksobx;
        Image_PGM_P2* masksoby;
        Image_PGM_P2* driviz;

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
      std::vector<int>* pixfet_vecbase = new std::vector<int>();

//      pixfet_vecbase->push_back(1);
  //    new_proz.run_masks(1,pixfet_vecbase,new_img1,samp_log);
    //    log_file_stream << commissaire_c << " maskcomleat at: " << asctime(localtm) << "\n";
      //    pixfet_vecbase->pop_back();
        //  pixfet_vecbase->push_back(1);
        //  new_proz.run_masks(1,pixfet_vecbase,new_img1,samp_log);
      //    log_file_stream << commissaire_c << " maskcomleat at: " << asctime(localtm) << "\n";

          //pixfet_vecbase->pop_back();
          pixfet_vecbase->push_back(1);
          new_proz.run_masks(1,pixfet_vecbase,new_img1,samp_log2);
          log_file_stream << commissaire_c << " maskcomleat at: " << asctime(localtm) << "\n";

      //      pixfet_vecbase->pop_back();
        //      pixfet_vecbase->push_back(4);
    //          new_proz.run_masks(1,pixfet_vecbase,new_img1,samp_log3);
    //          log_file_stream << commissaire_c << " maskcomleat at: " << asctime(localtm) << "\n";

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
        //  new_proz.hisagramcal_(new_img1,0);

            //  mask1= new_proz.return_img_from_map(1);
              masksobx= new_proz.return_img_from_map(1);
              printf("reutnfrommap mask\n");
              masksobx->write_image(outf_stream);

          //    masksoby= new_proz.return_img_from_map(2);
      //        printf("reutnfrommap mask\n");
      //        masksoby->write_image(outf_stream);

    //          driviz= new_proz.return_img_from_map(3);
    //        printf("reutnfrommap mask\n");
    //        driviz->write_image(outf_stream);
      //  img_map_itr =
    //    if (img_map_itr != image_ptr_map.end())
  //{                            = img_map_itr->second;}


          //new_img1->write_image(outf_stream);
              log_file_stream << "imagewritentofile"<< asctime(localtm) << "\n";
              printf("displaytest mask\n");

            //  glewoutortor.displayImage(mask1->b_imgArray, mask1->get_W_cs(),mask1->get_h_rs());
          //      glewoutortor.displayImage(mask0->b_imgArray, mask1->get_W_cs(),mask1->get_h_rs());
              log_file_stream << "funnwierd glthingdid itz prokez"<< asctime(localtm) << "\n";
              printf("Shutdown \n");
          //  new_proz.conected_comp_labler(new_img1);
        //    log_file_stream << "connetocponetzz"<< asctime(localtm) << "\n";


        //    Image_PGM_P2* thshed_img= new Image_PGM_P2(new_proz.thresholdImg(new_img1));
      //      log_file_stream << "theshold and new thed obnkimg"<< asctime(localtm) << "\n";

        //    new_proz.conected_comp_labler(thshed_img);
      //        log_file_stream << "contomzb2"<< asctime(localtm) << "\n";
                 //cleanuo
            delete new_img1;
            delete  pixfet_vecbase;

      //        delete thshed_img;

            log_file_stream.close();
          return 0;
          }
