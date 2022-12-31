#pragma once
#include <iostream>

/**
 * @brief struct for the drawing cards
 * 
 */
struct DrawCard {
    std::string command;
    std::string text;

    DrawCard(std::string command, std::string text){
        this->command = command;
        this->text = text;
    }  

    DrawCard(){
        
    }
};




/**
 * !card commands
 * 
 * * d <amount> <person>
 * deposit amount to person
 * peron => b(bank), l/r(player side), *(all players), o(owner)
 * 
 * * g <amount> <person>
 * get amount from person
 * peron => b(bank), l/r(player side), *(all players)
 * 
 * * go <id>
 * go to place
 * id => place id eg: jail, sialkot, etc...
 * 
 * * dn
 * do nothing
 * 
 */