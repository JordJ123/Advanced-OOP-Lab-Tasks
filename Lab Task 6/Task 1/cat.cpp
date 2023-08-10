#include <string>
#include "cat.h"

Cat::Cat(const std::string& name, const unsigned int& lives) 
    : name(name), lives(lives) {};

void Cat::setName(const std::string& name) {
    this->name = name;
}

void Cat::setLives(const unsigned int& lives) {
    this->lives = lives;
}

std::string& Cat::getName() {
    return name;
}

unsigned int& Cat::getLives() {
    return lives;
}

std::ostream &operator<<(std::ostream &os, const Cat& cat) {
    os << cat.name << " has " << cat.lives << " lives";
    return os;
}