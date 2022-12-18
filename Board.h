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


    void update();
    void render(sf::RenderTarget &target);
};

Board::Board(){
    this->initTextures();
    this->board.setTexture(boardTexture);
    this->board.setPosition(0.f, 0.f);

}

Board::Board(float posx, float posy){
    this->initTextures();
    this->board.setTexture(boardTexture);
    this->board.setScale(0.1f, 0.1f);
    this->board.setPosition(posx, posy);

}

Board::~Board(){

}

void Board::initTextures(){
    if(! this->boardTexture.loadFromFile("Textures\\Board-1.png")){
        std::cout << "Asset not found:: Board.jpeg";
        throw 404;
    }

}

void Board::update(){

}

void Board::render(sf::RenderTarget &target){
    target.draw(this->board);
}


