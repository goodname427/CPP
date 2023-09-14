#include <iostream>
#include "math.h"
using namespace std;

class Shape
{
public:
    virtual double Size()=0;
};

class Rectangle : public Shape
{
public:
    Rectangle(double width, double height) : width(width), height(height) {}
    double Size() { return width * height; }
    double width;
    double height;
};

class Circle : public Shape
{
public:
    Circle(double radius) : radius(radius) {}
    double Size() { return 3.14 * radius * radius; }
    double radius;
};

class Triangle : public Shape
{
public:
    Triangle(double a, double b, double c) : a(a), b(b), c(c) {}
    double Size()
    {
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
    double a;
    double b;
    double c;
};

double SumSize(Shape *shapes[], int n)
{
    double s = 0;
    for (int i = 0; i < n; i++)
    {
        s += shapes[i]->Size();
    }
    return s;
}

int main()
{
    Shape *shapes[] = {
        new Rectangle(1, 3),
        new Rectangle(4, 2),
        new Rectangle(6, 23),
        new Circle(6),
        new Circle(3),
        new Circle(2.4),
        new Triangle(2, 3, 4),
        new Triangle(6, 2, 5.3),
        new Triangle(5, 3, 4)
    };
    cout << SumSize(shapes, 9) << endl;
    return 0;
}