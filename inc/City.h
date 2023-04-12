#ifndef _CITY_H
#define _CITY_H
#include <random>
#include "Organism.h"
#include "Empty.h"
#include "GameSpecs.h"




using namespace std;
class Organism;

const int GRID_WIDTH = 20;
const int GRID_HEIGHT = 20;


class City
{
private:
    int humanPopulation, zombiePopulation, currentIteration;
    void resetFlags();

protected:
    //array of organisms to use as the game board
    Organism *grid[GRID_HEIGHT][GRID_WIDTH];
public:
    City();
    virtual ~City();
    Organism *getOrganism( int x, int y );
    void setOrganism( Organism *organism);
    int  getHumanPopulation();
    int  getZombiePopulation();
    void setHumanPopulation(int  population);
    void setZombiePopulation(int population);
    int  getCurrentIteration();


    void move();
    friend ostream& operator<<( ostream &output, City &city );

    bool hasDiversity();
};

#endif
