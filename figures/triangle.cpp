#include "figures.h"
#include <cmath>
Triangle::Triangle(double new_a, double new_b, double new_c)
{
    this->name = "Triangle";
    this->a = new_a;
    this->b = new_c;
    this->c = new_b;
}

double Triangle::area()
{
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double Triangle::perimeter()
{
    return a + b + c;
}