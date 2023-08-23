#include "WindowManager.h"
#include "Player.h"
#include "Blocks.h"

int main()
{
    std::unique_ptr<alpha::Window> window = std::make_unique<alpha::Window>(800, 600 , "Window Ahmad" , 60.f);
    window->setWindowPos(sf::Vector2i(0 , 0));
    window->setWindowFrameRate(120.f);


    Player* p1 = new Player(sf::Vector2f(0.f , 300.f) , "assest/player.png");
    p1->setMovement(true);

    Block* b1 = new Block(window->getMainWindow().getSize().x , window->getMainWindow().getSize().y);
    b1->set_sprite(4 , "assest/grass_background.png");

    Block* b2 = new Block(window->getMainWindow().getSize().x , window->getMainWindow().getSize().y);
    b2->set_sprite(5 ,"assest/dirt_background.png");

    window->addGameObjects(p1);
    window->addGameObjects(b1);
    window->addGameObjects(b2);
    window->run();

    return 0;
}