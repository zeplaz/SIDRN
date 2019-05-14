





#include <SFML/Graphics.hpp>


#DEFINE MAIN_WIDOWX 1200
#DEFINE MAIN_WINDOWY 1200


bool quit = false;

void render_main_windowThr_func(sf::RenderWindow* windowz)
{

    while (windowz->isOpen())
    { //list draw calls.
      windowz.mainwindow_renderque(draw...);
      windowz->display();

    }

}


void Run_Physics_thread()
{

}


void run_Network_system()
{
 sf::IpAdress loc_ip = sf::IpAddress::getLocalAddress();
 sf::UdpSocket Udp_socket;
 char udp_connectionType, mode;
 char buffer[2000];
 std::size_t received_dat;
 std::map<unsigned short, sf::IPaddress> computer_id;
 std::string network_string = "connected TO:";

 unsigned short port;

 Udp_socket.bind(port);









}

      //enum SYM_Floor_statez{}

int Main(int argc, char* argv[])
{


  std::chrono::steady_clock::time_point t_sym_start_t;
  t_sym_start_t = std::chrono::steady_clock::now();

  std::fstream  log_file_stream;

  //std::duration<double>
  Printf("ISO_main_ray_sim\n");


  log_file_stream.open("log_file.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    log_file_stream << "ISO_main_ray_sim begain exuection: " << t_sym_start_t << "\n";


sf::RenderWindow window_dispy_main (sf::VideoMode(MAIN_WIDOWX,MAIN_WINDOWY), "Image_displayMAIN_window");
window_dispy_main.setFramerateLimit(60);

    window_main.setActive(false);

    sf::Thread render_main_windowThr_func(&rendering_Thread, &window_dispy_main);
    rednder_thread.launch();

    sf::Music introMusic;
    introMusic.OpenFromFile("res/audio/intotext_muz.ogg");

    //sf::Thread physics_thead(&)

    //window.setActive(false); in your main(), before you pass it off to the thread.

    sf::View Main_view;

    Main_view.setSize().x;
    Main_view.getCenter().x;
  Main_view.getSize().x;

    status_view.
    cmd_view.
    min_consol_view.


Main_view.getCenter().x-Main_view.getSize().x/2;

sf::Sprite phical_SPRIT_objk;


bool Hit_test (int x, int y)
{

}


phical_SPRIT_objk.getPosition().x+phical_SPRIT_objk.getGlobalBounds().width

while (window_dispy_main.isOpen())
{
   sf::Event Primay_event;

      while (window_dispy_main.pollEvent(Primay_event))

      {
        {if (Primay_event.type ==sf::Event::Closed)
                    window.close();
            }

        {if (Primay_event.type == sf::Event::Resized)
            glViewport(0, 0, Primay_event.size.width, Primay_event.size.height);
        }

      }

      if (Primay_event.type == sf::Event::GainedFocus)
      //get keypress for pause
        {
            printf("keypress rturn to input cmdz; \n");
            event::polling { keypres :
            event::polling { keypres :returnkey,..}

}

    }

//main sysm loop move to w?

if (event.type == sf::Event::MouseWheelMoved)
{
    std::cout << "wheel movement: " << event.mouseWheel.delta << std::endl;
    std::cout << "mouse x: " << event.mouseWheel.x << std::endl;
    std::cout << "mouse y: " << event.mouseWheel.y << std::endl;
}

if (event.type == sf::Event::MouseButtonPressed)
{
    if (event.mouseButton.button == sf::Mouse::Right)
    {
        std::cout << "the right button was pressed" << std::endl;
        std::cout << "mouse x: " << event.mouseButton.x << std::endl;
        std::cout << "mouse y: " << event.mouseButton.y << std::endl;
    }
}

f::Vector2i localPosition = sf::Mouse::getPosition(window);
if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
{action on }


}

if (event.type == sf::Event::TextEntered)
  std::string srt_usr_event_text;
   if (event.text.unicode < 128)
  {

    srt_usr_event_text += static_cast<char>(event.text.unicode);
  }

   if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
   {
    // left key is pressed: move our character
    character.move(1, 0);
}
