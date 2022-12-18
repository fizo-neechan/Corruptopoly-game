#pragma once
#include "headers.h"

class Game {
    private:
        sf::RenderWindow *window;
        sf::Event event;


    public:
        Game();
        ~Game();

        bool running();
        void update();
        void render();
};

Game::Game(){
    this->window = new sf::RenderWindow(sf::VideoMode(600.f, 700.f), "Hello ma niggs", sf::Style::Close | sf::Style::Titlebar);

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
        }
}

void Game::render(){
    this->window->clear();

    this->window->display();
}