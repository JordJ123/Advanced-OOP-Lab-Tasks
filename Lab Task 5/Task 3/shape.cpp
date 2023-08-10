#include <math.h>
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

Rectangle::Rectangle(double x0, double y0, double x1, double y1) : x0(x0), y0(y0), x1(x1), y1(y1) {};

std::string Rectangle::to_string() const {
    std::stringstream sstr;
    sstr << "Rectangle at [(" << x0 << ", " << y0 << "), (" << x1 << ", " << y1 
        << ")] with width " << abs(x1 - x0) << ", height " << abs(y1 - y0);
    return sstr.str();
};

void Rectangle::centre_at(double x, double y) {
    double width = abs(x1 - x0);
    double height = abs(y1 - y0);
    if (x0 < x1) {
        this->x0 = x - (width / 2);
        this->x1 = x + (width / 2);
    } else {
        this->x0 = x + (width / 2);
        this->x1 = x - (width / 2);
    }
    if (y0 < y1) {
        this->y0 = y - (height / 2);
        this->y1 = y + (height / 2);
    } else {
        this->y0 = y + (height / 2);
        this->y1 = y - (height / 2);
    }
}

Triangle::Triangle(double x0, double y0, double x1, double y1, double x2, double y2) 
    : x0(x0), y0(y0), x1(x1), y1(y1), x2(x2), y2(y2) {};

std::string Triangle::to_string() const {
    double side1 = sqrt( ((x1 - x0) * (x1 - x0)) + ((y1 - y0) * (y1 - y0)) );
    double side2 = sqrt( ((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)) );
    double side3 = sqrt( ((x2 - x0) * (x2 - x0)) + ((y2 - y0) * (y2 - y0)) );
    std::stringstream sstr;
    sstr << "Triangle at [(" << x0 << ", " << y0 << "), (" << x1 << ", " << y1 
        << "), (" << x2 << ", " << y2 << ")] with side lengths " << side1 << ", "
        << side2 << ", and " << side3;
    return sstr.str();
};


void Triangle::centre_at(double x, double y) {
    double xCentroid = (x0 + x1 + x2) / 3.0;
    double yCentroid = (y0 + y1 + y2) / 3.0;
    
    double xDistance = xCentroid - x;
    double yDistance = yCentroid - y;

    this->x0 = x0 - xDistance;
    this->x1 = x1 - xDistance;
    this->x2 = x2 - xDistance;
    this->y0 = y0 - yDistance;
    this->y1 = y1 - yDistance;
    this->y2 = y2 - yDistance;
}