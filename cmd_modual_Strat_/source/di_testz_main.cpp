

//`sdl2-config --cflags --libs`
#include <SDL.h>
//#include <SDL/SDL_image.h>
#include <SDL_image.h>
#include <stdio.h>

#include "Dialog.hpp"
#include "path_rez.hpp"
#include "image_layar_cmd.hpp"
#include "cmd_managerz.hpp"

#include "UI_kontrolUNIT.hpp"
#include "cmd_buttonz.hpp"


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


    //dep_cmd asset_cmd_mgmt;


    rez_path test_rez_path_UI;
    char* char_raw_test_UI = {"GUI/sample_01_UIv02.png"};
    test_rez_path_UI(char_raw_test_UI);


    if (sdl_render == nullptr)
    {
      printf("nullprtzmain of render.");
    }


    //wrap_sdl_texture test_texture02;


    //test_texture02.load_texture_file(test_txtr2_path,&sdl_render);
    //confermz_buttonz test_conferm_button;

    int con_x= 100, con_y= 200;

    //test_conferm_button.load_paks_button(&sdl_render);
    //test_conferm_button.setPosition(con_x,con_y);
    //test_conferm_button.set_size();

    texture_cmd texture_asset_mgmt(&texture_asset_mgmt);

    hash_tablez<wrap_sdl_texture> texture_h_table;

    texture_asset_mgmt.registar_with_hashtable(&texture_h_table);
    //texture_h_table.  &test_texture02,

    texture_asset_mgmt.create_texture_resorce(&sdl_render);


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

        test_conferm_button.sdl_handle_event(&Prim_SDL_event);


        //redering stuffz
      //  SDL_SetRenderDrawColor( sdl_render, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_SetRenderDrawColor( sdl_render, 0, 0, 0, 255 );

        SDL_RenderClear(sdl_render);

        //drawz
        int posx=300, posy=50;
        int posx1=500, posy1=300;
        //test_texture01.render(sdl_render,posx,posy);
        //test_texture02.render(sdl_render,posx1,posy1);
        test_conferm_button.render(sdl_render);
        //test_texture03.render(sdl_render,10,500);
        //outputtoscreenz
       SDL_RenderPresent(sdl_render);


      }
    }
    shutdownz(sdl_window_main,sdl_render);



  return 0;
  }
