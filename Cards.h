#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <array>

using namespace std;

class Player;

class Cards {

public:
    //Constructor
    Cards();
    Cards(string name, string goods, string action);
    Cards(const Cards& object);//Copy constructor
    Cards& operator = (const Cards& object);//Assignment Operator
    ~Cards();//Destructor
    //Stream Insertion Operator
    friend ostream& operator<<(ostream& output, const Cards& object);
private:
    string cardName;
    string cardGoods;
    string cardAction;
};

class Deck {

public:
    //Constructor
    Deck();
    //Copy constructor
    Deck(const Deck& object);
    Deck& operator = (const Deck& object);//Assignment Operator
    ~Deck();//Destructor
    //Stream Insertion Operator
    friend ostream& operator<<(ostream& output, const Deck& object);
    Cards* draw();
    //Get Method
    vector<Cards*> getDeck();
    //Set Method
    void setDeck(Cards* object);
private:
    vector<Cards*> vectorDeck;
};

class Hand {

public:
    //Constructor
    Hand();
    //Copy constructor
    Hand(const Hand& object);
    //Assignment Operator
    Hand& operator = (const Hand& object);
    //Destructor
    ~Hand();
    //Stream Insertion Operator
    friend ostream& operator<<(ostream& output, const Hand& object);
    void exchange(int index, Player* player);
    //Get Method
    vector<Cards*> getHand();
    //Set Method
    void setHand(Cards* object);
    void setCard(int index, Deck deck);
private:
    vector<Cards*> hand;
};
#pragma once
