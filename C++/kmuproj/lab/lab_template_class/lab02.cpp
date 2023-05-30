#include "point2.hpp"
#include <iostream>
int main(int argc , char argv []){
    std::cout << "template " << "\n";
    Point point{10, 10};
    std::cout << "point.getX () = " << point.getX () << "\n";
    std::cout << "point.getY () = " << point.getY () << "\n";
    std::cout << point << "\n";
    std::cout << "done... " << "\n";
return 0;
}