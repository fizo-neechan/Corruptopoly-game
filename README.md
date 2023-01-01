# Corruptopoly - A Game by Law Abiding Citizens

Game created by @fizo_neechan and @r2ja


Corrupt-o-poly is a parody version of the popular board game Monopoly, inspired by the political climate of a certain country. The project was created in Visual Studio Code using C++ and SFML for the GUI, with all assets created using Photoshop and Dall-E. The game features a game board, property cards, prompt cards, and graphics, and was implemented using a circular linked list for traversal of the game board and a stack for drawing prompt cards. The group plans to further develop the project in the future and release it publicly under fair-use guidelines. The time complexity for the circular linked list and stack are both O(n).

The basic data structures used in the making of the game are:
 - Stack - To emulate a deck of drawable cards
 - Circular linked list - To emulate the board and board positions and to be able to easily move players around the board
 - Arrays - if you consider them data structures :)
 
 
 ### All the Game files include:
 - Game.h
 - Board.h
 - Button.h
 - DrawCard.h
 - BoardCard.h
 - Player.h
 - CircularLinkedList.h
 - main.cpp

 
 
 
 
 ### Main functionality of the Game:
 
 All the sprite classes contain an update function which updates the sprite positions and class attributes.
 > void update()
 
 Rest of the games updates are handled in the update function of the *Board.h* file
 > void Board::update(sf::Vector2f mousePos) {...}
 
 ### How to compile the Game:
 
 First of all, you need to install SFML library on your system, to be able to compile the files
 
 The DLL's are already included in the repo, so after installing SFML run the following commands:
 
 compile the files:
 > g++ -c main.cpp -IC:/SFML-2.5.1/include
 
 link the linker:
 > g++ main.o -o main -LC:/SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system
 
 run the created exe:
 > ./main
 
