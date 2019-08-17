
struct resource_Pathz_Button_pak
{
  rez_path button_res_path_OFF;
  rez_path button_res_path_HOVER;
  rez_path button_res_path_DOWN;
};

struct resource_Texture_Button_pak
{
  wrap_sdl_texture full_rez_texture_OFF;
  wrap_sdl_texture sdr_scale_texture_OFF;
  wrap_sdl_texture min_scale_texture_OFF;

  wrap_sdl_texture full_rez_texture_HOVER;
  wrap_sdl_texture sdr_scale_texture_HOVER;
  wrap_sdl_texture min_scale_texture_HOVER;

  wrap_sdl_texture full_rez_texture_DOWN;
  wrap_sdl_texture sdr_scale_texture_DOWN;
  wrap_sdl_texture min_scale_texture_DOWN;
};


struct raw_paths
{
char* path_char_OFF = {"GUI/Confermz_buttonz_2DOWN.ppm"};
char* path_char_HOVER = {"GUI/Confermz_buttonz_2HOVER.ppm"};
char* path_char_DOWN = {"GUI/Confermz_buttonz_2DOWN.ppm"};
};


class base_button
{
  protected :
  int butten_id;
  int posx, posy;
  int b_hight,b_width;

  public :
  base_button();
  virtual ~base_button() = default;
  //virtual void set_position(int x, int y) = 0;
  virtual void sdl_handle_event(SDL_Event* sdl_event) = 0;
  virtual void render(SDL_Renderer*) = 0;
  virtual void set_size(int x, int y) = 0;
 };



class sdl_button  : public base_button
{
protected :
SDL_Point sdl_postion;
SDL_Rect sdl_rectbox;
SDL_Renderer* sdl_render = nullptr;

button_graphic_statez button_vis_state;

resource_Pathz_Button_pak res_Path_pak;
resource_Texture_Button_pak texture_state_pak;


public :

sdl_button(){};

virtual void load_paks_button(SDL_Renderer** render_toset) = 0;

virtual ~sdl_button() = default;

virtual void setPosition(int x, int y)
{
  sdl_postion.x =x;
  posx=x;
  sdl_postion.y = y;
  posy=y;

}

  virtual void set_size()
  {
    sdl_rectbox.x = sdl_postion.x;
    sdl_rectbox.y = sdl_postion.y;
    sdl_rectbox.w = texture_state_pak.full_rez_texture_OFF.getWidth();
    sdl_rectbox.h = texture_state_pak.full_rez_texture_OFF.getHeight();
  }

virtual void set_size(int width, int hight)
{
  sdl_rectbox.x = sdl_postion.x;
  sdl_rectbox.y = sdl_postion.y;
  sdl_rectbox.w = width;
  sdl_rectbox.h = hight;
}
  //SDL_Rect

  virtual void render(SDL_Renderer* sdl_render) {}


  //prim_texture.render(sdl_postion.x,sdl_postion.y);


virtual void sdl_handle_event(SDL_Event* sdl_event)
{
  if( sdl_event->type == SDL_MOUSEMOTION || sdl_event->type == SDL_MOUSEBUTTONDOWN || sdl_event->type == SDL_MOUSEBUTTONUP )
  {
    int mouse_x, mouse_y;
    SDL_GetMouseState( &mouse_x, &mouse_y );
    bool on_button = true;

    if(mouse_x < sdl_postion.x)
    {
      on_button= false;
    }
    else if(mouse_x > sdl_postion.x+b_width)
    {
        on_button= false;
    }
    else if(mouse_y < sdl_postion.y)
    {
        on_button= false;
    }
    else if(mouse_y > sdl_postion.y+b_hight)
    {
      on_button= false;
    }

    if(!on_button)
    {
      button_vis_state = BUTTON_MOUSE_OFF;
    }

    else
    {
      switch(sdl_event->type)
      {
        case SDL_MOUSEMOTION :
          button_vis_state = BUTTON_MOUSE_HOVER;
        break;

        case SDL_MOUSEBUTTONDOWN :
          button_vis_state = BUTTON_MOUSE_DOWN;
        break;

        case SDL_MOUSEBUTTONUP :
          button_vis_state = BUTTON_MOUSE_POST_DOWN;
        break;
      }
     }
    }
   }
};


class confermz_buttonz : public sdl_button
{
protected :
raw_paths raw_char_paths;

public :
 confermz_buttonz(){};
 ~confermz_buttonz()= default;

 virtual void update()
 {

 }
 virtual void load_paks_button(SDL_Renderer** render_toset)
 {
   res_Path_pak.button_res_path_OFF(raw_char_paths.path_char_OFF);
   res_Path_pak.button_res_path_HOVER(raw_char_paths.path_char_HOVER);
   res_Path_pak.button_res_path_DOWN(raw_char_paths.path_char_DOWN);

   texture_state_pak.full_rez_texture_OFF.load_texture_file(res_Path_pak.button_res_path_OFF,
                                                              render_toset);
   texture_state_pak.full_rez_texture_HOVER.load_texture_file
                                          (
                                            res_Path_pak.button_res_path_HOVER,
                                            render_toset
                                          );
   texture_state_pak.full_rez_texture_DOWN.load_texture_file(res_Path_pak.button_res_path_DOWN,
                                                              render_toset);

   set_size(texture_state_pak.full_rez_texture_OFF.getWidth(),
            texture_state_pak.full_rez_texture_OFF.getHeight());

 }

void scale_button_texture_fixed()
{
  SDL_Surface* temp_sufrace;
  //wrap_sdl_texture test_texture03(full_rez_texture.scale_texture(sdl_render,56,28,
                          //        temp_sufrace),56,28);

//test_texture03.set_sufrace_overide(temp_sufrace);
SDL_FreeSurface(temp_sufrace);
temp_sufrace = nullptr;
}

virtual void render(SDL_Renderer* sdl_render)
{
  switch(button_vis_state)
  {
    case BUTTON_MOUSE_HOVER :
    {
      texture_state_pak.full_rez_texture_HOVER.render(sdl_render,posx,posy);
    }
    break;

    case BUTTON_MOUSE_DOWN :
    {
      texture_state_pak.full_rez_texture_DOWN.render(sdl_render,posx,posy);
    }
    break;

    case BUTTON_MOUSE_OFF :
    {
      texture_state_pak.full_rez_texture_OFF.render(sdl_render,posx,posy);
    }
    break;
    //default =
  }
//prim_texture.render(sdl_postion.x,sdl_postion.y);
}

};
