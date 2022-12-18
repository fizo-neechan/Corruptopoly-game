#pragma once
#include <iostream>


struct BoardCard {
    int ID;
    char owner;
    int value;

    uint8_t houses;
    uint8_t buildings;

    BoardCard(int id, int value)
        :owner('u'), houses(0), buildings(0)
    {
        this->ID = id;
        this->value = value;
    }
};


/**
 * ! CARD COMMANDS
 * 
 * * -1 => DRAW CARD FROM DECK
 * * 0 => empty slot, nothing to do
 */

