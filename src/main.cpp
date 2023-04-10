//
// Created by W0068332 on 11/21/2021.
//
//Example main.cpp
//This supposes that city->step() calls the move method of each organism in the city
//in a single pass causing each to perform all tasks that it can.

#include "../inc/Organism.h"
#include "../inc/City.h"

using namespace std;

void ClearScreen()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

int main() {
    City *city = new City();
    string test = "";
    while (true){

        city->move();
        cout << *city;
    }

//    chrono:: milliseconds interval(INTERVAL);

//    while (city->hasDiversity()) { //while both humans and zombies exist
//        this_thread::sleep_for(interval);
//        ClearScreen();
//        city->move(); //includes all actions
//
//
//// Alternate multi-pass version with each activity happening in its own
//// pass through the array. Lends itself to prototyping and testing:
//        //   city->humansMove();
//        //   city->zombiesMoveEat();
//        //   city->humansRecruit();
//        //   city->zombiesRecruit();
//        //   city->zombiesStarve();
//        //   city->countOrganisms(Z or H goes here);
//
//        city->reset(); //resets moved flags
//        city->countOrganisms(Z or H goes here);// run once for each type
//        cout << *city; //prints city
//        cout << "GENERATION " << city->getGeneration() << endl;
//        cout << "HUMANS: " << city->countType(HUMAN_CH) << endl;
//        cout << "ZOMBIES: " << city->countType(ZOMBIE_CH) << endl;
//    }//end while
}//end main