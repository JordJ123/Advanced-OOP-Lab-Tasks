#ifndef CAT
#define CAT
//#pragma once sets the file to be included only once within a single compilation
//#pragma once isn't used by all c++ compiliers however

#include <string>

class Cat {

    //Attributes
    private:
        std::string name;
        unsigned int lives;

    //Constructors & Destructors
    public:
        Cat();
        Cat(std::string name);
        Cat(std::string name, unsigned int lives);
        ~Cat();

    //Setters
    public:
        void set_name(std::string& name);
        void set_lives(unsigned int& lives);

    //Getters
    public:
        std::string& get_name();
        unsigned int& get_lives();

};

#endif