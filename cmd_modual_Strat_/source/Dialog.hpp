#pragma once

#include <fstream>
#include <string>
#include <cassert>
#include <functional>
#include <unordered_map>
#include <array>

#include "define_typedef_cmdz_.h"
#include "UI_kontrolUNIT.hpp"
#include "cmd_managerz.hpp"

//#define cmdzdi
//emum cmdzdi {};

//if use factorysetup for objkcreaion
//makesnese to build a reiclcle phsialsy?scrapyeard?
//ya gota be some intresting metaz in there :) obje reclx,desct,scraping woo

  template<typename T, unsigned long N, unsigned long M>
  std::array<T, M+N>& operator+=(std::array<T, N>& rhs, const std::array<T, M>& lefh)
  {
    memcpy(rhs+N,lefh,sizeof(lefh));
    return rhs;
  }

template<typename T, unsigned long N,unsigned long M>
std::array<T,N> operator+(const std::array<T,N>a, std::array<T,M> const b)
{
  //std::array<T,N+M> comb += a;
//  return comb;
}

class di_tag
{
  protected :
  static int next_tag_id;

  int tag_id;
  char cmd_;
  char* tag_msg[255]= {"%\\NULLTHIS MSG IS EMPTYz"};

  private :

  bool flaged = false;

  public :

    virtual ~di_tag() =  default;

    di_tag()
      {
      set_id(next_tag_id);
      }

      void di_tag_inz(char* set_msg, bool flag_intal,char cmd_char)
      {
        flaged = flag_intal;
        cmd_ = cmd_char;
        //tag_msg =  set_msg;
      }

      inline bool chk_is_active()
      {
        return flaged;
      }

    inline bool overide_cmd(char in_overd_cmd_)
    {
        cmd_ =in_overd_cmd_;
      //  tag_msg = "OVERIDED_ACVITE::" + cmd_;
        printf("overIDE_beenACTIVATED!\n");
        printf("%s\n",tag_msg);
    }

    inline bool overide_cmd(char in_overd_cmd_, char* inmsg_ovr)
    {
        cmd_ =in_overd_cmd_;
      //  tag_msg = "##@OVERIDED_ACVITE::" + cmd_ + "\n #&->UPDATEZ: " + inmsg_ovr;

    }

    inline virtual void set_id(int val)
    {
      assert ((val>=next_tag_id)&& "<di_tag::set_id: broken ID>");
      tag_id = val;
      next_tag_id=tag_id+1;
    }


    inline char** return_tag_msg()
    {
      return tag_msg;
    }

};

class dialog_base_node
{
    protected :
      static int stat_next_di_id;

    private:
      int di_id;
      int parent_id = NULL;
      std::vector<dialog_base_node*> serre_list;
      std::vector<di_tag> tag_list;
      DI_typeCHAR di_type;
      bool end_er = false;
      bool has_branches = false;

   public:
    std::wstring dialoge_node_text;

    virtual ~dialog_base_node()= default;

    dialog_base_node()
    {
      set_id(stat_next_di_id);
    }

    inline int get_id()
    {
     return di_id;
    }

    inline virtual void set_id(int val)
    {
      assert ((val>=stat_next_di_id)&& "<di_id::set_id: broken ID>");
      di_id = val;
      stat_next_di_id=di_id+1;
    }

    inline virtual void setup_dialgo(bool sup_parent,
                                     bool is_end, int& in_parnt)
    {
       if(!sup_parent)
        {
           parent_id = in_parnt;
        }
        end_er=is_end;
      }


        //std::Vector<dialog_base*> serre_list;
      //  std::vector<di_tag> tag_list;
      //  DI_typeCHAR di_type;
      //  bool end_er = false;
      //  bool has_branches = false;

    //inline virtual void setup_dialgo(bool auto, param ... )



   inline virtual std::vector<di_tag>* prt_tag_list()
   {
     return &tag_list;
   }

  inline virtual bool  chk_ender()
  {
    return end_er;
  }

  inline virtual bool chk_has_branches()
  {
    return has_branches;
  }

};

class di_tree
{
  private :

  int di_tree_id;
  //std::wstring di_name;
  int num_nodez;

  std::unordered_map<int,dialog_base_node*> dialog_map;

  public :

    di_tree();
    ~di_tree() = default;
    void add_dialgo_node();
};

class diloge_tree_factory
{
  std::hash<std::wstring> diloge_hasher;
  di_tree* operator() (bool is_auto)
  {
    if(!is_auto)
    {
      di_tree* prt_di_tree = new di_tree();
    }
  }


};
