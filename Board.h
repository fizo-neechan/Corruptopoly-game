#include "headers.h"
#include "Player.h"

class Board{
private:

    sf::Texture background[2];
    sf::Sprite sidePanel;
    uint8_t panelState;

    sf::Texture boardTexture;
    sf::Texture playerTextures[4];

    sf::Sprite board;
    Player players[4];

    std::stack<DrawCard> deck;

    void loadDeckFromFile();
    void shuffleCards();
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

    this->panelState = 0;
    this->sidePanel.setTexture(this->background[0]);
    this->sidePanel.setPosition(1024.f,0.f);

    for(size_t i = 0; i < 4; i++){
        this->players[i].playerSprite.setTexture(this->playerTextures[i]);
        this->players[i].playerSprite.setScale(0.07f,0.07f);
        this->players[i].playerSprite.setPosition(920.f,920.f);
    }
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

}

void Board::loadDeckFromFile(){
    std::fstream f();

}



void Board::update(){

}

void Board::render(sf::RenderTarget &target){
    target.draw(this->board);
    target.draw(this->sidePanel);

    for(size_t i = 0; i < 4; i++)
        target.draw(this->players[i].playerSprite);
}


