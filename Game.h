#pragma once
#include "headers.h"
#include "Board.h"

class Game {
    private:
        sf::RenderWindow *window;
        sf::Event event;
        
        Board board;

        sf::Texture background[2];
        sf::Sprite sidePanel;
        uint8_t panelState;

        sf::Texture playerTextures[4];
        Player players[4];

        std::stack<DrawCard> deck;
        std::vector<DrawCard> drawnCards;

        
        void initTextures();
        void loadDeckFromFile();
        void shuffleCards();

    public:
        Game();
        ~Game();

        bool running();
        void update();
        void render();
};

Game::Game(){
    this->window = new sf::RenderWindow(sf::VideoMode(1600.f, 1024.f), "Hello ma niggs", sf::Style::Close | sf::Style::Titlebar);
    
    this->panelState = 0;
    this->sidePanel.setTexture(this->background[0]);
    this->sidePanel.setPosition(1024.f,0.f);

    for(size_t i = 0; i < 4; i++){
        this->players[i].playerSprite.setTexture(this->playerTextures[i]);
        this->players[i].playerSprite.setScale(0.07f,0.07f);
        this->players[i].playerSprite.setPosition(920.f,920.f);
    }
}

Game::~Game(){
    delete [] this->window;
}

bool Game::running(){
    return this->window->isOpen();
}

void Game::initTextures(){
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

void Game::loadDeckFromFile(){
    std::fstream f("Cards\\drawCards.txt", std::ios::in);
    while(!f.eof()){
        DrawCard newCard;

        std::getline(f, newCard.command, ',');
        std::getline(f, newCard.text, ',');

        this->deck.push(newCard);
    }
}

void Game::shuffleCards(){
    std::shuffle(this->drawnCards.begin(), this->drawnCards.end(), std::default_random_engine(time(0)));
    for(auto it: this->drawnCards)
        this->deck.push(it);

    this->drawnCards.clear();
}

void Game::update(){
        while (this->window->pollEvent(this->event)){
            if (event.type == sf::Event::Closed)
                this->window->close();
        }

        this->board.update();
}

void Game::render(){
    this->window->clear();
    
    this->board.render(*this->window);
    this->window->draw(sidePanel);

     for(size_t i = 0; i < 4; i++)
        this->window->draw(this->players[i].playerSprite);

    this->window->display();
}