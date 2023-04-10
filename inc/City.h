#ifndef _CITY_H
#define _CITY_H
#include "Organism.h"
#include "Empty.h"



using namespace std;
class Organism;

const int GRID_WIDTH = 20;
const int GRID_HEIGHT = 20;

class City
{
protected:
    //array of organisms to use as the game board
    Organism *grid[GRID_HEIGHT][GRID_WIDTH];
public:
    City();
    virtual ~City();
    Organism *getOrganism( int x, int y );
    void setOrganism( Organism *organism, int x, int y );


    void move();
    friend ostream& operator<<( ostream &output, City &city );
};

#endif
