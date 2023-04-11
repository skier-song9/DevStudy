#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int i{10};
    int *ptr = &i;

    cout << &i << endl; //0xc7a19ff9dc
    cout << ptr << endl; //0xc7a19ff9dc
    cout << *ptr << endl; //10

    cout << i << endl; //10
    cout << *ptr << endl; //10

    int *n = new int{90};
    cout << n << endl; //0x237d9c91710
    cout << *n << endl; //90

    return 0;
}
