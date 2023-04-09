//
// Created by nick on 4/9/2023.
//

#include "../inc/Organism.h"

Organism::Organism()
{

}

Organism::Organism(City *city, int width, int height)
{
    this->city = city;
    this->width = width;
    this->height = height;

}


void Organism::setPosition(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Organism::endTurn()
{

}

bool Organism::isTurn()
{
    return false;
}

ostream &operator<<(ostream &output, Organism *organism)
{
    if (organism->getSpecies() == Organism::HUMAN){
        output << "\033[48;5;20m" << " h " << "\033[0m";
        return output;
    } else{
        output << "\033[38;5;16m" << "\033[48;5;22m" << " z " << "\033[0m";
        return output;
    }
}

Organism::~Organism()
{

}
