#ifndef _Zombie_H
#define _Zombie_H

#include "Organism.h"

class Zombie : public Organism
{
private:
    int daysToBreed, daysHungry;
    bool hasEaten;
    void endTurn() override;
    void breed();
    void starve();
    Organism* lookForHuman(vector<Organism*> validTargets);
public:
    Zombie();
    Zombie( City *city, int width, int height );
    virtual ~Zombie();

    void move() override;
    vector<Organism*> getTargets() override;

};

#endif