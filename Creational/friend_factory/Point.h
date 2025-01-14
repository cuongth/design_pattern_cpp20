#ifndef POINT_H
#define POINT_H
#include <cmath>

class Point
{
    Point(float x, float y)
        : x(x), y(y) {}
public:
    float x, y;
    friend class PointFactory;
    friend std::ostream& operator<<(std::ostream& os, const Point& p)
    {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

// Factory creates Point instance.
class PointFactory
{
public:
    static Point NewCartesian(float x, float y)
    {
        return Point{x, y};
    }

    static Point NewPolar(float r, float theta)
    {
        return Point{r * std::cos(theta), r * std::sin(theta)};
    }
};

#endif //POINT_H
