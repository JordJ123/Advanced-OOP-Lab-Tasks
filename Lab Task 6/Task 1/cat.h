#ifndef CAT_H
#define CAT_H

#include <functional>
#include <iostream>
#include <string>
#include <sstream>

class Cat {

    //Attributes
    private:
        std::string name;
        unsigned int lives;

    //Constructor
    public:
        Cat(const std::string& name, const unsigned int& lives);

    //Setters & Getters
    public:
        void setName(const std::string& name);
        void setLives(const unsigned int& lives);
        std::string& getName();
        unsigned int& getLives();
    
    //Other
    public:
        friend std::ostream &operator<<(std::ostream &os, const Cat& cat);

};

namespace std {
    template <>
    struct hash <Cat> {
        size_t operator()(const Cat &obj) const {
            std::stringstream ss;
            ss << obj;
            return std::hash<std::string>()(ss.str());
        }
    };
}

#endif
