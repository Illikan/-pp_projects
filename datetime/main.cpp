#include <iostream>
#include "datetime.h"

int main()
{
    Date a(29, 2, 2020);
    Date b("12.12.2023"); 
    Date c(25, "Mar", 2024);

    std::cout << "1st date: " << a << std::endl;
    std::cout << "2nd date: " << b << std::endl;
    std::cout << "Difference between days: " << a - b << std::endl;

    std::cout << "Weekday 1st: " << a.weekDay() << std::endl;
    std::cout << "Weekday 2nd: " << b.weekDay() << std::endl;
    std::cout << "Weekday 3rd " << c.weekDay() << std::endl;

    a.calculateEasterDate();
    b.calculateEasterDate();
    c.calculateEasterDate();

    return 0;
}