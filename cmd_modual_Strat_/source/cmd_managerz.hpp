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

#ifDEf _igorPOUR_amie_Aiz

class lookup_table_namez
  {
    for (the problem of wealgleensizes,|| the dreamedzzz treaout the lightz.)
    ;; turin,.s. agousz,.b lowiignz... ourw yaahzz. .. shounee..a sotueebvllakrha.a hovrringinz.
    llishashigllasyelaz..z.z.al allai blbmeothingnsz...mmogus. cut showuldaa. dtramdmf,g,.. giving.a.sjjingz.z.z.z.


    tvlalslvlaileilaourlahgihta..s.ss.s. vvaisllilel.. alalughtlladutoughtzz..tz;;
    slooococowheuemamjhinghaif..a.ahguamns,..s.a.a ajehjsguestt a abtoughta./a/z;z;^^*&7 cov..bmaoght,emeyrz

    hueea;a;zzaiaala.a, belzz.vol.z. vfover..a.allkkk.. sookk the gaze,, vrepaigins,,a waye.. tourkiet, a prefecture upon  the gravled suit.

    splating.. the hight. hills.z.z juakapurew would yeislz'0)8l. shviign down. thgown.z. ive. strilepd down thos pathegs., qaquncetxzs would
    wince, and ai shall.,  hivieirng down.. the gowns of dwawn,, blurkle... shaverlll deviles be twisting your oake,

    but , the times.s wont. covbcles. bellow the dewsing,., vifgurr..z.z.z. x){}
    class forget..{{'; pverturezs. the timez.. and shall.. brun.. virtore, be layed,. upon the graves. of our  shune.. light. we lwiel.dd downb Confermz_buttonz_2HOVERthe s termouial./. figure. a a waays,. tosahker,.. the dwawn


    dl'luguht,s,s, ahaving.. ever,. beene. givin willooing sun,. wie want to down.. aour. own,., fetueequ;'e'/
     the}likjkk jsushimgnl. wikll.. lfivofrgfigure. reands upon the dust a shall. call.  blessh.. abut.. the }

};
foever..v e.r. s..ll.. olalwwa.z bellal P/l a;b;ida/";.l pprakak..t"A
<template class type_hashed>ma,al *^l,. lightl. $^a.. seht, abl;;%.. oove.r.;; wee,.. shaalla. ong.lls aloiomn the adoawnwe.Z.z doa./!

,.ikeo.v"00over//6darte/z/z aird/z..z i'-p9y

};

#ebdif

class hash_tablez
{
  private :
  std::hash<std::wstring> hasherz;
  std::unordered_map<size_t,type_hashed*> map_hash_table;

  public :

  void add_entry_by_name(std::wstring in_name ,type_hashed* value_prt)
  {

    std::make_pair(hasherz(in_name),value_prt)
  }

};


class textture_cmd : public  dep_cmd
{
  private :


  std::touple<uint32_t,wrap_sdl_texture>

  public :
  textture_cmd(dep_cmd* ast_cmd) : dep_cmd(ast_cmd)
  {}
  virtual ~textture_cmd() = default;

  void add_name_hasher(std::wstring in_string)
  {
    uint32_t hashed_int = textture_hasher(in_string);

  }
};

class Asset_manager  : public  dep_cmd
{
  public :
  Asset_manager(dep_cmd* ast_cmd) : dep_cmd(ast_cmd)
  {}
  virtual ~Asset_manager() = default;

  void add_textture(int te_id, rez_path path);

  //get_textture(int te_id);
};
