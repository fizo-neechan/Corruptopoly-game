#pragma once
#include <SFML/Graphics.hpp>

class Button {
    private:
        sf::Sprite sprite;
        int id;
        bool state;

    public:


        Button(float posx, float posy, int id, sf::Texture &texture);
        Button();
        ~Button();

        bool isClicked(sf::Vector2i pos);
        void render(sf::RenderTarget &target);


        int getId();
        void toggle();


}; 

Button::Button(){

}

Button::Button(float posx, float posy, int id, sf::Texture &texture)
:state(1), id(id)
{
    this->sprite.setTexture(texture);  
    this->sprite.setPosition(posx, posy);


    std::cout << "\nbtn Pos: " << this->sprite.getPosition().x << ' ' << this->sprite.getPosition().y << ' '
                << this->sprite.getTextureRect().width << ' ' << this->sprite.getTextureRect().height << std::endl;
}

Button::~Button(){

}

bool Button::isClicked (sf::Vector2i mousePos) {
    if(this->state){
        if (mousePos.x> this->sprite.getPosition().x && mousePos.x<( this->sprite.getPosition().x +  this->sprite.getTextureRect().width)) {
            if(mousePos.y> this->sprite.getPosition().y && mousePos.y<( this->sprite.getPosition().y +  this->sprite.getTextureRect().height)) {
                return 1;
            }
        }
    }
    return 0;
}

void Button::render(sf::RenderTarget &target){
    if(this->state)
        target.draw(this->sprite);
}

int Button::getId(){
    return this->id;
}

void Button::toggle(){
    this->state != this->state;
}