/***** Memory Leak Check *****/
#define _DEBUG
#ifdef _DEBUG
// #define new new( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif
#define _CRTDBG_MAP_ALLOC
#include <memory>
/****************************/
#include <iostream>
#include "Cards.h"
#include "Map.h"
#include "BiddingFacility.h"
#include "Player.h"
#include <string>
#include <random>
#include <algorithm>

using namespace std;

int main() {

    //**check for memory leaks**//
     // _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    vector<Territory*> card_t;
    vector<Cards*> card_h;
    BiddingFacility* card_bid = new BiddingFacility("Eight", 100, 11);

    Player* card_play = new Player("Eight", 7, 18, card_t, card_h, card_bid);

    // 2 players - 27 cards
     /**** Just for simple check ****/
    Cards* card1 = new Cards("Ancient Phoenix", "Flying", "Move 5 armies");
    Cards* card2 = new Cards("Ancient Sage", "+1 VP per Ancient Card", "Move 3 armies");
    Cards* card3 = new Cards("Ancient Tree Spirit", "3 elixirs", "Place 4 armies");
    Cards* card4 = new Cards("Ancient Woods", "1 new army", "Build a city AND place 1 army");
    Cards* card5 = new Cards("Cursed Banshee", "2 elixirs", "Move 6 armies");
    Cards* card6 = new Cards("Cursed Gargoyles", "Flying", "Move 5 armies");
    Cards* card7 = new Cards("Cursed King", "1 elixir", "Place 3 armies OR Move 4 armies");
    Cards* card8 = new Cards("Cursed Mausoleum", "Move 1 army", "Build a city");
    Cards* card9 = new Cards("Cursed Tower", "+1 VP per flying", "Build a city");
    Cards* card10 = new Cards("Dire Dragon", "Flying", "Move 3 armies AND Destroy army");

    //Cards* card11 = new Cards("Dire Eye", "Flying", "Place 4 armies");
    //Cards* card12 = new Cards("Dire Giant", "Immune to attack", "Place 3 armies AND Destroy army");
    //Cards* card13 = new Cards("Dire Goblin", "1 elixir", "Move 5 armies");
    //Cards* card14 = new Cards("Dire Ogre", "+1 VP per 3 coins", "Move 2 armies");
    //Cards* card15 = new Cards("Forest Elf", "1 army", "Place 3 armies OR Move 2 armies");
    //Cards* card16 = new Cards("Forest Gnome", "3 elixirs", "Move 2 armies");
    //Cards* card17 = new Cards("Forest Pixie", "1 army", "Move 4 armies");
    //Cards* card18 = new Cards("Forest Tree Town", "Move 1 army", "Build a city");
    //Cards* card19 = new Cards("Graveyard", "+1 VP per Cursed Card", "Place 2 armies");
    //Cards* card20 = new Cards("Lake", "+1 VP per Forest Card", "Place 2 armies OR Move 3 armies");
    //Cards* card21 = new Cards("Night Hydra", "1 army", "Move 5 armies AND Destroy army");
    //Cards* card22 = new Cards("Night Village", "1 army", "Build a city");
    //Cards* card23 = new Cards("Night Wizard", "+1 VP per Night Card", "Adrien");
    //Cards* card24 = new Cards("Noble Hills", "Three noble cards = 4VP", "Place 3 armies");
    //Cards* card25 = new Cards("Noble Knight", "Move 1 army", "Place 4 armies AND Destroy army");
    //Cards* card26 = new Cards("Noble Unicorn", "Move 1 army", "Move 4 armies AND Place 1 army");
    //Cards* card27 = new Cards("Stronghold", "+1 VP per Dire card", "Build a city");

    //// 3 players - 32 cards
    //Cards* card28 = new Cards("Arcane Manticore", "Move 1 army", "Place 4 armies AND Destroy army");
    //Cards* card29 = new Cards("Arcane Sphinx", "Flying", "Place 3 armies OR Move 4 armies");
    //Cards* card30 = new Cards("Arcane Temple", "+1 VP per Arcane Card", "Move 3 armies");
    //Cards* card31 = new Cards("Mountain Dwarf", "+3 VP if you have two Mountain Cards", "Move 2 armies AND Destroy army");
    //Cards* card32 = new Cards("Mountain Treasury", "1 elixir and 2 coins", "Move 3 armies");

    //// 4 players - 34 cards
    //Cards* card33 = new Cards("Castle", "1 elixir", "Place 3 armies OR Build a city");
    //Cards* card34 = new Cards("Castle 2", "1 elixir", "Move 3 armies AND Build a city");


    Deck* newDeck = new Deck();

    newDeck->setDeck(card1);
    newDeck->setDeck(card2);
    newDeck->setDeck(card3);
    newDeck->setDeck(card4);
    newDeck->setDeck(card5);
    newDeck->setDeck(card6);
    newDeck->setDeck(card7);
    newDeck->setDeck(card8);
    newDeck->setDeck(card9);
    newDeck->setDeck(card10);

    cout << "/****** TEST Draw Method ******/\n" << endl;
    cout << "/****** Before Draw Method ******/" << endl;
    cout << *newDeck << endl;

    Hand* newHand = new Hand();

    for (int i = 0; i < 6; i++) {
        newHand->setHand(newDeck->draw());
    };

    cout << "/****** After Draw Method ******/" << endl;

    cout << *newDeck << endl;

    cout << "/****** TEST Exchange Method ******/\n" << endl;

    cout << "/****** Before Exchange Method ******/" << endl;

    cout << *newHand << endl;

    cout << "/****** After Exchange Method <Index 4> ******/" << endl;

    newHand->exchange(4, card_play);

    cout << *newHand << endl;

    cout << "/****** Part 2 Demonstration: Adding the method to fill the empty card space in the hand ******/" << endl;

    cout << "/****** TEST setCard Method ******/" << endl;

    newHand->setCard(4, newDeck);

    cout << "/****** After Test setCard Method ******/" << endl;

    cout << *newHand << endl;


    cout << "/******** Memory Leak Protect ********/" << endl;

    delete card_play;
    card_play = nullptr;
    delete newDeck;
    newDeck = nullptr;
    delete newHand;
    newHand = nullptr;

    card_t.clear();
    card_h.clear();

    return 0;
}
