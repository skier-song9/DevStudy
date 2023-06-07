#include "point.hpp"
#include <iostream>

class Point;

class Coordinate{
public:
    double distance(Point const &point){
        double dist = std::sqrt(std::pow((x-point.x),2)+std::pow((y-point.y,2)));
        return dist;
    }
private:
    int const x{};
    int const y{};
};

class Point{
    friend class Coordinate;
public:
    Point() = default;
    Point(int const x, int const y):x{x},y{y}{}
public:
    friend
};



int main(int argc, char const *argv[])
{
    std::cout << "friend functions" << "\n";

    Point point{10,20};
    setPoint(point,100,200);
    setPoint(point,500);
    std::cout << "point = " << point << "\n";
    
    std::cout << "done..." << "\n";
    return 0;
}
