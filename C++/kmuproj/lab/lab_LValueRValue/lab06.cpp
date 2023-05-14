#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int i{10};

    // int *ptr{&1000}; //[x] error: lvalue required as unary ‘&’ operand

    int *ptr{&i};

    int* &ref{ptr};

    cout << &ptr << endl;
    cout << &ref << endl;

    return 0;
}
