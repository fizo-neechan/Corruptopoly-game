#include <iostream>
#include <fstream>
#include <algorithm>
#include <time.h>
#include <random>

void loadBoardCards(){
    std::fstream f("Cards\\Game Vals.txt", std::ios::in);
    while(!f.eof()){
        std::string name;
        std::string id;
        std::string value;

        std::getline(f, name, ',');
        std::getline(f, id, ',');
        std::getline(f, value);

        // //  !ERROR STOI FIX
        // BoardCard newCard(name, std::stoi(id), std::stoi(value));
        // this->BoardCards.insert_back(newCard);
        std::cout << name << '/' << std::stoi(id) << '/' << std::stoi(value) << std::endl;
    }
}

int main(){

loadBoardCards();

    



    return 0;
}