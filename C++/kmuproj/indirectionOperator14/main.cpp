#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int i = 97;
    int *p;

    
    // p = 0x7604fff6b4; //[x] 메모리 주소를 직접 할당하는 것은 의미가 없다. 이렇게 하면 메모리 주소가 p에 할당되는 것이 아니라 16진수 숫자가 할당되는 것임.
    p = &i;

    int *q = &i;

    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    cout << "sizeof(p) is " << sizeof(p) << endl;
    cout << "sizeof(q) is " << sizeof(q) << endl;

    cout << "i = " << i << endl;;
    cout << "*p = " << *p << endl;
    cout << "*q = " << *q << endl;
    cout << "&i = " << &i << endl;

    char c = 'a';
    char *ptr;
    ptr = &c;

    return 0;
}
