#include "Player.h";


using namespace std;

//Default Construtor
Player::Player()
{
    name = "Default";
    move = 0;
    coin = 0;
    army = 18;
    cityToken = 3;
    vector<Territory*> territory;
    vector<Cards*> handCard;
    bid = new BiddingFacility();
}

//Construtor with parameter
Player::Player(string name, int coin, int move, vector<Territory*> territory, vector<Cards*> handCard, BiddingFacility* bid)
{
    this->name = name;
    this->coin = coin;
    this->move = move;
    this->army = 18;
    this->cityToken = 3;
    this->territory = territory;
    this->handCard = handCard;
    this->bid = bid;
}

//Copy Constructor
Player::Player(const Player& object) {
    this->name = object.name;
    this->coin = object.coin;
    this->move = object.move;
    this->army = object.army;
    this->cityToken = object.cityToken;
    for (int i = 0; i < object.territory.size(); i++) {
        this->territory[i] = new Territory(*object.territory[i]);
    }
    for (int i = 0; i < object.handCard.size(); i++) {
        this->handCard[i] = new Cards(*object.handCard[i]);
    }
    this->bid = new BiddingFacility(*(object.bid));
}

//Assignment Operator
Player& Player::operator=(const Player& object) {
    this->name = object.name;
    this->coin = object.coin;
    this->move = object.move;
    this->army = object.army;
    this->cityToken = object.cityToken;
    for (int i = 0; i < object.territory.size(); i++) {
        this->territory[i] = new Territory(*object.territory[i]);
    }
    for (int i = 0; i < object.handCard.size(); i++) {
        this->handCard[i] = new Cards(*object.handCard[i]);
    }
    this->bid = new BiddingFacility(*(object.bid));
    return *this;
}

//Destructor
Player::~Player() {
    name = "";
    coin = 0;
    move = 0;
    army = 0;
    cityToken = 0;

    for (int i = 0; i < territory.size(); i++) {
        delete territory.at(i);
        territory[i] = nullptr;
    }
    for (int i = 0; i < handCard.size(); i++) {
        delete handCard.at(i);
        handCard[i] = nullptr;
    }

    territory.clear();
    handCard.clear();

    delete bid;
    bid = nullptr;
};

//Method Required by Part 2
void Player::PayCoin(int coin) {
    this->coin = this->coin - coin;
}

void Player::BuildCity(Territory* territory) {
    territory->setBuildCity();
    cityToken = cityToken - 1;
}

void Player::PlaceNewArmies(Territory* territory, int army) {
    if (this->territory.empty()) {
        territory->setPlayer(getName());
        territory->setArmy(army);
        setArmy(4);
        territory->setBuildCity();
        this->territory.push_back(territory);
    }
    else if (territory->getBuildCity() == true) {
        territory->setArmy(army);
        setArmy(4);
    }
    else {
        cout << "You can not place new armies in the territory without a city." << endl;
    }
}

//Move army from point A to point B
void Player::MoveArmies(Territory* A, Territory* B, int army) {
    //Check point B whether occupied by player
    if (B->getPlayer().empty()) {
        A->setArmy(-army);
        B->setArmy(army);
        B->setPlayer(getName());
        territory.push_back(B);
        setMove(-army);
    }
    else if (B->getPlayer().compare(getName()) == 0) {
        A->setArmy(-army);
        B->setArmy(army);
        setMove(-army);
    }
    else {
        cout << "Your destination has been occupied by other players." << endl;
    }
}

void Player::MoveOverLand(Territory* A, Territory* B, int army) {

    if (A->getContinentName().compare(B->getContinentName()) != 0) {

        if (getMove() > 3) {

            if (B->getPlayer().empty()) {
                A->setArmy(-army);
                B->setArmy(army);
                B->setPlayer(getName());
                territory.push_back(B);
                setMove(-army - 3);
            }
            else if (B->getPlayer().compare(getName()) == 0) {
                A->setArmy(-army);
                B->setArmy(army);
                setMove(-army - 3);
            }
            else {
                cout << "Your destination has been occupied by other players." << endl;
            }
        }
        else {
            cout << "You need more than three movement to cross continent." << endl;
        }
    }
    else {
        cout << "You destination is in the same continent." << endl;
    }
}

void Player::DestroyArmy(Territory* territory, int num) {
    territory->setArmy(-num);
}

//Set Method
void Player::setArmy(int army) {
    this->army -= army;
}
void Player::setMove(int move) {
    this->move += move;
}
void Player::setCoin(int coin) {
    this->coin -= coin;
}
void Player::setHandCard(Cards* object) {
    this->handCard.push_back(object);
}

//Get Method
string Player::getName() {
    return name;
}
int Player::getMove() {
    return move;
}
int Player::getCoin() {
    return coin;
}
vector<Territory*> Player::getTerritory() {
    return territory;
}
vector<Cards*> Player::getHandCard() {
    return handCard;
}

//Service Method
bool Player::check_territory(Territory* object) {
    for (int i = 0; i < territory.size(); i++) {
        if (territory[i]->getPlayer().compare(object->getPlayer()) == 0) {
            return false;
        }
    }
    return true;
}
void Player::printTerritory() {
    for (int i = 0; i < territory.size(); i++) {
        cout << *territory[i];
    }
}
//Stream Insertion Operator
ostream& operator<< (ostream& output, const Player& object) {
    output << "Player Name: " << object.name << " Movement: " << object.move << " Coin: " << object.coin << " Army: " << object.army << " City Token: " << object.cityToken << endl;
    if (object.handCard.size() != 0) {
        output << "Player Hand Card : \n";
        for (int i = 0; i < object.handCard.size(); i++) {
            output << i + 1;
            output << " -- " << *(object.handCard[i]);
        }
    }
    if (object.territory.size() != 0) {
        output << "Player Territory : \n";
        for (int i = 0; i < object.territory.size(); i++) {
            output << i + 1;
            output << " -- " << *(object.territory[i]);
        }
    }
    return output;
}
