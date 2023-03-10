#include "headers.h"

/**
 * @brief Player struct
 * 
 */
struct Player {
    char id;
    sf::Sprite playerSprite;
    sf::Vector2f moveVec;
    int money;
    sf::Text moneyText;

    CircularLinkedList<BoardCard>::Node<BoardCard> *boardPos;

    Player();
    
    void update();
    void render(sf::RenderTarget &target);
    void move(int roll);
};

/**
 * @brief Construct a new Player object
 * 
 */
Player::Player(){
    this->money = 200;
    this->moveVec = sf::Vector2f(-70.f, 0.f);

    this->moneyText.setColor(sf::Color::Black);
    this->moneyText.setCharacterSize(50);
}

/**
 * @brief update the player properties
 * 
 */
void Player::update(){
    this->moneyText.setString(std::to_string(this->money));
}

/**
 * @brief render the Player sprite
 * 
 * @param target 
 */
void Player::render(sf::RenderTarget &target){
    target.draw(this->playerSprite);
}

/**
 * @brief move the player n steps where n = roll
 * 
 * @param roll 
 */
void Player::move(int roll){
    for(int i = 0; i < roll; ++i){
        this->boardPos = this->boardPos->next;
        this->playerSprite.setPosition(this->playerSprite.getPosition() + this->moveVec);

        if(this->boardPos->data.ID == 0)
            this->money += 200;

        if(this->boardPos->data.ID == 0)
            this->moveVec = sf::Vector2f(-500.f, 0.f);
        else if(this->boardPos->data.ID == 5)
            this->moveVec = sf::Vector2f(0.f, -500.f);
        else if(this->boardPos->data.ID == 10)
            this->moveVec = sf::Vector2f(500.f, 0.f);
        else if(this->boardPos->data.ID == 15)
            this->moveVec = sf::Vector2f(0.f, 500.f);
    }
}