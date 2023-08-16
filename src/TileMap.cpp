#include "TileMap.h"

#include <array>

game::TileMap::TileMap()
{
    this->texture = new sf::Texture();
}

game::TileMap::~TileMap()
{
    delete this->texture;
}

sf::Sprite game::TileMap::getSprite(const std::string& p , const sf::Vector2f& pos)
{    
    if (!this->texture->loadFromFile(p)) exit(EXIT_FAILURE);

    sf::Sprite sprite_;
    sprite_.setTexture(*this->texture);
    sprite_.setPosition(pos);
    printf("texture loaded\n");
    return sprite_;

}

const std::vector<std::pair<std::string,sf::Sprite>> game::TileMap::getSpritesData() const
{
    return this->sprites_data_vec;
}

void game::TileMap::set_map(sf::RenderWindow& window)
{
    float py = 0.f;
    float px = 0.f;

    std::array<std::array<uint8_t, (uint8_t)(WIDTH_ / 100.f)>, (uint8_t)(HEIGHT_ / 100.f)> arr = {{
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {3, 3, 3, 3, 3, 3, 3, 3},
        
    }};

    for (unsigned long i = 0 ; i < arr.size() ; ++i) {

        py = i * 100.f;
        px = 0.f;
        
        for (unsigned long k = 0 ; k < arr.at(i).size() ; ++k) {

            if (arr.at(i).at(k) == 1){
                this->sprites_data_vec.push_back(std::make_pair("grass" , this->getSprite("/Users/ahmadodeh/Alpha-Two-Engine/assest/grass_background.png",sf::Vector2f(px,py))));
                window.draw(this->getSprite("/Users/ahmadodeh/Alpha-Two-Engine/assest/grass_background.png",sf::Vector2f(px,py)));

            }
            
            if (arr[i][k] == 3) {
                this->sprites_data_vec.push_back(std::make_pair("dirt" , this->getSprite("/Users/ahmadodeh/Alpha-Two-Engine/assest/dirt_background.png",sf::Vector2f(px,py))));
                window.draw(this->getSprite("/Users/ahmadodeh/Alpha-Two-Engine/assest/dirt_background.png",sf::Vector2f(px,py)));

            }

            px += 100.f;
        }
        
    }

}

