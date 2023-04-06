#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    const int ROWS = 3, COLS = 5;
    int arr[ROWS][COLS] = {
        {0,1,2,3,4},
        {5,6,7,8,9},
        {10,11,12,13,14}
    };

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

