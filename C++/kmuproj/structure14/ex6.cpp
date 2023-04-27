#include <iostream>
using namespace std;

struct Point{
    int x;
    int y;
};

void printPoint(Point *point);

int main(int argc, char const *argv[])
{
    
    Point point{10,20};
    printPoint(point); 

    print = movePoint(point,100,100);

    delete point;

    return 0;
}

void printPoint(Point *point){
    // cout << (*point).x << " , " << (*point).y << endl;
    cout << point->x << " , " << point->y << endl;
}

Point movePoint(Point point, const int dx, const int dy){
    point.x += dx;
    point.y += dy;

    // return point; //반환하지 않아도 값이 변경되어 있음.
}