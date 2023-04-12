//
// Created by nick on 4/10/2023.
//

#include "../inc/Empty.h"


Empty::Empty(City *city, int width, int height) {
    this->city = city;
    this->x = width;
    this->y = height;
    this->species = EMPTY;
}

Empty::~Empty() {

}

void Empty::endTurn() {
}
