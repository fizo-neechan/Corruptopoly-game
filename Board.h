#pragma once
#include "headers.h"
#include "Player.h"
#include "Button.h"
#include <algorithm>
#include <random>

class Board{
private:

    sf::Texture background[2];
    sf::Sprite sidePanel;
    uint8_t panelState;

    sf::Texture boardTexture;
    sf::Sprite board;
    CircularLinkedList<BoardCard> BoardCards;

    sf::Texture playerTextures[4];
    Player players[4];

    sf::Texture rollbtn;
    std::vector<Button> buttons0;
    std::vector<Button> buttons1;

    std::stack<DrawCard> deck;
    std::vector<DrawCard> drawnCards;

    void loadDeckFromFile();
    void shuffleCards();
    void initTextures();
    void loadBoardCards();

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

    this->loadDeckFromFile();
    this->shuffleCards();
    this->loadBoardCards();

    this->panelState = 0;
    this->sidePanel.setTexture(this->background[0]);
    this->sidePanel.setPosition(1024.f,0.f);

    for(size_t i = 0; i < 4; i++){
        this->players[i].playerSprite.setTexture(this->playerTextures[i]);
        this->players[i].playerSprite.setScale(0.07f,0.07f);
        this->players[i].playerSprite.setPosition(920.f,920.f);
        this->players[i].boardPos = this->BoardCards.head;
    }

    buttons0.push_back(Button(1024.f + 195.f, 62.f, 1, rollbtn));
    buttons1.push_back(Button(1024.f + 195.f, 62.f, 1, rollbtn));
}

Board::Board(float posx, float posy){
    this->initTextures();
    this->board.setTexture(boardTexture);
    this->board.setPosition(posx, posy);

    this->panelState = 0;
    this->sidePanel.setTexture(this->background[0]);
    this->sidePanel.setPosition(0.f,0.f);

    for(size_t i = 0; i < 4; i++){
        this->players[i].playerSprite.setTexture(this->playerTextures[i]);
        this->players[i].playerSprite.setScale(0.07f,0.07f);
        this->players[i].playerSprite.setPosition(920.f,920.f);
    }
}

Board::~Board(){

}

void Board::initTextures(){
    if(! this->boardTexture.loadFromFile("Textures\\Background\\Board-2.png")){
        std::cout << "Asset not found:: Board.jpeg";
        throw 404;
    }
    if(!this->background[0].loadFromFile("Textures\\Background\\backgroundTexture-state0.png")){
        std::cout << "file not found :: backgroundTexture-state0.png";
        throw 404;
    }
    // if(!this->background[1].loadFromFile("Textures\\Background\\backgroundTexture-state1.png")){
    //     std::cout << "file not found :: backgroundTexture-state1.png";
    //     throw 404;
    // }
    if(!this->playerTextures[0].loadFromFile("Textures\\Sprites\\Bat.png")){
        std::cout << "file not found :: Bat.png";
        throw 404;
    }
    if(!this->playerTextures[1].loadFromFile("Textures\\Sprites\\Bullet.png")){
        std::cout << "file not found :: Bullet.png";
        throw 404;
    }
    if(!this->playerTextures[2].loadFromFile("Textures\\Sprites\\Tank.png")){
        std::cout << "file not found :: Tank.png";
        throw 404;
    }
    if(!this->playerTextures[3].loadFromFile("Textures\\Sprites\\Tiger.png")){
        std::cout << "file not found :: Tiger.png";
        throw 404;
    }
    if(!this->rollbtn.loadFromFile("Textures\\Background\\Roll-btn.png")){
        std::cout << "file not found :: Roll-btn.png";
    }

    



}

void Board::loadDeckFromFile(){
    std::fstream f("Cards\\drawCards.txt", std::ios::in);
    while(!f.eof()){
        DrawCard newCard;

        std::getline(f, newCard.command, ',');
        std::getline(f, newCard.text, ',');

        this->deck.push(newCard);
    }
}

void Board::shuffleCards(){
    std::shuffle(this->drawnCards.begin(), this->drawnCards.end(), std::default_random_engine(time(0)));
    for(auto it: this->drawnCards)
        this->deck.push(it);

    this->drawnCards.clear();
}

void Board::update(){
    if(this->deck.empty())
        this->shuffleCards();

    
}

void Board::loadBoardCards(){
    std::fstream f("Cards\\drawCards.txt", std::ios::in);
    while(!f.eof()){
        std::string name;
        std::string id;
        std::string value;

        std::getline(f, name, ',');
        std::getline(f, id, ',');
        std::getline(f, value, ',');

        //  !ERROR STOI FIX
        BoardCard newCard(name, std::stoi(id), std::stoi(value));
        this->BoardCards.insert_back(newCard);
    }
}

void Board::render(sf::RenderTarget &target){
    target.draw(this->board);
    target.draw(this->sidePanel);

    for(size_t i = 0; i < 4; i++)
        target.draw(this->players[i].playerSprite);

    for(auto btn: this->buttons0)
    for(auto btn: this->buttons1)
        btn.render(target);
}


