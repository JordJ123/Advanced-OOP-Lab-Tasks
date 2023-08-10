#include <iostream>
#include "shape.h"

int main(int argc , char *argv[]) {
    
    //Rectangle
    Shape *y = new Rectangle (0, 1, 1, 0); // x, y, r
    std::cout << y->to_string() << std::endl;
    y->centre_at(-2.5, 2.5);
    std::cout << y->to_string() << std::endl;
    delete y;

    return 0;
}