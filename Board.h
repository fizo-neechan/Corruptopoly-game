#include "headers.h"

class Board{
private:

    sf::Texture backgroundTexture;
    sf::Texture boardTexture;
    sf::Texture playerTextures[4];

    sf::Sprite board;
    sf::Sprite players[4];



    void initTextures();
public:
    Board();
    Board(float posx, float posy);
    ~Board();
};

Board::Board(){

}

Board::Board(float posx, float posy){

}

Board::~Board(){

}
