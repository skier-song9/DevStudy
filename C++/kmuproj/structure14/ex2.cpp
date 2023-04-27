#include <iostream>
using namespace std;

struct Foo {
    int num;
    string data;
};

int main(int argc, char const *argv[])
{
    
    Foo foo{10,"hello"};

    int *ptr {(int *)&foo}; //또는 int *ptr {&foo.num};

    cout << "&foo = " << &foo << endl; //0x8cc69ffa10
    cout << "&foo.num = " << &foo.num << endl; //0x8cc69ffa10
    cout << "&foo.data = " << &foo.data << endl; //0x8cc69ffa18

    cout << "ptr = " << ptr << endl;
    cout << "*ptr = " << *ptr << endl;

    return 0;
}
