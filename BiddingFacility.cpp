#include "BiddingFacility.h"
#include <iostream>
#include <string>
using namespace std;

BiddingFacility::BiddingFacility() {}

BiddingFacility::BiddingFacility(string a, int b, int c)
{
    name = a;
    money = b;
    bid = c;
}

//Copy Construtor
BiddingFacility::BiddingFacility(const BiddingFacility& object)
{
    this->name = object.name;
    this->money = object.money;
    this->bid = object.bid;
}
//Assignment Operator
BiddingFacility& BiddingFacility::operator=(const BiddingFacility& object) {
    this->name = object.name;
    this->money = object.money;
    this->bid = object.bid;
    return *this;
}
//reveal the bid of each player
void BiddingFacility::revealBid()
{
    cout << name << " bid " << bid;
}
//set the bid for each player
void BiddingFacility::setBid()
{
    cout << "Enter the amount you wanna bid: ";
    cin >> bid;
    while (bid < 0)
    {
        cout << "You can't bid less than 0";
        cin >> bid;
    }
}
//get the bid of each player
int BiddingFacility::getBid()
{
    return bid;
}
//Method to find out who goes first
void BiddingFacility::compareBid(vector<BiddingFacility*> a)
{
    int max = 0;
    string currentMaxName = a[0]->name;
    size_t arraylength = sizeof(a) / sizeof(a[0]);
    bool sameBid = false;

    for (size_t i = 0; i < a.size(); i++)
    {

        cout << a[i]->name << " has bid " << a[i]->bid << endl;

        if (a[i]->bid > max)
        {
            max = a[i]->bid;
            currentMaxName = a[i]->name;
        }

    }

    for (int i = 0; i < a.size(); i++)
    {

        if (a[i]->bid == max && a[i]->name.compare(currentMaxName) < 0)
        {
            currentMaxName = a[i]->name;
            sameBid = true;
        }

    }
    if (max == 0)
        cout << "\nAll player bids 0 so " << currentMaxName << " will go first because his name is first in alphabetical order " << endl;
    else
        if (sameBid)
            cout << "\nTwo or more players have the same bid but " << currentMaxName << " will go first becasue his name is first in alphabetical order " << endl;
        else
            cout << "\n" << currentMaxName << " will go first due to highest bid: " << max;
}

//stream insertion operator
ostream& operator<<(ostream& output, const BiddingFacility& BF)
{
    output << "Name: " << BF.name << ", Money: " << BF.money << ", Bid: " << BF.money << endl;
    return output;
}

//Destructor
BiddingFacility::~BiddingFacility() {
    cout << "Destructor is called" << endl;
    name = "";
    money = 0;
    bid = 0;
}
