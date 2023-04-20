#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n = 99;
    int *ptr = &n;
    void *vptr = &n;

    cout << "&n = " << &n << endl; //0x9aea3ffd8c
    cout << "ptr = " << ptr << endl; //0x9aea3ffd8c
    cout << "vptr = " << vptr << endl; //0x9aea3ffd8c

    cout << "n = " << n << endl; //99
    cout << "*ptr = " << *ptr << endl; //99
    // cout << "*vptr = " << *vptr << endl; //[x] void pointer를 운용(값에 접근)하려면 몇 바이트를 읽어야 하는지 알려줘야 한다.
    cout << "*vptr = " << *((int *)vptr) << endl; //99

    return 0;
}
