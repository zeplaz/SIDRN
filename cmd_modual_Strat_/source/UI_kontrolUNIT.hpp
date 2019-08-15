#pragma once

#include "define_typedef_cmdz_.h"

  struct timrz
  {
    unsigned int chk_interval =1;
    unsigned int str_timz =0;
  };

  class UI_kontrlz_modual
  {
    protected :
    bool		mouse_iz_over = false;
    bool		mouse_down = false;
    bool		mouse_motion = false;
    //Vector2		m_LastPosition;
    int			m_Clicks = 0;
    //SDL_Timer	m_DoubleClickTimer = (500);//500ms for 2 clicks for now...
    bool focuz;
  };


  class UI_department
  {
    private :
    freind UI_kontrlz_modual;
    UI_kontrlz_modual* ktrl_modual_focuz = nullptr;

    void set_focuz(UI_kontrlz_modual* ktrlz)
    {
      if(ktrl_modual_focuz)
      {ktrl_modual_focuz->focuz=false;}

      ktrl_modual_focuz = ktrlz;
      ktrlz-> focuz = true;
    }

    public :

  }

  class base_button
  {
    protected :
    int butten_id;
    int posx, posy;
    int b_hight,b_width;

    public :
    base_button();
    virtual ~base_button() = default;
    virtual void set_position(int x, int y) = 0;
    virtual void sdl_handle_event(SDL_Event* sdl_event) = 0;
    virtual void render() = 0;
    virtual void set_size(int x, int y) = 0;
   };

class sdl_button  : public base_button
{
  protected :
  SDL_Point sdl_postion;
  button_graphic_statez button_vis_state;
  SDL_Rect sdl_rectbox;
  wrap_sdl_texture prim_texture;

  public :

  sdl_button();
  virtual ~sdl_button() = default;

  virtual void setPosition(int x, int y)
  {
    sdl_postion.x =x;
    posx=x;
    sdl_postion.y = y;
    posy=y;

  }

  virtual void set_size(int width, int hight);
  {
    sdl_rectbox.x = 0;
    sdl_rectbox.y = i * 100;
    sdl_rectbox.w = width;
    sdl_rectbox.h = hight;
  }
    //SDL_Rect

  virtual void render()
  {
    prim_texture.render(sdl_postion.x,sdl_postion.y);
  }

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


class tabz_base
{

  protected :
  int tab_id;
  int width, hight;
  int posx,posy;
  bool focuz;
  int depth;
  tabz_base* parent_prt = nullptr;
  //bool is_mouse_on();
  std::vector<base_button*> butten_z;
  std::vector<tabz_base*> sub_tabz;

  static int next_tab_id;

  public :
  //virtual void
  tabz_base()
  {
    if(!depth ==0)
    {
      create_id_tab();
    }
    }

  create_id_tab()
  {
    assert ((val>=next_tag_id)&& "<di_tag::set_id: broken ID>");
    tab_id = val;
    next_tab_id=tab_id+1;
  }
  virtual ~tabz_base() = default;

  virtual void create_primary_tab()
  {

  }

  virtual void set_size(int w,int h)
  {
    width = w;
    hight = h;
  }

  virtual void set_posz(int x, int y)
  {
    posy = y;
    posx = x;
  }

  virtual void set_focus()
  {
    focuz = true;
  }



};


  class sdl_tabz : public tabz_base
  {
    protected :
    SDL_Point sdl_postion;

    public :
    virtual bool is_mouse_on()
    {
      if(focuz = false)
      {return false;}

      else
      {

      }
    }

      for (int tabN=0; tabN<sub_tabz.size(); tabN++)
      {
          sub_tabz.at(tabN)

      }
      for(int i=0; i<butten_z.size();i++)
      {

      }
    }


    virtual void set_posz(int x, int y) override
    {
      sdl_postion.x =x;
      posx=x;
      sdl_postion.y = y;
      posy=y;
    }
    virtual bool add_button()
    {
      bool succezz = true;
      base_button* prt_button = new base_button();

      butten_z->set_posz();

      butten_z.push_back(prt_button);


      if(!button_texture.load_texture_file())
      {
        printf("##@# fail--buttenimage invalid fileloadz:chk_pathz\n");
        succezz = false;
      }

     }

    virtual void tab_event_scan(SDL_Event* sdl_event)
    {


      for (std::vector<base_button*>::iterator it = butten_z.begin() ; it != butten_z.end(); ++it)
      { base_button* prt_button;
        prt_button = *it;
        prt_button->sdl_handle_event(sdl_event);
      }
    }

    virtual void tab_render()
    {
      for (std::vector<base_button*>::iterator it = butten_z.begin(); it != butten_z.end(); ++it)
      {
        base_button* prt_button;
        prt_button = *it;
        prt_button->render();
      }
    }

    virtual void shut_tab();


  };
