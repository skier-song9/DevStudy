#include <iostream>
using namespace std;

struct Point{
    int x;
    int y;
};

void printPoint(Point *ptr);
void printPoints(Point **arr, const int size);

int main(int argc, char const *argv[])
{
    const int SIZE = 3;
    Point *arr[SIZE]{};    

    arr[0] = new Point{10,11};
    arr[1] = new Point{20,21};
    arr[2] = new Point{30,31};

    printPoints(arr,SIZE);

    return 0;
}

void printPoint(Point *ptr){
    cout << ptr->x << ", " << ptr->y << ")" << endl;
}

void printPoints(Point **arr, const int size){
    for (int i{}; i<size; i++){
        cout << "(" << arr[i]->x << ", " << arr[i]->y << ")" << endl;
        //또는 cout << "(" << (*(arr+i))->x << ", " << (*(arr+i))->y << ")" << endl;
    }
}