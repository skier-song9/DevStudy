#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int *ptr = nullptr; //0x20a5ffe78
    cout << &ptr << endl;
    cout << ptr << endl;

    ptr = new int{9}; // >> ptr의 메모리 주소는 0x20a5ffe78고, ptr의 값은 new int의 메모리주소가 된다.
    cout << ptr << endl; //0x1aedaa61710
    cout << &ptr << endl; //0x20a5ffe78
    cout << *ptr << endl;

    cout << *(ptr+1) << endl; // 해당 주소에 값을 할당한 적이 없기 때문에 쌩뚱맞은 값이 나온다.

    delete ptr; 
    
    return 0;
}
