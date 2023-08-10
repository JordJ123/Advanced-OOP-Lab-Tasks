#include <iostream>
#include <string>
#include "cat.h"

int main(int argc, char* argv[]) {
    
    const int catNumber((argc - 1) % 2 == 0 ? (argc - 1) / 2 : (argc) / 2);
    std::cout << "Allocating clowder of size " << catNumber << "\n";
    Cat *cats = new Cat[catNumber];

    int i;
    int currentCat = 0;
    if ((argc - 1) % 2 == 0) {
        for (i = 1; i < argc; i++) {
            std::string name = argv[i];
            unsigned int lives = std::stoi(argv[++i]);
            cats[currentCat].set_name(name);
            cats[currentCat].set_lives(lives);
            currentCat++;
        }
    } else {
        for (i = 1; i < argc - 1; i++) {
            std::string name = argv[i];
            unsigned int lives = std::stoi(argv[++i]);
            cats[currentCat].set_name(name);
            cats[currentCat].set_lives(lives);
            currentCat++;
        } 
        std::string name = argv[i];
        cats[currentCat].set_name(name);
    }

    int j;
    for (j = 0; j < catNumber; j++) {
        std::cout << cats[j].get_name() << " has "
                  << cats[j].get_lives() << " lives." << std::endl;
    }

    delete [] cats;

    return 0;
}