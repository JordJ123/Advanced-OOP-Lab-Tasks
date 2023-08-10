#ifndef SHAPE
#define SHAPE

#include <string>

class Shape {

    //Constructors & Destructors
    public:
        Shape() = default;
        ~Shape() = default;

    //Methods
    public:
        virtual std::string to_string() const = 0;
        virtual void centre_at(double x, double y) = 0;

};

class Circle : public Shape {

    //Attributes
    private:
        double x;
        double y;
        double r;

    //Constructors & Destructors
    public:
        Circle(double x, double y, double r);
        ~Circle() = default;

    //Methods
    public:
        virtual std::string to_string() const;
        virtual void centre_at(double x, double y);

};

class Rectangle : public Shape {

    //Attributes
    private:
        double x0;
        double y0;
        double x1;
        double y1;

    //Constructor & Destructor
    public:
        Rectangle(double x0, double y0, double x1, double y1);
        ~Rectangle() = default;

    //Methods
    public:
        virtual std::string to_string() const;
        virtual void centre_at(double x, double y);

};

class Triangle: public Shape {
    
    //Attributes
    private:
        double x0;
        double y0;
        double x1;
        double y1;
        double x2;
        double y2;
    
    //Constructor & Destructor
    public:
        Triangle(double x0, double y0, double x1, double y1,
            double x2, double y2);
        ~Triangle() = default;

    //Methods
    public:
        virtual std::string to_string() const;
        virtual void centre_at(double x, double y);

};

#endif