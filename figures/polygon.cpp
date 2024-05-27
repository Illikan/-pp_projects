#include "figures.h"
#include <cmath>
Point2d::Point2d(double new_x, double new_y)
{
    this->x = new_x;
    this->y = new_y;
}

Point2d &Point2d::operator=(Point2d point)
{
    this->x = point.x;
    this->y = point.y;
    return *this;
}

double &Point2d::get_x()
{
    return this->x;
}

double &Point2d::get_y()
{
    return this->y;
}

Point2d::Point2d()
{
    this->y = 0.0;
    this->x = 0.0;
}

Polygon::Polygon(std::vector<Point2d> &new_points)
{
    this->name = "Polygon";
    this->points.resize(new_points.size());
    for (int i = 0; i < new_points.size(); i++)
    {
        this->points[i] = new_points[i];
    }
}
Point2d Polygon::operator[](unsigned long index) const
{
    if (index < 0 && index >= this->points.size())
    {
        throw std::exception();
    }
    return this->points[index];
}

double Polygon::area()
{
    double a = 0, b = 0;
    for (int i = 1; i < this->points.size(); i++)
    {
        a += points[i - 1].get_x() * points[i].get_y();
        b += points[i - 1].get_y() * points[i].get_x();
    }
    return abs(a - b);
}

double Polygon::perimeter()
{
    double ans = 0;
    for (int i = 0; i < this->points.size() - 1; i++)
    {
        ans += sqrt((points[i + 1].get_x() - points[i].get_x()) *
                        (points[i + 1].get_x() - points[i].get_x()) +
                    (points[i + 1].get_y() - points[i].get_y()) *
                        (points[i + 1].get_y() - points[i].get_y()));
    }
    ans += sqrt((points[0].get_x() - points[this->points.size() - 1].get_x()) *
                    (points[0].get_x() - points[this->points.size() - 1].get_x()) +
                (points[0].get_y() - points[this->points.size() - 1].get_y()) *
                    (points[0].get_y() - points[this->points.size() - 1].get_y()));
    return ans;
}