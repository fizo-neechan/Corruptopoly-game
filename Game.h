#pragma once
#include "headers.h"
#include "Board.h"

class Game {
    private:

        sf::Texture background[2];
        sf::Sprite sidePanel;
        uint8_t panelState;

        sf::RenderWindow *window;
        sf::Event event;

        Board board;
        
    public:
        Game();
        ~Game();

        bool running();
        void update();
        void render();
};

Game::Game(){
    this->window = new sf::RenderWindow(sf::VideoMode(1600.f, 1024.f), "Corruptopoly - A Game by Law Abiding Citizens", sf::Style::Close | sf::Style::Titlebar);
    
}   

Game::~Game(){
    delete [] this->window;
}

bool Game::running(){
    return this->window->isOpen();
}

void Game::update(){
        while (this->window->pollEvent(this->event)){
            if (event.type == sf::Event::Closed)
                this->window->close();
            if(event.type == sf::Event::MouseButtonPressed){
                sf::Vector2i mousePos = sf::Mouse::getPosition(*this->window);
                std::cout << "mouse button pressed << " << mousePos.x << ',' << mousePos.y << std::endl;
                this->board.update(mousePos);
            }
        }
}

void Game::render(){
    this->window->clear();
    this->board.render(*this->window);


    

    this->window->display();
}