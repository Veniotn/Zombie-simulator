//
// Created by nick on 4/9/2023.
//
#include "../inc/City.h"
#include "../inc/Human.h"
#include "../inc/Zombie.h"
#include "../inc/GameSpecs.h"



//constructor
City::City() {
    const int ORGANISM_CHOICES = 3;
    int organismChoice, boardWidth, boardHeight;
    //set the counters at 0;
    humanPopulation = 0, zombiePopulation = 0, currentIteration = 1;
    //https://stackoverflow.com/questions/19665818/generate-random-numbers-using-c11-random-library
    //random number using c++ 11 random library, generate seed before loop from current time.
    mt19937 gen(chrono::system_clock::now().time_since_epoch().count());


    //fill the grid
    for(int currentRow = 0; currentRow< GRID_HEIGHT; currentRow++){
        for (int currentColumn = 0; currentColumn < GRID_WIDTH; currentColumn++) {
            //choose if it will be a zombie or a human human = 0, empty = 2;
            std::uniform_int_distribution<> range(Organism::HUMAN, Organism::EMPTY);
            organismChoice = range(gen);

            //get the board size as editable number
            boardWidth  = GRID_WIDTH;
            boardHeight = GRID_HEIGHT;

            //fill the grid spot, save their position in the array and add one to the respected counter.
            if(organismChoice == Organism::HUMAN && humanPopulation < HUMAN_STARTCOUNT){
                grid[currentRow][currentColumn] = new Human(this, boardWidth, boardHeight);
                grid[currentRow][currentColumn]->setPosition(currentColumn, currentRow);
                humanPopulation++;
            }
            else if(organismChoice == Organism::ZOMBIE && zombiePopulation < ZOMBIE_STARTCOUNT)
            {
                grid[currentRow][currentColumn] = new Zombie(this, boardWidth, boardHeight);
                grid[currentRow][currentColumn]->setPosition(currentColumn, currentRow);
                zombiePopulation++;
            }
            else
            {
                grid[currentRow][currentColumn] = new Empty(this, boardWidth, boardHeight);
                grid[currentRow][currentColumn]->setPosition(currentColumn,currentRow);
            }
        }//end nested loop
    }//end for loop


}



//methods
void City::move() {
    for (int currentRow = 0; currentRow < GRID_HEIGHT; currentRow++)
    {
        for (int currentColumn = 0; currentColumn < GRID_WIDTH; currentColumn++)
        {
            //if they havent moved yet move them
            if (!grid[currentRow][currentColumn]->hasMoved())
            {
                grid[currentRow][currentColumn]->move();
            }
        }
    }
    resetFlags();
}

void City::resetFlags()
{
    for (int currentRow = 0; currentRow < GRID_HEIGHT; currentRow++)
    {
        for (int currentColumn = 0; currentColumn < GRID_WIDTH; currentColumn++)
        {
          grid[currentRow][currentColumn]->setMoved(false);
        }
    }
    currentIteration++;
}

//void;

//getter/setters
bool City::hasDiversity()
{
    //if either of these are false return true.
    return !(zombiePopulation == 0 || humanPopulation == 0);
}

void City::setOrganism(Organism *organism)
{
    grid[organism->getYPosition()][organism->getXPosition()] = organism;
}

Organism* City::getOrganism(int x, int y) {
    for (int currentRow = 0; currentRow < GRID_HEIGHT; currentRow++) {
        for (int currentColumn = 0; currentColumn < GRID_WIDTH; currentColumn++) {

            bool targetOrganism = grid[currentRow][currentColumn]->getXPosition() == x
                               && grid[currentRow][currentColumn]->getYPosition() == y;
            //if the current index matches the position of the organism we are seeking return it.
            if (targetOrganism)
            {
                return grid[currentRow][currentColumn];
            }
            //continue to search
        }//end nested
    }//end for
    return nullptr;
}



void City::setHumanPopulation(int population)
{
    humanPopulation = population;
}

int City::getHumanPopulation()
{
    return humanPopulation;
}

void City::setZombiePopulation(int population)
{
    zombiePopulation = population;
}

int City::getZombiePopulation()
{
   return zombiePopulation;
}

int City::getCurrentIteration()
{
    return currentIteration;
}

//overloads
ostream &operator<<(ostream &output, City &city) {
    cout << "Current iteration: " << city.currentIteration <<  endl;
    for(int currentRow = 0; currentRow < GRID_HEIGHT; currentRow++)
    {
        for (int currentColumn = 0; currentColumn < GRID_WIDTH; ++currentColumn)
        {
            cout << city.grid[currentRow][currentColumn];
        }
        cout << "\n";
    }
}



//destructor
City::~City() {
    for (int cityRow = 0; cityRow < GRID_HEIGHT; cityRow++) {
        for (int cityColumn = 0; cityColumn < GRID_WIDTH; cityColumn++) {
            delete grid[cityRow][cityColumn];
        }
    }
}