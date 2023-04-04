#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    char ch='A';
    cout << ch << endl;
    cout << (void *)&ch << endl;

    char *p=&ch;
    cout << *p << endl;
    cout << (void *)p << endl;
    cout << (void *)&p << endl;    

    cout << endl;
    char **pp = &p;
    cout << **pp << endl; // A
    cout << *pp << endl; // p의 메모리 주소
    cout << (void *)pp << endl; // p의 메모리 주소
    cout << (void *)*pp << endl; // ch의 메모리 주소
    // cout << (void *)**pp << endl; //[x]
    cout << (void *)&pp << endl; // pp의 메모리 주소

    **pp = 'B';
    cout << **pp << endl; // B
    cout << *p << endl; // B
    cout << ch << endl; // B

    return 0;
}
