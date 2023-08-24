#ifndef BLOCKS_H_
#define BLOCKS_H_

#include "GameObjs.h"
#include <memory>
#include <vector>


class Block : public game::Object
{
    private:
        std::vector<sf::Vector2f> positions;
        std::vector<sf::Sprite> sprites;
        std::unique_ptr<sf::Texture> texture;
        uint32_t window_width;
        uint32_t window_height;

    public:
        Block(uint32_t w , uint32_t h);
        ~Block();

    public:
        void update(float deltaTime);
        void render(sf::RenderWindow &window);
    
    public:
        void create_sprites(const std::string &texture_path, const sf::Vector2f &pos_);
        void set_sprite(int row , const std::string &path);
};


#endif