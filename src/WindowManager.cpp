#include "WindowManager.h"

alpha::Window::Window()
{
    this->windowRenderer = std::make_unique<sf::RenderWindow>(sf::VideoMode(WINDOW_WIDTH_FIXED , WINDOW_HEIGHT_FIXED) , WINDOW_TITLE);
    this->windowEvent    = std::make_unique<sf::Event>();
    this->FPS = FPS_;

}

alpha::Window::Window(uint16_t w , uint16_t h, const std::string& title , float f)
{
    this->windowRenderer = std::make_unique<sf::RenderWindow>(sf::VideoMode(w , h) , title);
    this->windowEvent    = std::make_unique<sf::Event>();
    this->FPS = f;
}

alpha::Window::~Window()
{
    if (this->objects.size() == 0) return;

    size_t obj_size = this->objects.size();

    
    for (auto i : this->objects)
        delete i;
    
    this->objects.clear();
    this->mouseEvents.clear();
    this->keyBoardEvents.clear();

    fprintf(stdout, "deleted %lu objects\n" ,obj_size);
}

sf::RenderWindow& alpha::Window::getMainWindow()
{
    if (this->windowRenderer.get() == nullptr) exit(EXIT_FAILURE); 

    return *this->windowRenderer;

}

void alpha::Window::setWindowPos(const sf::Vector2i& p)
{
    if (this->windowRenderer.get() == nullptr) return;
    this->windowRenderer->setPosition(p);
}

sf::Vector2i alpha::Window::getWindowPos() const
{
    return this->windowRenderer->getPosition();
}

void alpha::Window::setWindowFrameRate(float f)
{
    if (f <= 0.f)
        this->FPS = FPS_;
    
    else
        this->FPS = f;
}

float alpha::Window::getWindowFrameRate() const
{
    return this->FPS;
}


void alpha::Window::addGameObjects(game::Object* gameObj)
{

    if (gameObj == nullptr)
        return;
    
    if (this->objects.size() < GAME_OBJECTS_LIMIT)
    {
        this->objects.push_back(gameObj);
    }

}

void alpha::Window::deleteObjects()
{
    for (auto i : this->objects)
    {
        delete i;
    }

    this->objects.clear();
}

void alpha::Window::removeGameObjects()
{
    if (!this->objects.size()) return;

    this->deleteObjects();
    
}

void alpha::Window::onLeftClick(const std::function<void()>& f)
{
    this->mouseEvents.push_back(f);
}

void alpha::Window::keyboardEventHandler(const std::function<void()>& f)
{
    this->keyBoardEvents.push_back(f);
}

void alpha::Window::renderAll()
{
    this->windowRenderer->clear(sf::Color::White);

    for (auto& i : this->objects)
    {
       i->render(*this->windowRenderer);
    }

    this->windowRenderer->display();
}

void alpha::Window::updateAll()
{
    if (this->cl.getElapsedTime().asSeconds() >= 1.0f / FPS)
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) for (const auto& m : this->mouseEvents) m();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) for (const auto& k : this->keyBoardEvents) k();

        for (auto& i : this->objects) i->update();
    }
    else 
    {
        sf::Time sleepTime = sf::seconds((1.0f / FPS) - this->cl.getElapsedTime().asSeconds());
        sleep(sleepTime);
    }
}

void alpha::Window::run()
{
    this->windowRenderer->setFramerateLimit(this->FPS >= 0.f ? this->FPS : FPS_);
    
    while (this->windowRenderer->isOpen())
    {
        while (this->windowRenderer->pollEvent(*this->windowEvent))
        {
            if (this->windowEvent->type == sf::Event::Closed)
            {
                this->deleteObjects();
                this->windowRenderer->close();
            }
        }

        this->updateAll();
        this->renderAll();
        
    }
}

void alpha::Window::end()
{
    if (this->windowRenderer.get() == nullptr)
        return;
    
    else
        this->windowRenderer->close();

}