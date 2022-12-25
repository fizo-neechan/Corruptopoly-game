#pragma once
#include "headers.h"
#include "Player.h"
#include <algorithm>
#include <random>

class Board{
private:



    sf::Texture boardTexture;

    sf::Sprite board;


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
    this->board.setPosition(posx, posy);
}

Board::~Board(){

}

void Board::initTextures(){
    if(! this->boardTexture.loadFromFile("Textures\\Background\\Board-2.png")){
        std::cout << "Asset not found:: Board.jpeg";
        throw 404;
    }


}





void Board::update(){
    
}

void Board::render(sf::RenderTarget &target){
    target.draw(this->board);
}


