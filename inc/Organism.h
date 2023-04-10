#ifndef _Organism_H
#define _Organism_H
#include <iostream>
#include <chrono>
#include <thread>
#include <vector>



using namespace std;

class City;

class Organism
{
protected:
    int x, y, width, height;
    bool moved;
    City *city;
    int species;
    enum {HUMAN,ZOMBIE,EMPTY};

    enum { WEST, NORTH, EAST, SOUTH, NUM_DIRECTIONS };

public:
    Organism();
    Organism( City *city, int width, int height );
    virtual ~Organism();

    virtual void move();

    virtual vector<Organism*> getTargets();
    //virtual void spawn() = 0;
    int getSpecies() const{return this->species;} //this could also be coded concrete here
    int getXPosition() const{return this->x;}
    int  getYPosition() const{return this->y;}

    void setPosition( int x, int y );
    void endTurn();
    bool isTurn();

    friend ostream& operator<<( ostream &output, Organism *organism );
};


#endif

