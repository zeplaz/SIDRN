

#pragma once

#include <SFML/Graphics.hpp>


#include <string>
#include <functional>

typedef struct
 {
  int x1,x2,y1,y2;
  int id;
  string boxname;
 }b_box_2d;

bool b_menu::being_clicked()
{

}

bool on_hover()
{

}
bool on_relase(){}

void update();

virtual void draw(sf::RenderTarget& rtarget, sf::RenderStates) const
{

}
class b_menu_bouton{
    render_enity rendr_bouton;
    text b_txt;

};

 class b_menu
 {


   std::function<void(gui_control_t *, int, int)> on_mouse_over = nullptr;
   	std::function<void(gui_control_t *, int, int)> on_mouse_down = nullptr;
   std::function<void(gui_control_t *, int, int)> on_mouse_up = nullptr;

 };

void b_menu::resizedim(const int w, const int h)
{

}
