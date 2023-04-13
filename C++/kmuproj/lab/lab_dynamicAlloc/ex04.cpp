#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    const int SIZE = 5;
    int *ptr = new int[SIZE]{10,20,30,40,50};

    for (int i = 0; i<SIZE; i++){
        cout << ptr[i] << endl;
    }

    delete[] ptr;

    return 0;
}
