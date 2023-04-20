#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int arr[]{10,20,30,40,50};
    const int size = sizeof(arr)/sizeof(arr[0]);

    // for(int i=0; i<size; i++)
    // {
    //     cout << "arr[" << i << "] = " << arr[i] << "  ";
    // }
    // cout << endl;

    // int *ptr = arr;
    // for (int i = 0; i < size; i++){
    //     cout << ptr[i] << "  ";
    // }
    // cout << endl;

    // for(int i=0; i<size; i++)
    // {
    //     cout << *(ptr+i) << "  ";
    // }
    // cout << endl;

    void *ptr = arr;
    for (int i=0; i<size; i++){
        cout << ((int *)ptr)[i] << "  ";
    }
    cout << endl;

    return 0;
}
