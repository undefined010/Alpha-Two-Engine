#include "WindowManager.h"
#include "Player.h"

int main()
{
    std::unique_ptr<alpha::Window> window = std::make_unique<alpha::Window>(800, 600 , "Window Ahmad" , 60.f);
    window->setWindowPos(sf::Vector2i(0 , 0));
    
    Player* p1 = new Player(sf::Vector2f(0.f , 300.f) , "assest/player.png");
    p1->setMovement(true);

    Player* p2 = new Player(sf::Vector2f(200.f , 300.f) , "assest/player.png");

    window->addGameObjects(p1);
    window->addGameObjects(p2);

    window->run();

    return 0;
}