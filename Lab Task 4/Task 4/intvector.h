#ifndef INTVECTOR
#define INTVECTOR

#include <ostream>

class IntVector {

    //Attributes
    private:
        int *data = nullptr;
        unsigned int pos = 0;
        unsigned int length = 0;

    //Constructors & Destructors
    public:
        IntVector(const unsigned int length);
        ~IntVector();

    //Methods
    public:
        friend std::ostream& operator<<(std::ostream &os, const IntVector &iv);
        void push(const int value);
        int pop();
        void resize(const unsigned int new_length);
        void print();

};

#endif