//
// Created by nick on 4/9/2023.
//

#include "../inc/Zombie.h"

Zombie::Zombie(City *city, int width, int height) {
    this->city    = city;
    this->width   = width;
    this->height  = height;
    this->species = ZOMBIE;
}

Zombie::Zombie() {}

void Zombie::move() {}

Zombie::~Zombie() {

}
