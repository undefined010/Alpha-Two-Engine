#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include "GameObjs.h"
#include "TileMap.h"

#include <SFML/Graphics.hpp>

#include <memory>
#include <vector>
#include <functional>

#define FPS_ 60

#define WINDOW_WIDTH_FIXED  800
#define WINDOW_HEIGHT_FIXED 600

#define WINDOW_TITLE "ALPHA-2"

namespace alpha
{
    class Window 
    {
        private:
            float FPS;

        private:
            std::unique_ptr<sf::RenderWindow> windowRenderer;
            std::unique_ptr<sf::Event> windowEvent;
            sf::Vector2u size;
            sf::Clock cl;
            game::TileMap mm;

        public:
            sf::RenderWindow& getMainWindow();

        private:
            std::vector<game::Object*> objects; 
            std::vector<std::function<void()>> mouseEvents;

        public:
            void addGameObjects(game::Object* gameObj);
            void removeGameObjects();
            std::vector<game::Object*> getGameObjects;

        public:
            float getWindowFrameRate() const;
            void setWindowFrameRate(float f);
            sf::Vector2i getWindowPos() const ; 
            void setWindowPos(const sf::Vector2i& p);

        public:
            void mouseEventHandler(const std::function<void()>& f);

        public:
            void clearObjects();
            void renderAll();
            void updateAll();
            void run();
            void end();

        public:
            Window();
            Window(uint16_t w_ , uint16_t h, const std::string& title , float f);
            ~Window();

        
    };
}

#endif