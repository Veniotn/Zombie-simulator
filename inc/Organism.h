#ifndef _Organism_H
#define _Organism_H
#include <iostream>
#include <chrono>
#include <thread>


using namespace std;

class City;

class Organism
{
protected:
    int x, y, width, height;
    bool moved;
    City *city;
    int species;
    enum {HUMAN,ZOMBIE};

    enum { WEST, NORTH, EAST, SOUTH, NUM_DIRECTIONS };

public:
    Organism();
    Organism( City *city, int width, int height );
    virtual ~Organism();

    virtual void move() = 0;
    //virtual void spawn() = 0;
    int getSpecies(){return this->species;} //this could also be coded concrete here
    //virtual void getPosition() = 0;

    void setPosition( int x, int y );
    void endTurn();
    bool isTurn();

    friend ostream& operator<<( ostream &output, Organism *organism );
};


#endif

