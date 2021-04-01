#pragma once
#include <string>
#include <array>
#include <vector>
using namespace std;
class BiddingFacility
{
private:
    //Name of the player
    string name;
    //The current amount of money the player has
    int money;
    //The bid the player makes
    int bid;

public:
    //Default constructor of the class
    BiddingFacility();

    //Constructor with 3 parameters
    BiddingFacility(string a, int b, int c);

    //Copy constructor
    BiddingFacility(const BiddingFacility& object);

    //Assignment Operator
    BiddingFacility& operator = (const BiddingFacility&);

    //function to set the bid
    void setBid();

    //Getter for attribute bid
    int getBid();

    //Reveal the bid of the player
    void revealBid();

    //compare the bid to decide which player will go first
    static void compareBid(vector<BiddingFacility*> a);

    //Stream insertion operator
    friend ostream& operator<<(ostream& output, const BiddingFacility& BF);

    //Destructor
    ~BiddingFacility();

};
