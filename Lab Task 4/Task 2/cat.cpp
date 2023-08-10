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

void Cat::set_name(std::string& name) {
    std::cout << "set_name called with value " << name << ".\n";
    this->name = name;
}

void Cat::set_lives(unsigned int& lives) {
    std::cout << "set_lives called with value " << lives << ".\n";
    if (lives >= this->lives) {
        return;
    }
    if (lives == 0) {
        std::string name = "The Cat formerly known as " + get_name();
        set_name(name);
    }
    this->lives = lives;
}

std::string& Cat::get_name() {
    return this->name;
}

unsigned int& Cat::get_lives() {
    return this->lives;
}