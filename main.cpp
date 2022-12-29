#include "headers.h"
#include "Game.h"

/**
 * @brief The main function that updates and renders the game while it's running.
 * 
 * @return int 
 */
int main()
{
    Game game;

    while (game.running()){
        game.update();
        game.render();
    }

    return 0;
}