#include <iostream>
using namespace std;

struct Point{
    int x;
    int y;
};

void printPoint(Point *p);

int main(int argc, char const *argv[])
{
    
    const int SIZE = 5;
    Point arr[SIZE]{
        {10,11},
        {20,21},
        {30,31},
        {40,41},
        {50,51}
    };

    Point *ptr = &arr[1];
    cout << "ptr = ";
    printPoint(ptr);
    return 0;
}

void printPoint(Point *p){
    cout << "(" << p->x << ", " << p->y << ")" << endl;
}