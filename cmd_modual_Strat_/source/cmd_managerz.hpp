#pragma once

#include <map>
#include <functional>
#include <string>
#include <unordered_map>

#include "image_layar_cmd.hpp"
//Textrappz


class dep_cmd
{
private:

  dep_cmd(const dep_cmd &uc);
  const dep_cmd& operator = (const dep_cmd &uc);

  protected :
  dep_cmd* self_prt_department_cmd;

  public :
  dep_cmd()
  {}
  dep_cmd(dep_cmd* inz)  :self_prt_department_cmd(inz){}

  virtual ~dep_cmd() = default;
};


class Dialog_cmdz : public  dep_cmd
{
  public :
  Dialog_cmdz()
  {}
  virtual ~Dialog_cmdz() = default;
};

/*
class lookup_table_namez
  {
    std::wstring
  };
*/

template<class type_hashed>
class hash_tablez
{
  private :
  std::hash<std::wstring> hasherz;
  std::unordered_map<size_t,type_hashed*> map_hash_table;
  typename std::unordered_map<size_t,type_hashed*>::iterator map_table_itr = map_hash_table.begin();

  //
  public :

  //template<class type_hashed>
  void add_entry_by_name(std::wstring in_name ,type_hashed* value_prt)
  {
    map_hash_table.insert(std::make_pair(hasherz(in_name),value_prt));
  }

  void add_enty_by_hashed(size_t in_hashedval,type_hashed* value_prt)
  {
    map_hash_table.insert(std::make_pair(in_hashedval,value_prt));
  }

  void add_entry_auto(auto in_name, type_hashed* value_prt)
  {
    map_hash_table.insert(std::make_pair(hasherz(in_name),value_prt));
  }

  size_t hashed_val_return(int type_in,auto intohash)
  {
    switch (type_in)
    {
      case WSTRING_INZ :
      {
          return hasherz(intohash);
          break;
      }
      case CHARZ_INZ :
      {
        return hasherz(intohash);
        break;
      }
    }

  }

  type_hashed* return_hashed_entity(int ID_entity)
  {
    //  std::unordered_map<>::iterator map_table_itr
    // = map_hash_table.begin();
    map_table_itr = map_hash_table.find(ID_entity);
    if(map_table_itr == map_hash_table.end())
    {
      printf("invailedID or texture been destoyed.");
      return nullptr;
    }
    else
    {
      type_hashed* tmpr_prt;
      tmpr_prt= map_table_itr->second;
      return tmpr_prt;
    }
  }

  void destory_entry(int in_id)
  {
    type_hashed* tmpr_prt;
    tmpr_prt = return_hashed_entity(in_id);

    delete[] tmpr_prt;
    map_hash_table.erase(in_id);
  }

};


class texture_cmd : public  dep_cmd
{
  private :

  hash_tablez<wrap_sdl_texture>* prt_to_hashtable;
  //std::touple<uint32_t,wrap_sdl_texture>

  public :
  texture_cmd(dep_cmd* ast_cmd) : dep_cmd(ast_cmd)
  {
    prt_to_hashtable  = nullptr;
  }

  virtual ~texture_cmd() = default;

  bool registar_with_hashtable(hash_tablez<wrap_sdl_texture>* intable)
  {
    prt_to_hashtable =intable;
  }

  void add_name_hasher(std::wstring in_string,wrap_sdl_texture* intexture)
  {
    if(prt_to_hashtable !=nullptr)
    {
      //uint32_t hashed_int = prt_to_hashtable(in_string);
      prt_to_hashtable->add_entry_auto(in_string,intexture);
    }
  }

  void add_texture_via_prehashdval()
  {

  }

  void destory_texture(int id_texture)
  {
    prt_to_hashtable->destory_entry(id_texture);
  }

  //template<class type>
  size_t create_texture_resorce(int type_mode,auto inval,std::wstring name, SDL_Renderer** sdl_rednerz)
  {
    char* path_tx;
    rez_path in_path;
    size_t temp_id= NULL;

    switch (type_mode)
    {
    //  case MANUAL_ENTER :

    //  break;
      case CHARZ_INZ :
      {
       printf("##BEgin_texture_creationz");
       in_path(inval);
       wrap_sdl_texture* new_texture = new wrap_sdl_texture();
       new_texture->load_texture_file(in_path,sdl_rednerz);
       temp_id = prt_to_hashtable->hashed_val_return(WSTRING_INZ,name);
       prt_to_hashtable->add_enty_by_hashed(temp_id,new_texture);

       printf("#->compleate charz_inname loadtexture");
       break;
      }
    }

  //  case STRING_INZ:

    //  break;

    printf("newID %i##\n",temp_id);
    return temp_id;

  }

};

class Asset_manager  : public  dep_cmd
{
  public :
  Asset_manager(dep_cmd* ast_cmd) : dep_cmd(ast_cmd)
  {}
  virtual ~Asset_manager() = default;

  //void add_textture(int te_id, rez_path path);

  //get_textture(int te_id);
};
