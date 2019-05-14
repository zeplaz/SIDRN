

#include <iostream>
#include <SFML/Graphics.hpp>



int main(int argc, char* argv[])

{


	sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Joystick Use", sf::Style::Default);
		sf::Event e;

		sf::RectangleShape square;
		square.setFillColor(sf::Color(255, 0, 0, 255));
		square.setPosition(window.getSize().x / 2, window.getSize().y / 2);
		square.setOutlineColor(sf::Color(0, 0, 0, 255));
		square.setSize(sf::Vector2f(50.f, 50.f));

	sf::Joystick::Identification id = sf::Joystick::getIdentification(0);
	std::cout << "\nVendor ID: " << id.vendorId << "\nProduct ID: " << id.productId << std::endl;
	sf::String controller("Joystick Use: " + id.name);

//controller

if (sf::Joystick::isConnected(0)){
		// check how many buttons joystick number 0 has
		unsigned int buttonCount = sf::Joystick::getButtonCount(0);

		// check if joystick number 0 has a Z axis
		bool hasZ = sf::Joystick::hasAxis(0, sf::Joystick::Z);

		std::cout << "Button count: " << buttonCount << std::endl;
		std::cout << "Has a z-axis: " << hasZ << std::endl;
	}

  bool move = false;//indicate whether motion is detected
	int turbo = 1;//indicate whether player is using button for turbo speed ;)

//for movement
sf::Vector2f speed = sf::Vector2f(0.f,0.f);

//time
sf::Clock tickClock;
sf::Time timeSinceLastUpdate = sf::Time::Zero;
sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
sf::Time duration = sf::Time::Zero;


	window.setTitle(controller);//easily tells us what controller is connected
	bool quit_t = false;

while (!quit_t){


   while (window.pollEvent(e)){
     if (e.type == sf::Event::KeyPressed){
       switch (e.key.code){
       case sf::Keyboard::Escape:
       {
                      window.close();
                      return 0;
       }
         break;
       default:
         break;
       }
     }
     speed = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));

     if (e.type == sf::Event::JoystickMoved){
       move = true;
       std::cout << "X axis: " << speed.x << std::endl;
       std::cout << "Y axis: " << speed.y << std::endl;
     }
     else{
       move = false;
     }

     if (sf::Joystick::isButtonPressed(0, 0)){//"A" button on the XBox 360 controller
       turbo = 2;
       std::cout <<"button1" << std::endl;
     }

     if (!sf::Joystick::isButtonPressed(0, 0)){
       turbo = 1;
     }

     if(sf::Joystick::isButtonPressed(0,1)){//"B" button on the XBox 360 controller
        std::cout <<"button2" << std::endl;
       return 0;
     }

     timeSinceLastUpdate += tickClock.restart();
     		while (timeSinceLastUpdate > TimePerFrame)
     		{
     			timeSinceLastUpdate -= TimePerFrame;
     if (speed.x > 15.f || speed.x < -15.f || speed.y > 15.f || speed.y < -15.f)
     			square.move(turbo*speed.x*TimePerFrame.asSeconds(), turbo*speed.y*TimePerFrame.asSeconds());

   }
	 window.clear(sf::Color(0, 0, 0));
 		window.draw(square);
 		window.display();
 }}

return 0;}
