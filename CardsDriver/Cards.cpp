#include <iostream>
#include <string>
#include "Cards.hpp"
#include "Player.hpp"
using namespace std;

/****** Card Class ******/

//Default Constructor
Cards::Cards() {
    cardName = "";
    cardGoods = "";
    cardAction = "";
}
//Constructor with parameter
Cards::Cards(string name, string goods, string action) {
    cardName = name;
    cardGoods = goods;
    cardAction = action;
}
//Copy Constructor
Cards::Cards(const Cards& object) {
    this->cardName = object.cardName;
    this->cardGoods = object.cardGoods;
    this->cardAction = object.cardAction;

}
//Assignment Operator
Cards& Cards::operator = (const Cards& object) {
    this->cardName = object.cardName;
    this->cardGoods = object.cardGoods;
    this->cardAction = object.cardAction;
    return *this;
}
//Destructor
Cards::~Cards() {};
//Stream Insertion Operator
ostream& operator<<(ostream& output, const Cards& object) {
    return output << "Card Name: <" << object.cardName << "> Card Goods: <" << object.cardGoods << "> Card Action: <" << object.cardAction <<">"<< endl;
}
/****** END ******/


/****** Deck Class ******/
//Default Constructor
Deck::Deck() {
    vector<Cards*> vectorDeck;
}
//Copy Constructor
// Deck::Deck(const Deck& object) {

//     for (int i = 0; i < object.vectorDeck.size(); i++) {
//         this->vectorDeck[i] = new Cards(*object.vectorDeck[i]);
//     }

// }
//Assignment Operator
Deck& Deck::operator=(const Deck& object) {

    for (int i = 0; i < object.vectorDeck.size(); i++) {
        this->vectorDeck[i] = new Cards(*object.vectorDeck[i]);
    }
    return *this;
}
//Destructor
Deck::~Deck() {
    for (int i = 0; i < vectorDeck.size(); i++) {
        delete vectorDeck[i];
        vectorDeck[i] = nullptr;
    }
}
//Stream Insertion Operator
ostream& operator<<(ostream& output, const Deck& object) {
    output << "Deck Cards : ";
    output << object.vectorDeck.size();
    for (int i = 0; i < object.vectorDeck.size(); i++) {
        output << i + 1;
        output <<" -- " <<*(object.vectorDeck[i]);
    }
    output << endl;
    return output;
}
//Draw Method
Cards* Deck::draw() {
    Cards* tempcard = new Cards(*(this->vectorDeck.front()));
    delete this->vectorDeck.front();
    this->vectorDeck.front() = nullptr;
    this->vectorDeck.erase(this->vectorDeck.begin());
    return tempcard;
}
//Get Method
vector<Cards*> Deck::getDeck() {
    return vectorDeck;
}
//Set Method
void Deck::setDeck(Cards* object) {
    this->vectorDeck.push_back(object);
}
/****** END ******/


/****** Hand Class ******/

//Default Constructor
Hand::Hand() {
    vector<Cards*> hand;
}
//Copy Constructor
Hand::Hand(const Hand& object) {

    for (int i = 0; i < object.hand.size(); i++) {
        this->hand[i] = new Cards(*object.hand[i]);
    }

}
//Assignment Operator
Hand& Hand::operator=(const Hand& object) {

    for (int i = 0; i < object.hand.size(); i++) {
        this->hand[i] = new Cards(*(object.hand[i]));
    }
    return *this;
}
//Destructor
Hand::~Hand() {
    for (int i = 0; i < hand.size(); i++) {
        delete hand[i];
        hand[i] = nullptr;
    }
}
//Stream Insertion Operator
ostream& operator<<(ostream& output, const Hand& object) {
    output << "Hand Cards on the table: \n\n";
    for (int i = 0; i < object.hand.size(); i++) {
        output << i+1;
        output <<" -- "<<*(object.hand[i]);
    }
    output << endl;
    return output;
}
//Set Method
void Hand::setHand(Cards* object) {
    this->hand.push_back(object);
}

void Hand::exchange(int index, Player* player) {
    //For Cost
    int cost;
    if (index == 1) {
        cost = 0;
    }
    if (index == 2 || index == 3) {
        cost = 1;
    }
    if (index == 4 || index == 5) {
        cost = 2;
    }
    if (index == 6) {
        cost = 3;
    }
    if (player->getCoin() < cost) {
        cout << player->getName() << ": You do not have enough coin pay for card cost" << endl;
        return;
    }

    //For Pay
    player->setCoin(cost);

    //Add Card into Player's handcard
    Cards* temp = new Cards(*hand[index - 1]);
    player->getHandCard().push_back(temp);
    cout << "\n"<<player->getName() << " has select " << *temp << endl;

    //Memory Leak Proctect
    delete hand[index - 1];
    hand[index - 1] = nullptr;
    hand.erase(this->hand.begin() + (index - 1));
    delete temp;
    temp = nullptr;

}

void Hand::setCard(int index, Deck* deck) {
    
    Cards* temp = deck.draw();
    for (int i = index-1; i < 6; i++) {
        if (i < 5)
            this->hand[i] = this->hand[i];
        if (i == 5)
            this->hand[i] = nullptr;
    };
    
    this->hand[5] = temp;
    
}

//Get Method
vector<Cards*> Hand::getHand() {
    return hand;
}
    
/****** END ******/
