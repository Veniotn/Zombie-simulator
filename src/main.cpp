//
// Created by W0068332 on 11/21/2021.
//
//Example main.cpp
//This supposes that city->step() calls the move method of each organism in the city
//in a single pass causing each to perform all tasks that it can.

#include "../inc/Organism.h"
#include "../inc/City.h"
#include "../inc/GameSpecs.h"

using namespace std;

void ClearScreen()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

int main() {
    City *city = new City();

    chrono::milliseconds interval(static_cast<long long>(INTERVAL));

    while (city->hasDiversity() && city->getCurrentIteration() <= ITERATIONS) { //while both humans and zombies exist

        this_thread::sleep_for(interval);
        ClearScreen();
        cout << *city;
        city->move();//includes all actions


          cout << "GENERATION " << city->getCurrentIteration() << endl;
          cout << "HUMANS: " << city->getHumanPopulation() << endl;
          cout << "ZOMBIES: " << city->getZombiePopulation() << endl;
    }//end while
}//end main