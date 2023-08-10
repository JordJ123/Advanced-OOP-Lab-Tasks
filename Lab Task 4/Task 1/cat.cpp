#include <iostream>
#include "cat.h"

Cat::Cat(std::string name) : name(name), lives(9) { 
    std::cout << "Constructor called with name " << this->name + ".\n";
}

Cat::Cat(std::string name, unsigned int lives) : name(name), lives(lives) { 
    std::cout << "Constructor called with name and lives " << this->name 
        << " & " << this->lives << ".\n";
}

Cat::~Cat() {
    std::cout << "Destructor called for the Cat with name and lives " << this->name 
        << " & " << this->lives << ".\n";
}

std::string& Cat::get_name() {
    return this->name;
}

unsigned int& Cat::get_lives() {
    return this->lives;
}