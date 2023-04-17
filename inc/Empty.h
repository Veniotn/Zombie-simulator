//
// Created by nick on 4/10/2023.
//

#ifndef INC_4_ZOMBIES_EMPTY_H
#define INC_4_ZOMBIES_EMPTY_H
#include "Organism.h"

class Empty : public Organism{
private:
    void endTurn() override;
public:
    Empty(City *city, int width, int height);
    virtual ~Empty();
};


#endif //INC_4_ZOMBIES_EMPTY_H
