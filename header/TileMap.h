#ifndef TILE_MAP_H_
#define TILE_MAP_H_

#include <vector>
#include <utility>
#include <SFML/Graphics.hpp>

#define WIDTH_  800
#define HEIGHT_ 600

namespace game
{
    class TileMap
    {
        private:
            std::vector<std::pair<std::string,sf::Sprite>> sprites_data_vec;
            sf::Texture* texture;
        
        public:
            sf::Sprite getSprite(const std::string& p , const sf::Vector2f& pos);
            void set_map(sf::RenderWindow& window);

        public:
            const std::vector<std::pair<std::string,sf::Sprite>> getSpritesData() const;

        public:
            TileMap();
            ~TileMap();
    };
}

#endif