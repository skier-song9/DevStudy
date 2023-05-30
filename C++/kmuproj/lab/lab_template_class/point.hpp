#ifndef POINT_H
#define POINT_H
#include <iostream>
class Point {
public:
    Point() = default;
    Point(int const x, int const y) : x{x}, y{y} {}
public:
    inline int getX () const;
    inline int getY () const;
    friend inline void setPoint (Point &point, int const x, int const y);
    friend inline std::ostream &operator<<(std::ostream &os , Point const &point);
private:
    int x{};
    int y{};
};
int Point::getX () const { return x;}
int Point::getY () const { return y;}
void setPoint (Point &point, int const x, int const y){
    point.x= x, point.y =y;
}
std::ostream &operator<<( ostream os , Point const &point){
    os << "(" << point.x << ", " << point.y << ")";
    return os;
}
#endif /* POINT_H */