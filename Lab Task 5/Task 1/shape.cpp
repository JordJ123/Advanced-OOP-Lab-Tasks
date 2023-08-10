#include <sstream>
#include <string>
#include "shape.h"

Circle::Circle(double x, double y, double r) : x(x), y(y), r(r) {};

std::string Circle::to_string() const {
    std::stringstream sstr;
    sstr << "Circle Centered at (" << x << ", " << y << ") with radius " << r;
    return sstr.str();
};

void Circle::centre_at(double x, double y) {
    this->x = x;
    this->y = y;
}