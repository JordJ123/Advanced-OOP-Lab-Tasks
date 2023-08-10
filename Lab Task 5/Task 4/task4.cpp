#include <iostream>
#include "shape.h"

int main(int argc , char *argv[]) {
    
    //Rectangle
    Shape *y = new Polygon (8, 0, 0, 0, 1, 1, 1, 1, 0); // x, y, r
    std::cout << y->to_string() << std::endl;
    y->centre_at(-2.5, 2.5);
    std::cout << y->to_string() << std::endl;
    delete y;

    //Triangle
    Shape *x = new Polygon (6, 0, 0, 1, 1, 0, 1); // x, y, r
    std::cout << x->to_string() << std::endl;
    x->centre_at(-2.5, 2.5);
    std::cout << x->to_string() << std::endl;
    delete x;

    return 0;

}