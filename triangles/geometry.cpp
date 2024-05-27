#include <iostream>
#include "geometry.h"

using namespace std;

Point::Point()
{
    x = 0;
    y = 0;
}

Point::Point(double _x, double _y)
{
    x = _x;
    y = _y;
}

double calculateDistance(const Point &p1, const Point &p2)
{
    return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

double calculateTriangleArea(Triangle &tr)
{
    Point *v = tr.vertexes;

    double a = calculateDistance(v[0], v[1]);
    double b = calculateDistance(v[1], v[2]);
    double c = calculateDistance(v[2], v[0]);

    return tr.area = calculateAreaBySides(a, b, c);
}

double calculateAreaBySides(double a, double b, double c)
{
    double p2 = (a + b + c) / 2.0;

    if (p2 <= 0.0 || p2 <= a || p2 <= b || p2 <= c)
        return 0.0;

    return sqrt(p2 * (p2 - a) * (p2 - b) * (p2 - c));
}

bool operator<=(const Triangle &tr1, const Triangle &tr2)
{
    return tr1.area <= tr2.area;
}

void deletePoint(Point &p)
{
    p.x = p.y = 0.0;
}

void deleteTriangle(Triangle &tr)
{
    for (int i = 0; i < 3; i++)
        deletePoint(tr.vertexes[i]);

    tr.area = 0.0;
}