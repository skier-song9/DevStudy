#ifndef POINT_H
#define POINT_H

#include <iostream>

class Poiont{
public:
    Point() = default;
    Point(int const x, int const y) : x{x}, y{y} {}
private:
    friend inline void setPoint(Point &point,int const x, int const y);
    friend inline void setPoint(Point &point,int const x);
    friend std::ostream &operator<<(std::ostream &os, Point const &point);
private:
    int x{};
    int y{};
};

void setPoint(Point &point, int const x, int const y){
    point.x = x, point.y = y;
}

void setPoint(Point &point, int const x){ point.x = x; }

#endif