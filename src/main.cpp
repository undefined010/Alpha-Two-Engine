#include "WindowManager.h"
#include "Player.h"

// todo add collosion to all game objs

int main()
{
    std::unique_ptr<alpha::Window> window = std::make_unique<alpha::Window>(800, 600 , "Window Ahmad" , 60.f);
    window->setWindowPos(sf::Vector2i(0 , 0));
    
    Player* p1 = new Player(sf::Vector2f(0.f , 0.f) , "/Users/ahmadodeh/Alpha-Two-Engine/assest/player.png");
    p1->setMovement(true);
    p1->setPlayerPos(sf::Vector2f(0.f , 300.f));

    Player* p2 = new Player(sf::Vector2f(0.f , 200.f) , "/Users/ahmadodeh/Alpha-Two-Engine/assest/player.png");
    

    window->mouseEventHandler([&](){
        p2->setPlayerPos(sf::Vector2f((float) sf::Mouse::getPosition(window->getMainWindow()).x - p2->getPlayerBounds().x / 2.f, (float) sf::Mouse::getPosition(window->getMainWindow()).y - p2->getPlayerBounds().y / 2.f));
    });

    window->addGameObjects(p1);
    window->addGameObjects(p2);

    window->run();

    return 0;
}