#pragma once
#include <SFML/Graphics.hpp>

class Button {
    private:
        sf::Sprite sprite;
        std::string text;
        int id;
        uint8_t state;


    public:


        Button(float posx, float posy, int id, sf::Texture &texture);
        ~Button();

        bool isClicked(sf::Vector2f pos);
        void render(sf::RenderTarget &target);


}; 


Button::Button(float posx, float posy, int id, sf::Texture &texture)
:state(0), id(id)
{
    this->sprite.setTexture(texture);  
    this->sprite.setPosition(posx, posy);
}

Button::~Button(){

}

bool Button::isClicked (sf::Vector2f mousePos) {
    if (mousePos.x> this->sprite.getPosition().x && mousePos.x<( this->sprite.getPosition().x +  this->sprite.getTextureRect().width)) {
        if(mousePos.y> this->sprite.getPosition().y && mousePos.y<( this->sprite.getPosition().y +  this->sprite.getTextureRect().height)) {
            return 1;
        }
    }
    return 0;
}

void Button::render(sf::RenderTarget &target){
    target.draw(this->sprite);
}

