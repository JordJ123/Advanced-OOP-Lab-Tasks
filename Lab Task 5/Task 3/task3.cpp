#include <iostream>
#include "shape.h"

int main(int argc , char *argv[]) {
    
    Shape **xs = new Shape*[10];
    xs[0] = new Circle(0, 0, 1);
    xs[1] = new Rectangle (0, 1, 1, 0);
    xs[2] = new Triangle(0, 0, 1, 1, 0, 1);
    xs[3] = new Circle(2, 6, 3);
    xs[4] = new Rectangle (12, 2, 4, 32);
    xs[5] = new Triangle(-1, -1, 0, 0, 1, 1);
    xs[6] = new Circle(7, 6, 1);
    xs[7] = new Rectangle (23, 23, 2, 2);
    xs[8] = new Triangle(12, 56, 34, 34, 2, 3);
    xs[9] = new Circle(3, 234, 34);
    for (int i = 0; i < 10; i++) {
        std::cout << xs[i]->to_string() << std::endl;
    }
    std::cout << std::endl;
    for (int i = 0; i < 10; i++) {
        xs[i]->centre_at(0, 0);
        std::cout << xs[i]->to_string() << std::endl;
        delete xs[i];
    }
    delete [] xs;

    return 0;
    
}