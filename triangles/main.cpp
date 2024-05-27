#include <iostream>
#include <locale.h>
#include "geometry.h"
#include "search.h"
#include "file.h"

using namespace std;

int main()
{
  setlocale(LC_ALL, "Russian");

  char *inFileName = new char[512];
  char *outFileName = new char[512];

  cout << "Enter input file name: ";
  cin.getline(inFileName, 512);

  cout << "Enter output file name: ";
  cin.getline(outFileName, 512);

  int pointNum = countPoints(inFileName);
  if (pointNum < 0)
  {
    cout << "Input file does not exist" << endl;
    return -2;
  }

  Point *pointArray = new Point[pointNum];

  if (!inPoints(inFileName, pointArray, pointNum))
  {
    cout << "Points can't be read" << endl;
    return -3;
  }

  const int maxTrNum = 3;
  Triangle trArray[maxTrNum];
  
  searchMaxArea(pointArray, pointNum, trArray, maxTrNum);
 
  cout << "Created file with answers" << endl;
  delete[] pointArray;
  delete[] inFileName;
  delete[] outFileName;

  return 0;
}