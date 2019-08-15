#pragma once
#include <fstream>
//#include <array>
#include "define_typedef_cmdz_.h"
#include<stdio.h>

static bool OS_win = false;

class rez_path
{
  public:
  rez_path(){};
  ~rez_path() = default;
  char ch_path[255];
  int path_size;
  rez_path operator () (std::fstream& in_stream);
  rez_path operator () (char* in_charzarry)
  {
    path_size = strlen(in_charzarry);
    printf("##inchar: %s size of: %d \n", in_charzarry,path_size );

   for (size_t i =0; i< path_size;i++)
    {

     if(OS_win)
     {
      if(in_charzarry[i]=='\\')
      {
        in_charzarry[i]=='/';
      }
     }

     for (int i =0; i<path_size; i++)
     {
      ch_path[i]=in_charzarry[i];
     }

    //ch_path[path_size+1]='\0';
    }
  }

  rez_path operator () (std::string* in_string);
  rez_path operator () (std::wstring* in_wstring);

 //char* pars_file_path();
};
