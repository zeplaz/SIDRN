
#include <SFML/Graphics.hpp>

class USB_controler
{
  public :
  unsigned int buttonCount = sf::Joystick::getButtonCount(0);
  // check if joystick number 0 has a Z axis
  bool hasZ;
  bool move = false;//indicate whether motion is detected
  int turbo = 1;//indicate whether player is using button for turbo speed ;)
  sf::Joystick::Identification id;
  //for movement
  sf::Vector2f ctrlin_speed = sf::Vector2f(0.f,0.f);

  inline void load_controlr()
  {
    id = sf::Joystick::getIdentification(0);
    hasZ= sf::Joystick::hasAxis(0, sf::Joystick::Z);
    buttonCount = sf::Joystick::getButtonCount(0);
    std::cout << "\nVendor ID: " << id.vendorId << "\nProduct ID: " << id.productId << std::endl;
    sf::String controller("Joystick Use: " + id.name);

      if (sf::Joystick::isConnected(0))
        { // check how many buttons joystick number 0 has
          std::cout << "Button count: " << buttonCount  << std::endl;
          std::cout << "Has a z-axis: " << hasZ << std::endl;
        }
    }
};
