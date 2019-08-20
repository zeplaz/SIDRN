#pragma once

#include "define_typedef_cmdz_.h"
#include "cmd_buttonz.hpp"
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
    friend class UI_department;
  };


  class UI_department
  {

    private :

    UI_kontrlz_modual* ktrl_modual_focuz = nullptr;

    void set_focuz(UI_kontrlz_modual* ktrlz)
    {
      if(ktrl_modual_focuz)
      {ktrl_modual_focuz->focuz=false;}

      ktrl_modual_focuz = ktrlz;
      ktrlz-> focuz = true;
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
      create_primary_tab();
    }

   }

/*
  void create_id_tab()
  {
    assert ((val>=next_tag_id)&& "<di_tag::set_id: broken ID>");
    tab_id = val;
    next_tab_id=tab_id+1;
  }
  */

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
      if(focuz == false)
      {return false;}
     }
/*
      for (int tabN=0; tabN<sub_tabz.size(); tabN++)
      {
          sub_tabz.at(tabN)
      }

      for(int i=0; i<butten_z.size();i++)
      {

      }
    }
*/
    virtual void set_posz(int x, int y) override
    {
      sdl_postion.x =x;
      posx=x;
      sdl_postion.y = y;
      posy=y;
    }

    virtual void add_button(int type_button)
    {
      //bool succezz = true;
      switch (type_button)
      {
        case BUTTON_TYPE_CNFMZ :
        {
          sdl_button* prt_button = new confermz_buttonz();

          prt_button->setPosition(sdl_postion.x,sdl_postion.y);

          butten_z.push_back(prt_button);
          break;
        }

      }

    }
      /*
      if(!button_texture.load_texture_file())
      {
        printf("##@# fail--buttenimage invalid fileloadz:chk_pathz\n");
        succezz = false;
      }
     }
     */

    virtual void tab_event_scan(SDL_Event* sdl_event)
    {
      for (std::vector<base_button*>::iterator it = butten_z.begin() ; it != butten_z.end(); ++it)
      { base_button* prt_button;
        prt_button = *it;
        prt_button->sdl_handle_event(sdl_event);
      }
    }
/*
    virtual void tab_render()
    {
      for (std::vector<base_button*>::iterator it = butten_z.begin(); it != butten_z.end(); ++it)
      {
        base_button* prt_button;
        prt_button = *it;
        prt_button->render();
      }
    }
    */

    virtual void shut_tab();

  };
