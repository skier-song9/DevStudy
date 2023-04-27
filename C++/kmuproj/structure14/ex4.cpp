#include <iostream>
using namespace std;

struct Point{
    int x;
    int y;
};

void printPoints(Point *points, const int size);

int main(int argc, char const *argv[])
{
    
    Point points[] = {
        {10,20},
        {30,40},
        {50,60}
    };

    const int size = sizeof(points)/sizeof(points[0]);

    // cout << points[0].x << " , " << points[0].y << endl;
    // cout << points[1].x << " , " << points[1].y << endl;
    // cout << points[2].x << " , " << points[2].y << endl;

    printPoints(points,size);

    return 0;
}

void printPoints(Point *points, const int size){
    for(int i=0; i<size; i++){
        // cout << points[i].x << " , " << points[i].y << endl;
        //cout << (*(points+i)).x << " , " << (*(points+i)).y << endl;
        cout << (points + i)->x << " , " << (points + i )->y << endl; 
    }
};