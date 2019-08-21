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
    UI_department* UI_bureau;
    bool		mouse_iz_over = false;
    bool		mouse_down = false;
    bool		mouse_motion = false;
    //Vector2		m_LastPosition;
    int			m_Clicks = 0;
    //SDL_Timer	m_DoubleClickTimer = (500);//500ms for 2 clicks for now...
    bool focuz;
    friend class UI_department;

    public :



  };

  class UI_department
  {

    private :
    friend class UI_kontrlz_modual;

    UI_kontrlz_modual* ktrl_modual_focuz = nullptr;

    void set_focuz(UI_kontrlz_modual* ktrlz)
    {
      if(ktrl_modual_focuz)
      {ktrl_modual_focuz->focuz=false;}

      ktrl_modual_focuz = ktrlz;
      ktrlz-> focuz = true;
    }

    UI_department(const UI_department &copy) = delete;
    UI_department& operator = (const UI_department &copy) = delete;

    public :
      std::vector<UI_kontrlz_modual*> UI_ktl_modual_vec;

    ~UI_department()
    {
      for(size_t i =0; i< UI_ktl_modual_vec.size(); i++)
        {
          UI_kontrlz_modual* temp_ptr;
          temp_ptr = UI_ktl_modual_vec[i];
          delete[] temp_ptr;
        }
    }

    void desroy_ktl(int loc)
    {
      if(loc< UI_ktl_modual_vec.size())
      {
        UI_kontrlz_modual* temp_ptr;
        temp_ptr = UI_ktl_modual_vec[loc];
        delete[] temp_ptr;
      }
      else {
        printf("contoler out of boundz %i not exist\n", loc );
      }
    }

    template<class kntl_unit>
    kntl_unit* create_UIcontroler()
    {
      kntl_unit* k_u = new kntl_unit;
      k_u->UI_bureau=this;

      return k_u;
    }
  };

  class mouse_krlz
  {
    public :
    active_mouse_ktrl left;
    active_mouse_ktrl right;
    active_mouse_ktrl middle;

    vector2d_int loc_mouse;
    vector2d_double mouse_wheel;

  };
