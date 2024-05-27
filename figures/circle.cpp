#define _USE_MATH_DEFINES
#include "figures.h"
#include <cmath>
#include <math.h>
Circle::Circle(double new_r, double new_rr)
{
    if (new_rr == 0)
        this->name = "Circle";
    else
        this->name = "Elipse";
    this->r = new_r;
    this->rr = new_rr;
}

double Circle::area()
{
    if (this->rr == 0)
        return this->r * this->r * M_PI;
    else
        return this->r * this->rr * M_PI;
}
double Circle::perimeter()
{
    if (this->rr == 0)
        return this->r * M_PI * 2;
    else
        return M_PI * (this->r + this->rr);
}