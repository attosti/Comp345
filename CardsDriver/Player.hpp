#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "Map.hpp"
#include "Cards.hpp"
#include "BiddingFacility.hpp"

using namespace std;

//class Cards;

class Player {

public:
    //Constructor
    Player();
    Player(string name,int coin,int move,vector<Territory*> territory,vector<Cards*> handCard, BiddingFacility* bid);
    //Copy constructor
    Player(const Player& object);
    //Assignment Operator
    Player& operator = (const Player&);
    //Destructor
    ~Player();

    //Method Required by Part 2
    void PayCoin(int coin);
    void PlaceNewArmies(Territory* territory,int army);
    void MoveArmies(Territory* A,Territory* B,int army);
    void MoveOverLand(Territory* A, Territory* B,int army);
    void BuildCity(Territory* territory);
    void DestroyArmy(Territory* territory,int army);

    //Get Method
    string getName();
    int getMove();
    int getCoin();
    vector<Territory*> getTerritory();
    vector<Cards*> getHandCard();

    //Set Method
    void setArmy(int army);
    void setMove(int move);
    void setCoin(int coin);
    void setHandCard(Cards* object);

    //Service Method
    bool check_territory(Territory* object);
    void printTerritory();

    //Stream Insertion Operator
    friend ostream& operator<<(ostream& output, const Player& object);

private:
    string name;
    int coin,move,army,cityToken;
    vector<Territory*> territory;
    vector<Cards*> handCard;
    BiddingFacility* bid;

};

