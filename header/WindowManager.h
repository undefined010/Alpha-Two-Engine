#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include "GameObjs.h"

#include <memory>
#include <vector>
#include <functional>

#define FPS_ 60.f

#define WINDOW_WIDTH_FIXED  800
#define WINDOW_HEIGHT_FIXED 600

#define WINDOW_TITLE "ALPHA-2"
#define GAME_OBJECTS_LIMIT 10

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

        public:
            sf::RenderWindow& getMainWindow();

        private:
            std::vector<game::Object*> objects; 
            std::vector<std::function<void()>> mouseEvents;
            std::vector<std::function<void()>> keyBoardEvents;

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
            void onLeftClick(const std::function<void()>& f);
            void keyboardEventHandler(const std::function<void()>& f);

        public:
            void deleteObjects();
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