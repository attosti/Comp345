#pragma once
//
// Created by Nian Liu on 2021-02-09.
//

#ifndef COMP345W_MAP_H
#define COMP345W_MAP_H

#include <string>
#include <vector>
#include <set>
using namespace std;

class Territory
{
public:
    string tName;
    int tID;
    string continentName;
    int continentID;
    string player;
    int armyNum;
    bool connectedForeignContinent;
    bool build_city;

    vector<int> adjacentTerritoryInMap;
    vector<int> adjacentTerritoryInSameContinent;

    Territory();
    Territory(string tName, string continentName, int tID, int continentID);

    /*********** Consturtor For Part 3 ***********/
    Territory(string tName, string continentName, int tID, int continentID, bool connectedForeignContient, string player, bool build_city, int armyNum);
    /********************************************/
    //Copy Constructor
    Territory(const Territory& object);
    //Assignment Operator
    Territory& operator = (const Territory& object);
    //Destructor
    ~Territory();

    string getTName();
    int getTID();
    string getContinentName();
    int getContinentID();
    string getPlayer();
    int getArmyNum();
    bool getConnectedForeignContinent();
    vector<int> getAdjacentTerritoryInMap();
    vector<int> getAdjacentTerritoryInSameContinent();
    void setTName(string tName);
    void setTID(int tID);
    void setConnectedForeignContinent(bool canGoOut);
    void printTerritoryVector(vector<int> v);
    //For Part 3 Method
    bool getBuildCity();
    void setArmy(int armyNum);
    void setBuildCity();
    void setPlayer(string player);
    //Stream Insertion Operator
    friend ostream& operator<<(ostream& output, const Territory& object);

};

class Continent
{
public:
    string cName;
    int cID;
    vector<Territory*> territoryMemberInContinent;
    set<int> reachableForeignContinent;

    Continent();
    Continent(string cName, int cID);

    /**********************/
    //Copy Constructor
    Continent(const Continent& object);
    //Assignment Operator
    Continent& operator = (const Continent&);
    //Destructor
    ~Continent();
    //Stream Insertion Operator
    friend ostream& operator<<(ostream& output, const Continent& object);
    /**********************/

    string getCName();
    int getCID();
    vector<Territory*> getTerritoryMemberInContinent();
    bool checkSubGraph();
    set<int> getReachableForeignContinent();
};

class Map
{
public:
    string mName;
    int numOfAllTerritory;
    int numOfAllContinent;
    vector<Territory*> allTerritory;
    vector<Continent*> allContinent;

    Map();
    Map(string mName, int numOfAllTerritory, int numOfAllContinent);

    /*********************/
    //Copy Constructor
    Map(const Map& object);
    //Assignment Operator
    Map& operator = (const Map&);
    //Destructor
    ~Map();
    //Stream Insertion Operator
    friend ostream& operator<<(ostream& output, const Map& object);
    /**********************/

    string getMName();
    int getNumOfAllTerritory();
    int getNumOfAllContinent();
    vector<Territory*> getAllTerritory();
    void setMapName(string mName);
    void printAllTerritory();
    void printAllContinent();
    void validate();

    //friend class MapLoader;
};

#endif //COMP345W_MAP_H
