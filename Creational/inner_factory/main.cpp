#include <iostream>
#include "Point.h"
int main()
{
    auto p1 = Point::Factory.NewCartesian(3.0, 4.0);
    auto p2 = Point::Factory.NewPolar(5.0, M_PI_4);
    std::cout << "Point p1 "<< p1 << '\n'
              << "Point p2 "<< p2 << std::endl;
    return 0;
}