#include "point.hpp"

// void setPoint(Point &point, int const x, int const y){
//     point.x = x, point.y = y;
// }

std::ostream &operator<<(std::ostream &os, Point const &point){
    os << "(" << point.x << ", " << point.y << ")" << "\n";
    return os;
}