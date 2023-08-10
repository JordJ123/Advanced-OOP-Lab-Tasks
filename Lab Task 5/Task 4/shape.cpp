#include <cstdarg>
#include <iomanip>
#include <iostream>
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

Polygon::Polygon(const unsigned int num_coords, ...) : 
    num_sides(num_coords >= 6 ? floor(num_coords / 2) : 0),
    coordinates(new Coordinates*[this->num_sides]) {
    va_list args;
    va_start(args, num_coords);
    for (int i = 0; i < this->num_sides; i++) {
        this->coordinates[i] = new Coordinates{(double) va_arg(args, int),
            (double) va_arg(args, int)};
    }
    va_end(args);
};

Polygon::~Polygon() {
    for (int i = 0; i < this->num_sides; i++) {
        delete this->coordinates[i];
    }
    delete [] this->coordinates;
}

std::string Polygon::to_string() const {
    std::stringstream sstr;
    sstr << std::setprecision(2) << std::fixed;
    sstr << "Polygon at [";
    for (int i = 0; i < this->num_sides; i++) {
        sstr << "(" << coordinates[i]->x << ", " << coordinates[i]->y << ")";
        if (i != this->num_sides - 1) {
            sstr << ", ";
        }
    }
    sstr << "] with side lengths ";
    for (int i = 0; i < this->num_sides; i++) {
        sstr << get_side_length(i);
        if (i != this->num_sides - 1) {
            sstr << ", ";
        }
    }
    return sstr.str();
};

void Polygon::centre_at(double x, double y) {
    double xCentroid;
    double xDistance;
    for (int i = 0; i < num_sides; i++) {
        xCentroid += coordinates[i]->x;
    }
    xCentroid /= num_sides;
    xDistance = xCentroid - x;
    
    double yCentroid;
    double yDistance;
    for (int i = 0; i < num_sides; i++) {
        yCentroid += coordinates[i]->y;
    }
    yCentroid /= num_sides;
    yDistance = yCentroid - y;

    for (int i = 0; i < num_sides; i++) {
        coordinates[i]->x -= xDistance;
        coordinates[i]->y -= yDistance;
    }
}

double Polygon::get_side_length(const unsigned int &side) const {
    int c = (side == this->num_sides - 1 ? 0 : side + 1);
    return sqrt( 
        ((coordinates[c]->x - coordinates[side]->x) * (coordinates[c]->x - coordinates[side]->x))
        + ((coordinates[c]->y - coordinates[side]->y) * (coordinates[c]->y - coordinates[side]->y)));
}