#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    const char *p = "Hello";
    cout << p << endl;

    // const char *p1 = &"hello";
    const char(*p3)[6] = &"Hello";

    cout << *p3 << endl; // >> 

    return 0;
}
