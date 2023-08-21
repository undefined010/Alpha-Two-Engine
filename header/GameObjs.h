#ifndef GAMEOBJS_H_
#define GAMEOBJS_H_

#include <SFML/Graphics.hpp>

namespace game
{
    class Object
    {
    
        public:
            virtual void update(float deltaTime) = 0;
            virtual void render(sf::RenderWindow& window) = 0;

        public:
            Object() = default;
            virtual ~Object() = default;
    };
}

#endif