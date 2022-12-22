#include "headers.h"

struct Player {
    char id;
    sf::Sprite playerSprite;
    sf::Vector2f moveVec;
    int money;

    CircularLinkedList<BoardCard>::Node<BoardCard> *boardPos;

    Player();
    
    void update();
    void render(sf::RenderTarget &target);

};

Player::Player(){
    this->money = 0;
    this->moveVec = sf::Vector2f(-70.f, 0.f);
}

void Player::update(){

}

void Player::render(sf::RenderTarget &target){
    target.draw(this->playerSprite);
}