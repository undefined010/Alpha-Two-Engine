#include "Blocks.h"
#include <iostream>
static int c = 0;

Block::Block(uint32_t w , uint32_t h) : window_width{w} , window_height{h}
{
    this->texture = new sf::Texture();
}

Block::~Block()
{
    this->sprites.clear();
    this->positions.clear();
    delete texture;
}

void Block::create_sprites(const std::string &texture_path , const sf::Vector2f &pos_)
{

    if (!this->texture->loadFromFile(texture_path)) return;

    sf::Sprite s; 

    s.setTexture(*this->texture);
    s.setPosition(pos_);
     
    this->sprites.push_back(s);
    this->positions.push_back(s.getPosition());

    printf("done %d\n",++c);
    return;
}

void Block::set_sprite(int row , const std::string &path)
{
    for (int i = 0 ; i < (int)(this->window_height); ++i) {
        for (int k = 0 ; k < (int)(this->window_width ); ++k) {
            if (i == row) {
                create_sprites(path,sf::Vector2f(k * 100.f,i * 100.f));
                printf("green\n");
            }

        }
    }    
}


void Block::update(float deltaTime)
{
    if (deltaTime) return;
}

void Block::render(sf::RenderWindow &window) 
{
    for (auto &i : this->sprites) {
        
        window.draw(i);
        
    }
}

