#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    const int SIZE = 5;

    int arr[] = {10,20,30,40,50};

    cout << *(arr+2) << endl;

    // arr = arr+2; [x]  error: incompatible types in assignment of 'int*' to 'int [5]'
    // arr은 int[5]타입, arr+2는 int* 타입이므로 불가능하다.
    cout << *arr << endl;

    int *ptr = arr;
    ptr = arr+2;
    cout << *ptr << endl;

    for(int *ptr = arr, *end = arr + SIZE; ptr<end; ptr++){
        cout << *ptr << endl;
    }

    return 0;
}
