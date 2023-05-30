#include "point.hpp"
#include "ppoint.hpp"
#include <iostream>
int main(int
argc , char argv [])
std::
cout << "template
<< "
n";
Point<double> point{10.5, 10.7};
std::
cout << point.getX () = " << point.getX () << n";
std::
cout << point.getY () = " << point.getY () << n";
std::
cout << point << n";
PPoint
pp;
pp.setX
(
pp.setY
(
std::
cout << pp << n";
std::
cout << "
<< "
n";
return 0;
}
