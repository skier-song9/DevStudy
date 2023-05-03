#include <iostream>
using namespace std;

struct Point{
    int x;
    int y;
};

void printPoints(Point arr[], const int size);

int main(int argc, char const *argv[])
{
    const int SIZE = 5;
    Point arr[SIZE]{};

    printPoints(arr,SIZE);

    return 0;
}

void printPoints(Point arr[], const int size){
    for(int i = 0; i<size; i++){
        cout << "arr[" << i << "] = (" << arr[i].x << ", " << arr[i].y << ")" << endl; 
    }
    // 만약 매개변수를 Point *arr처럼 포인터 변수를 운용할 경우 화살표 사용
    // for(int i = 0; i<size; i++){
    //     cout << "arr[" << i << "] = (" << (arr+i)->x << ", " << (arr+i)->y << ")" << endl; 
    // }
} 