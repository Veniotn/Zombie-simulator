//
// Created by nick on 4/9/2023.
//
#include "../inc/City.h"
#include "../inc/Zombie.h"
#include "../inc/Human.h"

Zombie::Zombie(City *city, int width, int height) {
    this->city    = city;
    this->width   = width;
    this->height  = height;
    this->species = ZOMBIE;
    this->moved   = false;
}

Zombie::Zombie() {}

void Zombie::move()
{
    int gridRow, gridColumn, originalColumn, originalRow;
    vector<Organism*> validTargets;
    validTargets = getTargets();
    //if valid targets have been found
    if (validTargets.size() > 0)
    {
        //select one of the spaces randomly
        Organism *target = validTargets[rand() % validTargets.size()];
        //get its index
        gridColumn = target->getXPosition();
        gridRow    = target->getYPosition();

        //get the index of the zombies original memory slot
        originalColumn = this->x;
        originalRow    = this->y;

        if (target->getSpecies() != ZOMBIE)
        {
//            //free the targets memory
//            delete[] target;
            city->setOrganism(new Empty(city, originalColumn, originalRow), originalColumn, originalRow);
        }


        //move the zombie to the new space
        city->setOrganism(this, gridColumn, gridRow);



        //set the new position using the targets x and y
        this->setPosition(gridColumn, gridRow);
    }

    this->endTurn();
}



Zombie::~Zombie() {

}

vector<Organism *> Zombie::getTargets() {
    int xIndex, yIndex;
    vector<Organism*> validTargets;


    //search the adjacent tiles for targets
    //diagram:
    //          [-1]
    //      [-1][0][1]
    //          [1]
    for (int currentRow = -1; currentRow <= 1; currentRow++)
    {
        for (int currentColumn = -1; currentColumn <= 1; currentColumn++)
        {
            //ignore the current cell
            if (currentRow == 0 && currentColumn == 0){continue;}
            //find indexes of adjacent tiles
            xIndex = this->x + currentColumn;
            yIndex = this->y + currentRow;

            //check if they're off the map
            if ((xIndex < 0 || xIndex >= GRID_WIDTH) || (yIndex < 0 || yIndex >= GRID_HEIGHT)){continue;}

            //check if the spot is empty or is a human and if it is, add it to valid targets. Also check for null.
            Organism* target = city->getOrganism(xIndex,yIndex);
            if (target != nullptr)
            {
                if (target->getSpecies() != ZOMBIE)
                {
                    validTargets.push_back(target);
                }
            }

        }//end nested
    }//end for-loop

    //return the list of valid locations to move to.
    return validTargets;
}
