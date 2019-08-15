#pragma once

#include <map>
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
    dep_cmd(dep_cmd*);
    
  virtual ~dep_cmd() = default;
};


class Dialog_cmdz : public  dep_cmd
{
  public :
  Dialog_cmdz()
  {}
  virtual ~Dialog_cmdz() = default;
};


class textture_cmd : public  dep_cmd
{
  public :
  textture_cmd(dep_cmd* ast_cmd) : dep_cmd(ast_cmd)
  {}
  virtual ~textture_cmd() = default;
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
