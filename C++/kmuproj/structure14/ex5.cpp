#include <iostream>
using namespace std;

struct Point{
    int x;
    int y;
};

void printPoint(Point *point);

int main(int argc, char const *argv[])
{
    
    Point *point = new Point{10,20};

    printPoint(point); // point에는 new로 할당한 메모리의 주소가 있다.

    delete point;

    return 0;
}

void printPoint(Point *point){
    // cout << (*point).x << " , " << (*point).y << endl;
    cout << point->x << " , " << point->y << endl;
}