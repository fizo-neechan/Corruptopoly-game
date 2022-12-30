#pragma once
#include "headers.h"
#include "Player.h"
#include "Button.h"
#include <algorithm>
#include <random>

/**
 * @brief class declared for the board
 * 
 */
class Board{
private:

    sf::Texture background[2];
    sf::Sprite sidePanel;
    sf::Text panel_currCardText[4];
    uint8_t panelState;

    sf::Texture boardTexture;
    sf::Sprite board;
    CircularLinkedList<BoardCard> BoardCards;
    CircularLinkedList<BoardCard>::Node<BoardCard> *jailCard;

    sf::Texture playerTextures[4];
    Player players[4];
    int currPlayer;

    sf::Texture rollbtn;
    sf::Texture buildbtn;
    sf::Texture buybtn;
    sf::Texture nextbtn;

    std::vector<Button> buttons0;
    std::vector<Button> buttons1;

    sf::Font GothamBlackReg;

    std::stack<DrawCard> deck;
    std::vector<DrawCard> drawnCards;

    void loadDeckFromFile();
    void shuffleCards();
    void initTextures();
    void loadBoardCards();
    int getDiceRoll();

public:
    Board();
    /**
     * @brief Construct a new Board object
     * Taking the input of position x and position y
     * 
     * @param posx 
     * @param posy 
     */
    Board(float posx, float posy);
    ~Board();

    void update(sf::Vector2i mousePos);
    void render(sf::RenderTarget &target);
};

/**
 * @brief Another Constructor that is initalizing elements of the board.
 * 
 */
Board::Board(){
    srand(time(0));
    
    this->initTextures();
    this->board.setTexture(boardTexture);
    this->board.setPosition(0.f, 0.f);

    this->loadDeckFromFile();
    this->shuffleCards();
    this->loadBoardCards();

    this->panelState = 0;
    this->sidePanel.setTexture(this->background[0]);
    this->sidePanel.setPosition(1024.f,0.f);

    for(size_t i = 0; i < 4; i++){
        this->players[i].playerSprite.setTexture(this->playerTextures[i]);
        this->players[i].playerSprite.setScale(0.07f,0.07f);
        this->players[i].playerSprite.setPosition(920.f,920.f);

        this->players[i].boardPos = this->BoardCards.head;

        this->players[i].moneyText.setFont(GothamBlackReg);
        this->players[i].moneyText.setColor(sf::Color::Black);
        this->players[i].moneyText.setCharacterSize(50);
        this->players[i].moneyText.setPosition(1250.f, 690.f + (80.f*i));

        this->panel_currCardText[i].setFont(GothamBlackReg);
        this->panel_currCardText[i].setColor(sf::Color::Black);
        this->panel_currCardText[i].setPosition(1024.f + 113.f, 70.f + (i*50.f));
        this->panel_currCardText[i].setCharacterSize(50);
        this->panel_currCardText[i].setStyle(sf::Text::Bold);
    }

    this->currPlayer = 0;

    buttons0.push_back(Button(1024.f + 195.f, 62.f, 1, rollbtn));
    buttons1.push_back(Button(1024.f + 113.f, 300.f, 2, buybtn));
    buttons1.push_back(Button(1024.f + 113.f, 500.f, 3, buildbtn));
    buttons1.push_back(Button(1024.f + 113.f, 700.f, 4, nextbtn));

    jailCard = this->BoardCards.head;
    while(this->jailCard->data.ID != 5)
        this->jailCard = this->jailCard->next;

    this->GothamBlackReg.loadFromFile("Gotham Black Regular.ttf");
}

/**
 * @brief Constructor that creates the board and sets everything to default.
 * 
 * @param posx 
 * @param posy 
 */
Board::Board(float posx, float posy){
    this->initTextures();
    this->board.setTexture(boardTexture);
    this->board.setPosition(posx, posy);

    this->panelState = 0;
    this->sidePanel.setTexture(this->background[0]);
    this->sidePanel.setPosition(0.f,0.f);

    for(size_t i = 0; i < 4; i++){
        this->players[i].playerSprite.setTexture(this->playerTextures[i]);
        this->players[i].playerSprite.setScale(0.07f,0.07f);
        this->players[i].playerSprite.setPosition(920.f,920.f);
    }
}

Board::~Board(){

}

/**
 * @brief Function that is loading all the game textures.
 * 
 */
void Board::initTextures(){
    if(! this->boardTexture.loadFromFile("Textures\\Background\\Board-2.png")){
        std::cout << "Asset not found:: Board.jpeg";
        throw 404;
    }
    if(!this->background[0].loadFromFile("Textures\\Background\\backgroundTexture-state0.png")){
        std::cout << "file not found :: backgroundTexture-state0.png";
        throw 404;
    }
    if(!this->background[1].loadFromFile("Textures\\Background\\backgroundTexture-state1.png")){
        std::cout << "file not found :: backgroundTexture-state1.png";
        throw 404;
    }
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
    if(!this->rollbtn.loadFromFile("Textures\\Background\\Roll-btn.png")){
        std::cout << "file not found :: Roll-btn.png";
        throw 404;
    }
    if(!this->buildbtn.loadFromFile("Textures\\Background\\Build-btn.png")){
        std::cout << "file not found :: Build-btn.png";
        throw 404;
    }
    if(!this->buybtn.loadFromFile("Textures\\Background\\Buy-btn.png")){
        std::cout << "file not found :: Buy-btn.png";
        throw 404;
    }
    if(!this->nextbtn.loadFromFile("Textures\\Background\\Next-btn.png")){
        std::cout << "file not found :: Next-btn.png";
        throw 404;
    }
}

/**
 * @brief Function to load the CORRUPTOPOLY Cards, used for prompts.
 * 
 */
void Board::loadDeckFromFile(){
    std::fstream f("Cards\\drawCards.txt", std::ios::in);
    while(!f.eof()){
        DrawCard newCard;

        std::getline(f, newCard.command, ',');
        std::getline(f, newCard.text);

        this->deck.push(newCard);
    }
}

/**
 * @brief Function to shuffle the cards in the game.
 * 
 */
void Board::shuffleCards(){
    std::shuffle(this->drawnCards.begin(), this->drawnCards.end(), std::default_random_engine(time(0)));
    for(auto it: this->drawnCards)
        this->deck.push(it);

    this->drawnCards.clear();
}

/**
 * @brief Function to load the cards into the board.
 * 
 */
void Board::loadBoardCards(){
    std::fstream f("Cards\\Game Vals.txt", std::ios::in);
    while(!f.eof()){
        std::string name;
        std::string id;
        std::string value;

        std::getline(f, name, ',');
        std::getline(f, id, ',');
        std::getline(f, value);

        BoardCard newCard(name, std::stoi(id), std::stoi(value));
        this->BoardCards.insert_back(newCard);
    }
}

/**
 * @brief Function to role the dice
 * 
 * @return int, a value between 1 and 6 
 */
int Board::getDiceRoll(){
    return (rand() % 6) + 1;
}

/**
 * @brief The main update function that takes the mouse input and then
 * performs the update functions, traverses the board based on the dice roll to then prompt the user (sprites)
 * 
 * @param mousePos 
 */
void Board::update(sf::Vector2i mousePos){
    bool turntaken = 0;
    DrawCard drawnCard;
    BoardCard *currCard = &(this->players[this->currPlayer].boardPos->data);
    if(this->deck.empty())
        this->shuffleCards();

    if(this->panelState == 0){
        if(mousePos.x > 1024){
            for(auto btn: this->buttons0){
                if(btn.isClicked(mousePos)){
                    if(btn.getId() == 1){
                        int diceRoll = this->getDiceRoll();
                        this->players[currPlayer].move(diceRoll);
                        turntaken = 1;
                        break;
                    }
                }
            }
        } else return;

        if(turntaken){
            currCard = &(this->players[currPlayer].boardPos->data);
            if(currCard->value == -1){
                if(currCard->ID == -1){
                    drawnCard = this->deck.top();
                    std::cout << drawnCard.text << std::endl;
                    this->deck.pop();
                } else if(currCard->ID == 5){
                    this->players[this->currPlayer].money -= 200;
                } else if(currCard->ID == 15){
                    this->players[this->currPlayer].boardPos = jailCard;
                    this->players[this->currPlayer].money -= 200;
                }

                if(currPlayer == 3) currPlayer = 0;
                else currPlayer++;

            } else {
                this->panelState = 1;
            }
        }
    }
    if(panelState == 1){
        bool cahnegPlayer = 0;
        if(mousePos.x > 1024){
            for(auto btn: this->buttons1){
                if(btn.isClicked(mousePos)){
                    if(btn.getId() == 2){
                        if(currCard->owner == 'u'){
                            this->players[this->currPlayer].money -= currCard->value;
                            currCard->owner = currPlayer + '0';
                            cahnegPlayer = 1;
                        }
                    } else if(btn.getId() == 3){
                        if(currCard->owner - '0' == currPlayer){
                            if(currCard->houses == 4){
                                currCard->buildings += 1;
                                currCard->houses = 0;
                            } else
                                currCard->houses += 1;
                            
                            currCard->value += currCard->value / 3;
                            cahnegPlayer = 1;
                        }
                    } else if(btn.getId() == 4){
                        if(currCard->owner != 'u' && currCard->owner - '0' != currPlayer){
                            std::cout << "next";
                            this->players[currPlayer].money -= currCard->value / 10;
                            this->players[currCard->owner - '0'].money += currCard->value / 10;
                        }

                        cahnegPlayer = 1;
                    }

                    if(cahnegPlayer){
                        if(currPlayer == 3) currPlayer = 0;
                        else currPlayer++;

                        panelState = 0;
                    }

                }
            }
        }
    }

    this->sidePanel.setTexture(this->background[this->panelState]);
    this->panel_currCardText[0].setString(currCard->name);
    this->panel_currCardText[1].setString("Value: " + std::to_string(currCard->value));
    this->panel_currCardText[2].setString((currCard->owner == 'u' ? "unowned" : "Owner: " + currCard->owner));
    this->panel_currCardText[3].setString("Houses: " + std::to_string(currCard->houses));

    for(int i = 0; i < 4; i++)
        this->players[i].update();


    std::cout << currCard->name << '/' << currCard->value << '/' << currCard->owner << '/' << currCard->ID << std::endl;
}

/**
 * @brief the function that is performing the main task, it renders out the entire board for the user.
 * 
 * @param target 
 */
void Board::render(sf::RenderTarget &target){
    target.draw(this->board);
    target.draw(this->sidePanel);

    for(size_t i = 0; i < 4; i++)
        target.draw(this->players[i].playerSprite);

    if(this->panelState == 0){
        for(auto btn: this->buttons0)
            btn.render(target);

        for(size_t i = 0; i < 4; i++)
            target.draw(this->players[i].moneyText);

    }
    else{
        for(auto btn: this->buttons1)
            btn.render(target);

        for(size_t i = 0; i < 4; i++)
            target.draw(panel_currCardText[i]);
    }

    target.draw(sf::Text("Current Player: " + std::to_string(this->currPlayer), GothamBlackReg, 20));
}