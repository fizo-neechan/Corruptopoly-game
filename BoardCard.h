#pragma once
#include <iostream>


struct BoardCard {
    int ID;
    char owner;
    std::string name;

    int value;
    uint8_t houses;
    uint8_t buildings;

    BoardCard(std::string name, int id, int value)
        :owner('u'), houses(0), buildings(0)
    {
        this->name = name;
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

