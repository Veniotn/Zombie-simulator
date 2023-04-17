//
// Created by nick on 4/9/2023.
//
#include "../inc/City.h"
#include "../inc/Zombie.h"
#include "../inc/Human.h"


Zombie::Zombie(City *city, int width, int height) {
    this->city    = city;
    this->x   = width;
    this->y  = height;
    this->species = ZOMBIE;
    this->moved   = false;
    this->hasEaten = false;
    this->daysToBreed = 0;
    this->daysHungry = 0;

}

Zombie::Zombie() {
    this->city = nullptr;
    this->width = 0;
    this->height = 0;
    this->species = ZOMBIE;
    this->moved = false;
    this->hasEaten = false;
    this->daysToBreed = 0;
    this->daysHungry = 0;

}


void Zombie::move()
{
    int gridRow, gridColumn, originalColumn, originalRow;
    vector<Organism*> validTargets;
    validTargets = getTargets();
    //if valid targets have been found
    if (validTargets.size() > 0)
    {
        //looks for all human spaces, returns one randomly, if no humans found returns a valid empty space
        Organism *target = lookForHuman(validTargets);

        if (target->getSpecies() != ZOMBIE)
        {
            if (target->getSpecies() == HUMAN)
            {
                //if a human is eaten reduce the population counter
                city->setHumanPopulation(city->getHumanPopulation()-1);
                this->hasEaten = true;
            }

            //set the index we are leaving to empty
            city->setOrganism(new Empty(city, this->x, this->y));
        }
        this->setPosition(target->getXPosition(), target->getYPosition());
        //move the zombie to the new space
        city->setOrganism(this);

    }


    endTurn();
}


void Zombie::endTurn()
{
    this->moved = true;

    if (hasEaten)
    {
        this->daysHungry = 0;
        this->hasEaten = false;
    }
    else
    {
        daysHungry++;
    }


    if (daysHungry > ZOMBIE_STARVE)
    {
       starve();
    }

    if (daysToBreed > ZOMBIE_BREED)
    {
        breed();
    }
    else
    {
        daysToBreed++;
    }


}

void Zombie::breed()
{
    vector<Organism *> validTargets = getTargets();
    Organism* humanToConvert = lookForHuman(validTargets);

    if (humanToConvert->getSpecies() == HUMAN)
    {
        city->setOrganism(new Zombie(city, humanToConvert->getXPosition(), humanToConvert->getYPosition()));
        city->setZombiePopulation(city->getZombiePopulation()+1);
        city->setHumanPopulation(city->getHumanPopulation()-1);
        this->daysToBreed = 0;
    }
}

void Zombie::starve()
{
    //set the zombies space to empty.
    city->setOrganism(new Human(city, this->x, this->y));
    city->setZombiePopulation(city->getZombiePopulation()-1);
    city->setHumanPopulation(city->getHumanPopulation()+1);
}
Zombie::~Zombie(){delete[] city;}


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
            if (target != nullptr && target->getSpecies() != ZOMBIE)
            {
                validTargets.push_back(target);
            }
        }//end nested
    }//end for-loop

    //return the list of valid locations to move to.
    return validTargets;
}

Organism *Zombie::lookForHuman(vector<Organism*> validTargets)
{
    vector<Organism *> humans;
    //https://stackoverflow.com/questions/19665818/generate-random-numbers-using-c11-random-library
    //random number using c++ 11 random library, generate seed before loop from current time.
    mt19937 gen(chrono::system_clock::now().time_since_epoch().count());


    //search for humans through the list of available spots to move to
    for (int currentTarget = 0; currentTarget < validTargets.size(); currentTarget++)
    {
        if (validTargets[currentTarget]->getSpecies() == HUMAN)
        {
            humans.push_back(validTargets[currentTarget]);
        }
    }
    //if there are humans available pick one
    if (humans.size()  > 0)
    {
        //random number from 0 to the last index of the humans vector.
        std::uniform_int_distribution<> range(Organism::HUMAN, humans.size()-1);
        //choose one of the humans from the list
        return humans[range(gen)];
    }
    //if no humans found choose one of the random empty spots
    std::uniform_int_distribution<> range(Organism::HUMAN, validTargets.size()-1);
    return validTargets[range(gen)];
};
