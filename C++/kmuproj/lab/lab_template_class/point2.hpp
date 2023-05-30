#ifndef POINT_H
#define POINT_H
#include <iostream>
tmeplate <typename T> class Point {
public:
    Point() = default;
    Point(T const x, T const y) : x{x}, y{y} {}
public:
    inline T getX () const;
    inline T getY () const;
    template <typename P>
    friend inline void setPoint (Point<P> &point, P const x, P const y);
    template <typename E>
    friend inline std::ostream &operator<<(std::ostream &os , Point<E> const &point);
private:
    int x{};
    int y{};
};
template <typename T> T Point::getX () const { return x;}
template <typename T> T Point::getY () const { return y;}
template <typename E> void setPoint (Point<E> &point, E const x, E const y){
    point.x= x, point.y =y;
}
template <typename E>
std::ostream &operator<<(std::ostream os , Point<E> const &point){
    os << "(" << point.x << ", " << point.y << ")";
    return os;
}
#endif /* POINT_H */