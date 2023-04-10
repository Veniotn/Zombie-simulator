//
// Created by nick on 4/9/2023.
//

#include "../inc/Human.h"
#include "../inc/City.h"
#include "../inc/Empty.h"

//TODO: implement movement

Human::Human(City *city, int width, int height)
{
    this->city    = city;
    this->width   = width;
    this->height  = height;
    this->species = HUMAN;
    this->moved   = false;
}

Human::Human()
{

}

Human::~Human()
{

}



void Human::move()
{
    int columnIndex, rowIndex, originalColumn, originalRow;
    vector<Organism*> validTargets;
    //check for valid targets
    validTargets = getTargets();

    if (validTargets.size() > 0)
    {
        //select one of the target spaces
        Organism* target = validTargets[rand() % validTargets.size()];


        //get its place in the 2d array
        columnIndex = target->getXPosition();
        rowIndex = target->getYPosition();

        //move the human to the empty space
        city->setOrganism(this, columnIndex, rowIndex);

        //get original indexes
        originalColumn = this->x;
        originalRow    = this->y;


        //remove the human from the old space
        city->setOrganism(new Empty(city, originalColumn, originalRow), originalColumn, originalRow);

        //set the new position
        this->setPosition(columnIndex, rowIndex);




    }

    //set the moved flag to true
    this->endTurn();
}

vector<Organism *> Human::getTargets()
{
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
            //if the spot is empty add it to valid targets.
            Organism* target = city->getOrganism(xIndex,yIndex);
            if (typeid(target) == typeid(Empty))
            {
                validTargets.push_back(target);
            }
        }
    }


    return validTargets;
}





