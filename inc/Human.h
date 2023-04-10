#ifndef _Human_H
#define _Human_H

#include "Organism.h"

class Human : public Organism
{
public:
    Human();
    Human( City *city, int width, int height );
    virtual ~Human();
    vector<Organism*> getTargets() override;



    void move() override;
};

#endif
