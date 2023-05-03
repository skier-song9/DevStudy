#include <iostream>
using namespace std;

struct Point{
    int x;
    int y;
};

void printPoints(Point *arr, const int size);
void printPoint(Point *ptr);

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

    printPoints(arr,SIZE);

    return 0;
}

void printPoint(Point *ptr){
    cout << ptr->x << ", " << ptr->y << ")" << endl;
}

void printPoints(Point *arr, const int size){
    for (int i=0;i<size;i++){
        cout << "arr[" <<  i << "] = ("; 
        printPoint(arr+i);
    }
}