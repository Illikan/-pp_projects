#include <iostream>
#include "geometry.h"
#ifndef _SEARCH_H
#define _SEARCH_H
using namespace std;

void findAndInsert(Triangle* trArray, int length, const Triangle& triangle);

void searchMaxArea(const Point* pointArray, int pointNum, Triangle* trArray, int maxTrNum);

#endif