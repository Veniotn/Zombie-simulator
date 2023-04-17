//
// Created by nick on 4/9/2023.
//

#include "../inc/Organism.h"
#include "../inc/GameSpecs.h"


Organism::Organism()
{
    this->width = 0;
    this->height = 0;
    this->species = EMPTY;
    this->moved = false;
}
Organism::Organism(City *city, int width, int height)
{
    this->city = city;
    this->width = width;
    this->height = height;
    this->moved = false;

}

void Organism::setPosition(int x, int y)
{
    this->x = x;
    this->y = y;
}



bool Organism::hasMoved()
{
    return this->moved;
}
void Organism::setMoved(bool moved)
{
    this->moved = moved;
}

ostream &operator<<(ostream &output, Organism *organism)
{

    if (organism->getSpecies() == Organism::HUMAN)
    {
        output << "\033[48;5;" << HUMAN_COLOR << "m" << HUMAN_CHARACTER << "\033[0m";
        return output;
    } else if (organism->getSpecies() == Organism::ZOMBIE)
    {
        output << "\033[38;5;" << ZOMBIE_COLOR << "m" << "\033[48;5;22m" << ZOMBIE_CHARACTER << "\033[0m";
        return output;
    } else
    {
        output << "\033[47;5;16m" <<  EMPTY_SPACE << "\033[0m";
        return output;
    }
}

Organism::~Organism() {}
void Organism::endTurn() {}
vector<Organism *> Organism::getTargets() {return vector<Organism *>();}
void Organism::move() {}



