/**
 * @file            Corruptopoly - Main Game
 * @author          Faizan Haq - 2021528 // Raja Ata Ul Karim 2021528
 * @brief           The game comprises of two Data Structures and makes use of SFML to create a GUI based game.
 * @version         1.0
 * @date            2022-12-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include "headers.h"
#include "Board.h"

/**
 * @brief Class of the main Game.
 * 
 */
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

/**
 * @brief Construct a new Game:: Game objectFunction that opens the main window of the game using SFML.
 * 
 */
Game::Game(){
    this->window = new sf::RenderWindow(sf::VideoMode(1600.f, 1024.f), "Corruptopoly - A Game by Law Abiding Citizens", sf::Style::Close | sf::Style::Titlebar);
    
}   

/**
 * @brief Destroy the Game:: Game Object
 * Deconstructor that deletes the main window.
 * 
 */
Game::~Game(){
    delete [] this->window;
}

/**
 * @brief Function that checks whether or not the window is open or not using Bool.
 * 
 * @return true 
 * @return false 
 */
bool Game::running(){
    return this->window->isOpen();
}


/**
 * @brief Update function that updates aspects of the game.
 * 
 */
void Game::update(){
        while (this->window->pollEvent(this->event)){
            // close the window if x button pressed
            if (event.type == sf::Event::Closed)
                this->window->close();
            // only update the game board if the mouse button is pressed
            if(event.type == sf::Event::MouseButtonPressed){
                sf::Vector2i mousePos = sf::Mouse::getPosition(*this->window);
                std::cout << "mouse button pressed << " << mousePos.x << ',' << mousePos.y << std::endl;
                this->board.update(mousePos);
            }
        }
}

/**
 * @brief Using this function the game will render all the other sprites.
 * 
 */
void Game::render(){
    this->window->clear();
    this->board.render(*this->window);


    

    this->window->display();
}