#ifndef POINT_H
#define POINT_H
#include <cmath>
#include <ostream>

class Point
{
  Point(float x, float y)
    : x(x), y(y) {}
  // Inner factory is typical artifact of C#, Java,
  // and other languages that lack the 'friend' keyword.
  class PointFactory
  {
      PointFactory() = default;
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
public:
    float x, y;
    static PointFactory Factory;
    friend std::ostream& operator<<(std::ostream& os, const Point& p)
    {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

#endif //POINT_H
