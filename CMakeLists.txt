cmake_minimum_required(VERSION 3.23)
project(4_Zombies)

set(CMAKE_CXX_STANDARD 17)

add_executable(4_Zombies src/main.cpp inc/Organism.h inc/GameSpecs.h inc/City.h inc/Human.h inc/Zombie.h src/City.cpp src/GameSpec.cpp src/Human.cpp src/Zombie.cpp src/Organism.cpp src/Empty.cpp inc/Empty.h)
