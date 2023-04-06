#include <iostream>
// void printArray(int arr[],int size);
void printArray(int *arr,const int size);
using namespace std;
int main(int argc, char const *argv[])
{
    const int size; //= 5;
    int arr[]{10,20,30,40,50};

    printArray(arr,size);

    return 0;
}
// void printArray(int arr[],int size){
//     for (int i = 0; i < size; i++)
//     {
//         cout << "arr[" << i << "] = " << arr[i] << endl;
//     }
//     cout << endl;
// }
void printArray(int *arr,const int size){
    size = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < size; i++)
    {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
    cout << endl;
}