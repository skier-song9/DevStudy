#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    const int SIZE = 5;
    int *ptr = new int[SIZE]{10,20,30,40,50};

    // for (int *end=ptr+SIZE; ptr<end; ptr++){
    //     cout << *ptr << endl;
    // }

    for (int *bgn = ptr, *end=ptr+SIZE; bgn<end; bgn++){
        cout << *bgn << endl;
    }

    delete[] ptr;

    return 0;
}
