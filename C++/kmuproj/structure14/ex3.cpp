#include <iostream>
#pragma pack(push,1)
using namespace std;

struct Foo{
    int num;
    char tag;
};

int main(int argc, char const *argv[])
{
    
    Foo foo{10,'a'};
    cout << "sizeof(foo) = " << sizeof(foo) << endl; // 8

    return 0;
}

#pragma pack(pop)