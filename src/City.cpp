//
// Created by nick on 4/9/2023.
//
#include "../inc/City.h"
#include "../inc/Human.h"
#include "../inc/Zombie.h"



City::City() {
    const int ORGANISM_CHOICES = 2;
    int organismChoice, boardWidth, boardHeight;
    //fill the grid
    for(int currentRow = 0; currentRow< GRID_HEIGHT; currentRow++){
        for (int currentColumn = 0; currentColumn < GRID_WIDTH; currentColumn++) {
            //choose if it will be a zombie or a human
            organismChoice = rand() % ORGANISM_CHOICES;
            //get the board size as editable number
            boardWidth  = GRID_WIDTH;
            boardHeight = GRID_HEIGHT;

            //fill the grid spot and set their position to where they are in the array.
            if(organismChoice == 0){
                grid[currentRow][currentColumn] = new Human(this, boardWidth, boardHeight);
                grid[currentRow][currentColumn]->setPosition(currentColumn, currentRow);
            } else{
                grid[currentRow][currentColumn] = new Zombie(this, boardWidth, boardHeight);
                grid[currentRow][currentColumn]->setPosition(currentColumn, currentRow);
            }
        }//end nested loop
    }//end for loop


}

void City::move() {
    for (int currentRow = 0; currentRow < GRID_HEIGHT; currentRow++)
    {
        for (int currentColumn = 0; currentColumn < GRID_WIDTH; currentColumn++)
        {
            if (grid[currentRow][currentColumn]->isTurn())
            {
                grid[currentRow][currentColumn]->move();
            }
        }
    }
}

City::~City() {

}


void City::setOrganism(Organism *organism, int x, int y)
{
    grid[y][x] = organism;
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


//overload
ostream &operator<<(ostream &output, City &city) {
    cout << "Current state: " << endl;
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
//City::~City() {
//
//}