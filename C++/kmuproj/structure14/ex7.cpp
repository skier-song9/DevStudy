#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;

    Point(const int x,const int y) : x{x}, y{y} {
        cout << "ctor invoked." << endl;
    }
};

void printPoint(Point point);

int main(int argc, char const *argv[])
{
    
    Point point{10,20};
    printPoint(point);

    return 0;
}

void printPoint(Point point){
    cout << point.x << " , " << point.y << endl;
}