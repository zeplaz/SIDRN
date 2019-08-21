
#pragma once

//definez and typedefz
#include <valarray>


//notez:
template<auto n> // C++17 auto parameter declaration
auto f() -> std::pair<decltype(n), decltype(n)> // auto can't deduce from brace-init-list
{
    return {n, n};
}


//genreal definez
#define IMAGE 1
#define LOGFILE 2
#define DIALOG 3
#define G_DATA 4


// button definez
#define BUTTON_TYPE_CNFMZ 5
#define BUTTON_TYPE_EXIT 6
#define BUTTON_TYPE_SCALE 7

// manger_typeload
#define MANUAL_ENTER 8
#define STRING_INZ 9
#define CHARZ_INZ 10
#define WSTRING_INZ 11

//base tag types
#define DI_RESPONCE 'R'
#define DI_GREETINGS 'G'
#define DI_QUESTION 'Q'
#define DI_CMD_EXCUT 'x'



typedef  int DI_typeINT;
typedef  char DI_typeCHAR;

typedef int dimetion_2[2];


typedef std::valarray<int> vector2d_int = {0,0};
typedef std::valarray<float> vector2d_float = {0.f,0.f};
typedef std::valarray<double> vector2d_int = {0.f,0.f};

enum button_graphic_statez
{
  BUTTON_MOUSE_OFF = 0,
  BUTTON_MOUSE_HOVER = 1,
  BUTTON_MOUSE_DOWN = 2,
  BUTTON_MOUSE_POST_DOWN = 3
};

enum class Mousez_buttonz
  {
   none, left, right, middle
  };

enum class active_mouse_ktrl
{
  off =-1,
  mouse_relase = 0,
  down =1
};
