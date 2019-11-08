

class tabz_base
{

  protected :
  int tab_id;
  int width, hight;
  int posx,posy;
  bool focuz;
  int depth = 0;

  //bool is_mouse_on();
  //std::vector<base_button*> butten_z;
  std::vector<tabz_base*> sub_tabz;

  std::forward_list<pane*> tabz_pane_list;
  std::unordered_map<size_t,pane*> pane_map;


  static int next_tab_id;

  public :
  tabz_base* parent_prt = nullptr;
  //virtual void
  tabz_base()
  {
    if(!depth ==0)
    {
      create_primary_tab();
      depth++;
    }
  }

  virtual ~tabz_base() = default;

  virtual void create_primary_tab() =0;


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
  /*
    void create_id_tab()
    {
      assert ((val>=next_tag_id)&& "<di_tag::set_id: broken ID>");
      tab_id = val;
      next_tab_id=tab_id+1;
    }
    */
};

//
  class sdl_tabz : public tabz_base
  {
    protected :

    SDL_Point sdl_postion;
    UI_department tabz_UI_bureau;
    std::vector<sdl_tabz*> sub_tabz_sdl;

    //std::stack<pane*> active_panez;

    public :

    virtual ~sdl_tabz() = default;
    sdl_tabz()
    {
      sub_tabz.insert(this);
      //sdl_tabz* tmp_primtab = new sdl_tabz();
      parent_prt = this;
    }

    void set_focuz_single_pane(size_t pane_id)
    {
        pane_map.find(pane_id)

        sdl_tabz* temp_pane = ;

      tes_tab->set_ktl()
    pane_UI_bureau.set_focuz();

    }

      void set_my_focuz_panes()
      {

      }
      void set_ALL_sub_panez_focus()
      {

      }

    virtual void shut_tab();

    virtual bool is_mouse_on()
     {
      if(focuz == false)
      {return false;}
     }


    virtual void  create_primary_tab()
     {
       int width=200, hight=70, x ,y;

       //
       set_posz(x, y);
       add_button(BUTTON_TYPE_CNFMZ);

       set_size(width,hight);

     }

     virtual void add_tabztoparent_sdl(sdl_tabz* added_tab)
     {
       sub_tabz_sdl.push_back(added_tab);
       added_tab->parent_prt = this;
     }

    virtual void set_posz(int x, int y) override
    {
      sdl_postion.x =x;
      posx=x;
      sdl_postion.y = y;
      posy=y;
    }

    virtual void scan_eventz_buttonz()
    {


    }
    virtual void sdl_pass_eventz()
    {
      for (std::vector<sdl_tabz*>::iterator it = sub_tabz_sdl.begin() ; it != sub_tabz_sdl.end(); ++it)
      {
          sdl_tabz* prt_sdl_tab;
          prt_sdl_tab = *it;
          if(prt_sdl_tab->)
          prt_sdl_tab->handle_panez_evtz(sdl_event);
      }
    }

    virtual void handle_panez_evtz(SDL_Event* sdl_event)
    {
      for()
      prt_sdl_tab
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

    /*
    if(!button_texture.load_texture_file())
    {
      printf("##@# fail--buttenimage invalid fileloadz:chk_pathz\n");
      succezz = false;
    }
   }
   */
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

    };


  class pane
  {
    private :
    int posx, posy;
    size_t withd, hight;
    //UI_kontrlz_modual pane_ktl_modual;

    UI_kontrlz_modual pane_ktl_modual;
    std::vector<base_button*> buttonz_vec;
// is this the way or the other wat, untangle tabes and pane and decided on how to
//want the maging of the ctl flow... aethic llalaz
    //sdl_tabz tes_tab;


    //std::vector<wrap_sdl_texture> Pane_texture_collection;

  public:

    pane()
    {

    }
    ~pane() = default;

    //	gButtonSpriteSheetTexture.render( mPosition.x, mPosition.y, &gSpriteClips[ mCurrentSprite ] );
    void set_size();
    void set_location();


    virtual UI_kontrlz_modual* set_ktl()
    {
      return &pane_ktl_modual;
    }
    void pane_initalz()
    {
      tes_tab.
      pane_UI_bureau()
    }

    void render()
    {
      //Pane_texture_collection.
    //  render(posx,posy,)
    }
    void scan_eventz_buttonz()
    {
      for(std::vector<base_button*>::iterator it = butten_z.begin() ; it != butten_z.end(); ++it)
      {
        base_button* prt_button;
        prt_button = *it;
        prt_button->sdl_handle_event(sdl_event);
      }
    }

    virtual void add_button(int type_button,int posx,int posy)
    {
      //bool succezz = true;
      switch (type_button)
      {
        case BUTTON_TYPE_CNFMZ :
        {
          confermz_buttonz* prt_button = new confermz_buttonz();

          prt_button->setPosition(sdl_postion.x,sdl_postion.y);

          butten_z.push_back(prt_button);
          break;
        }

      }
    }
  };
