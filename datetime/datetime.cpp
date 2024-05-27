#include "datetime.h"
#include <iostream>
#include <string>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

vector<int> dates{};

vector<int> find_str(string s, string del) {
    // Use find function to find 1st position of delimiter.
    int end = s.find(del);
    vector<int> date{};
    while (end != -1) { // Loop until no delimiter is left in the string.
        date.push_back(stoi(s.substr(0, end)));
        s.erase(s.begin(), s.begin() + end + 1);
        end = s.find(del);
    }
    date.push_back(stoi(s));
    return date;
}

Date::Date(int day, int month, int year)
{
    curYear = year;
    JulianDate = DateToJulian(day, month, year);
}

Date::Date(string date)
{
    dates = find_str(date, ".");
    curYear = dates[2];
    JulianDate = DateToJulian(dates[0], dates[1], dates[2]);
 }

Date::Date(int day, string month, int year)
{
    map<string, int> strMonth{
        {"Jan", 1},
        {"Feb", 2},
        {"Mar", 3},
        {"Apr", 4},
        {"May", 5},
        {"Jun", 6},
        {"Jul", 7},
        {"Agu", 8},
        {"Sep", 9},
        {"Oct", 10},
        {"Nov", 11},
        {"Dec", 12}};
    JulianDate = DateToJulian(day, strMonth[month], year);
    curYear = year;
}

Date::~Date()
{
    JulianDate = 0;
    dates.clear();
}

double Date::DateToJulian(int day, int month, int year)
{
    checkDate(day, month, year);

    double gregorianAdjustment = 1;
    if (year < 1582)
        gregorianAdjustment = 0;
    if (year <= 1582 && month < 10)
        gregorianAdjustment = 0;
    if (year <= 1582 && month == 10 && day < 5)
        gregorianAdjustment = 0;
    double JulianDate = -1 * (int)(7 * ((int)((month + 9) / 12) + year) / 4);

    int sign = 1;
    if ((month - 9) < 0)
        sign = -1;
    int absDiff = month - 9;
    if (absDiff < 0)
        absDiff *= -1;
    double j1 = (int)(year + sign * (int)(absDiff / 7));
    j1 = -1 * (int)((::floor(j1 / 100) + 1) * 3 / 4);
    JulianDate = JulianDate + (int)(275 * month / 9) + day + (gregorianAdjustment * j1);
    JulianDate = JulianDate + 1721027 + 2 * gregorianAdjustment + 367 * year - 0.5;

    return JulianDate;
}

void Date::JulianToDate(double JulianDate)
{
    double x1 = ::floor(JulianDate + 0.5);
    double x2 = ::floor((x1 - 1867216.25) / 36524.25);
    double x3 = ::floor(x2 / 4);
    double x4 = x1 + 1 + x2 - x3;
    double x5 = x4 + 1524;
    double x6 = ::floor((x5 - 122.1) / 365.25);
    double x7 = ::floor(365.25 * x6);
    double x8 = ::floor((x5 - x7) / 30.6001);

    double day = ::floor(x5 - x7 - ::floor(30.6001 * x8));
    double month = x8 < 14 ? x8 - 1 : x8 - 13;
    double year = month > 2 ? x6 - 4716 : x6 - 4715;

    dates.clear();
    dates.push_back(static_cast<int>(day));
    dates.push_back(static_cast<int>(month));
    dates.push_back(static_cast<int>(year));
}

string Date::weekDay()
{
    string daysOfweek[]{"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
    return daysOfweek[static_cast<int>(JulianDate + 0.5) % 7];
}

void Date::calculateEasterDate()
{
    int year = curYear;
    int x1 = year % 19;
    int x2 = year / 100;
    int x3 = year % 100;
    int x4 = x2 / 4;
    int x5 = x2 % 4;
    int x6 = (x2 + 8) / 25;
    int x7 = (x2 - x6 + 1) / 3;
    int x8 = (19 * x1 + x2 - x4 - x7 + 15) % 30;
    int x9 = x3 / 4;
    int x10 = x3 % 4;
    int x11 = (32 + 2 * x5 + 2 * x9 - x8 - x10) % 7;
    int x12 = (x1 + 11 * x8 + 22 * x11) / 451;
    int month = (x8 + x11 - 7 * x12 + 114) / 31;
    int day = ((x8 + x11 - 7 * x12 + 114) % 31) + 1;

    // Католическая пасха считается

    cout << "This year's easter date: " << day << "." << month << "." << year << endl;
}

void Date::checkDate(int day, int month, int year)
{
    if (month > 12 || month < 1)
        throw DateException("Error: month error");

    if (day < 1)
        throw DateException("Error: day error");

    int daysInMonth = 0;
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        daysInMonth = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        daysInMonth = 30;
        break;
    case 2:
        daysInMonth = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28;
        break;
    default:
        throw DateException("Error: month error");
    }

    if (day > daysInMonth)
        throw DateException("Error: invalid days count");
}

double Date::operator-(const Date &other)
{
    return this->JulianDate < other.JulianDate ? other.JulianDate - this->JulianDate : this->JulianDate - other.JulianDate;
}

ostream &operator<<(ostream &os, const Date &date)
{
    Date temp = date;
    temp.JulianToDate(date.JulianDate);

    os << dates[0] << "." << dates[1] << "." << dates[2];
    return os;
}