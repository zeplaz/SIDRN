//definez and typedefz

//notez:
template<auto n> // C++17 auto parameter declaration
auto f() -> std::pair<decltype(n), decltype(n)> // auto can't deduce from brace-init-list
{
    return {n, n};
}

#pragma once

#define IMAGE 1
#define LOGFILE 2
#define DIALOG 3
#define G_DATA 4

//base tag types
#define DI_RESPONCE 'R'
#define DI_GREETINGS 'G'
#define DI_QUESTION 'Q'
#define DI_CMD_EXCUT 'x'

typedef  int DI_typeINT;
typedef  char DI_typeCHAR;

typedef int dimetion_2[2];


enum button_graphic_statez
{
  BUTTON_MOUSE_OFF = 0,
  BUTTON_MOUSE_HOVER = 1,
  BUTTON_MOUSE_DOWN = 2,
  BUTTON_MOUSE_POST_DOWN = 3
};
