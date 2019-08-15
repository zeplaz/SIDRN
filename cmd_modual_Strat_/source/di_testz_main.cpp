

//`sdl2-config --cflags --libs`
#include <SDL.h>
//#include <SDL/SDL_image.h>
#include <SDL_image.h>
#include "Dialog.hpp"
#include "path_rez.hpp"
#include "image_layar_cmd.hpp"
#include "cmd_managerz.hpp"
#include <stdio.h>

enum Button_Type{
SDL_Pressed_Default,
SDL_Pressed_Up,
SDL_Pressed_Down,
SDL_Pressed_Right,
SDL_Pressed_Left,
SDL_Pressed_Total,
};

const int MAIN_SCREEN_WIDTH = 1200;
const int MAIN_SCREEN_HIGHT = 800;

  bool run_sdl()
   {
     bool sucezz = true;
    if (SDL_Init(SDL_INIT_VIDEO)<0)
     {
      printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError());
  		sucezz = false;
     }

     printf("##->SDL ILIZATIONZ COMPLEATE:\n");

    return sucezz;
    }

  inline void shutdownz(  SDL_Window* prt_window_main, SDL_Renderer* ptr_renderz)
  {
    SDL_DestroyRenderer(ptr_renderz);
    SDL_DestroyWindow(prt_window_main);
    prt_window_main = nullptr;
    ptr_renderz = nullptr;

    IMG_Quit();
    SDL_Quit();
  }

bool construct_main_window(SDL_Window* prt_window_main,SDL_Renderer* ptr_renderz)
 {
  bool sucezz = true;

  if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
    {
      printf( "Warning: Linear texture filtering not enabled!" );
      sucezz = false;
    }

  prt_window_main = SDL_CreateWindow( "cmdz_Toolz:", SDL_WINDOWPOS_UNDEFINED,
                                        SDL_WINDOWPOS_UNDEFINED, MAIN_SCREEN_WIDTH,
                                        MAIN_SCREEN_HIGHT, 0);//SDL_WINDOW_SHOWN );
  if( prt_window_main == nullptr )
   {
    printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
    sucezz = false;
   }


    printf("##->RENDER_CREATED_MAINWINDOW_INILAIZED");

    return sucezz;
    }

int main(int argc, char **argv)
  {
    //tag_msg new_tag();
    SDL_Window* sdl_window_main = nullptr;
    //The window renderer
    SDL_Renderer* sdl_render = nullptr;

    bool quit = false;
    bool sucezz = true;
    SDL_Event Prim_SDL_event;

    quit = !run_sdl();

    //quit != construct_main_window(sdl_window_main,sdl_render);

    if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
      {
        printf( "Warning: Linear texture filtering not enabled!" );
        sucezz = false;
      }

    sdl_window_main = SDL_CreateWindow( "cmdz_Toolz:", SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED, MAIN_SCREEN_WIDTH,
                                          MAIN_SCREEN_HIGHT, 0);//SDL_WINDOW_SHOWN );
    if( sdl_window_main == nullptr )
     {
      printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
      sucezz = false;
     }
      printf("##->RENDER_CREATED_MAINWINDOW_INILAIZED");


    if(quit == true|| sucezz==false)
    {
      printf("!!!>>failure quit || sucezz set...\n");
      return -3;
    }
    else {
      printf("->insize rendergenraotr...\n");
      sdl_render =  SDL_CreateRenderer(sdl_window_main, -1,
                                        SDL_RENDERER_ACCELERATED
                                        );
      if( sdl_render == nullptr )
      {
        printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
          return -4;
      }
    }

    printf("#->SDLLOADED::mainwindow OPENz\n");

    rez_path test_txtr1_path;
    rez_path test_txtr2_path;

    char* pathcartexr01 = {"GUI/Confermz_buttonz_2DOWN.ppm"};
    char* pathcartexr02 = {"GUI/sample_01_UIv02.png"};

    test_txtr1_path(pathcartexr01);
    test_txtr2_path(pathcartexr02);

    wrap_sdl_texture test_texture01;
    wrap_sdl_texture test_texture02;


    if (sdl_render == nullptr)
    {
      printf("nullprtzmain of render.");
    }

    test_texture02.load_texture_file(test_txtr2_path,&sdl_render);

    test_texture01.load_texture_file(test_txtr1_path,&sdl_render);


    wrap_sdl_texture test_texture03(test_texture01.scale_texture(sdl_render,56,28),56,28);

    while(!quit)
    {
      //printf("loopz");
      while( SDL_PollEvent( &Prim_SDL_event ) != 0 )
      {
        if( Prim_SDL_event.type == SDL_QUIT )
        {
          quit = true;
        }

        //control_loop.cycle();
        //control_loop.update();


        //redering stuffz
      //  SDL_SetRenderDrawColor( sdl_render, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_SetRenderDrawColor( sdl_render, 0, 0, 0, 255 );

        SDL_RenderClear(sdl_render);

        //drawz
        int posx=300, posy=50;
        int posx1=500, posy1=300;
        //test_texture01.render(sdl_render,posx,posy);
        //test_texture02.render(sdl_render,posx1,posy1);
        test_texture03.render(sdl_render,10,500);
        //outputtoscreenz
       SDL_RenderPresent(sdl_render);


      }
    }
    shutdownz(sdl_window_main,sdl_render);



  return 0;
  }
