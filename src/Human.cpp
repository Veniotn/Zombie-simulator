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
    this->x   = width;
    this->y  = height;
    this->species = HUMAN;
    this->moved   = false;
    this->recruitCounter = 0;
}

Human::Human()
{
    this->city = nullptr;
    this->width = 0;
    this->height = 0;
    this->species = HUMAN;
    this->moved = false;
}

Human::~Human()
{
    delete[] city;
}



void Human::move()
{
    int columnIndex, rowIndex, originalColumn, originalRow;
    vector<Organism*> validTargets;
    //check for valid targets
    validTargets = getTargets();

    if (!validTargets.empty())
    {
        //select one of the target spaces
        Organism* target = validTargets[rand() % validTargets.size()];
        //move the human to the valid space in the array

        //remove the human from the old space
        city->setOrganism(new Empty(city, this->x, this->y));

        this->setPosition(target->getXPosition(), target->getYPosition());
        city->setOrganism(this);
    }


    endTurn();
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
            //get the class names of the target and see if its empty
            if (target != nullptr && target->getSpecies() == EMPTY )
            {
                validTargets.push_back(target);
            }
        }
    }
    return validTargets;
}

void Human::endTurn()
{
    this->recruitCounter++;


    if (recruitCounter > HUMAN_BREED)
    {
        recruit();
        resetRecruitCounter();
    }


    moved = true;
}

void Human::recruit()
{
    //https://stackoverflow.com/questions/19665818/generate-random-numbers-using-c11-random-library
    //random number using c++ 11 random library, generate seed before loop from current time.
    mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
    vector<Organism *> validTargets;
    validTargets = getTargets();
    uniform_int_distribution<> range(Organism::HUMAN, validTargets.size()-1);

    if (!validTargets.empty())
    {
        Organism * chosenSpace = validTargets[range(gen)];
        city->setHumanPopulation(city->getHumanPopulation()+1);
        city->setOrganism(new Human(city, chosenSpace->getXPosition(), chosenSpace->getYPosition()));
    }
}
void Human::resetRecruitCounter()
{
    recruitCounter = 0;
}







