#include "WindowManager.h"
#include "Player.h"
#include "TileMap.h"

int main()
{
    // window
    std::unique_ptr<alpha::Window> window = std::make_unique<alpha::Window>(800, 600 , "Window Ahmad" , 60.f);
    window->setWindowPos(sf::Vector2i(0 , 0));
    
    // player
    Player* p1 = new Player(sf::Vector2f(0.f , 300.f) , "assest/player.png");
    p1->setMovement(true);

    Player* p2 = new Player(sf::Vector2f(200.f , 300.f) , "assest/player.png");
    
    // tile map
    game::TileMap* mm = new game::TileMap();

    // window and player events
    int counter = 0;
    window->onLeftClick([&](){
        p2->setMovement(++counter % 2);

        if (counter == 1000) counter = 0;
    });

    p1->addPlayerEvents([&](){
        if (p1->getPlayerPos().y <= 0.f) p1->setPlayerPos(sf::Vector2f{p1->getPlayerPos().x , 0.f});
        if (p1->getPlayerPos().x <= 0.f) p1->setPlayerPos(sf::Vector2f{0.f , p1->getPlayerPos().y});

        if (p1->getPlayerPos().x + 100.f >= 800.f) p1->setPlayerPos(sf::Vector2f{700.f , p1->getPlayerPos().y});
        if (p1->getPlayerPos().y + 100.f >= 600.f) p1->setPlayerPos(sf::Vector2f{p1->getPlayerPos().x, 500.f});


    });

    p2->addPlayerEvents([&](){
        if (p2->getPlayerPos().y <= 0.f) p2->setPlayerPos(sf::Vector2f{p2->getPlayerPos().x , 0.f});
        if (p2->getPlayerPos().x <= 0.f) p2->setPlayerPos(sf::Vector2f{0.f , p2->getPlayerPos().y});

        if (p2->getPlayerPos().x + 100.f >= 800.f) p2->setPlayerPos(sf::Vector2f{700.f , p2->getPlayerPos().y});
        if (p2->getPlayerPos().y + 100.f >= 600.f) p2->setPlayerPos(sf::Vector2f{p2->getPlayerPos().x, 400.f});
    });

    window->addGameObjects(mm);
    window->addGameObjects(p1);
    window->addGameObjects(p2);

    window->run();

    return 0;
}