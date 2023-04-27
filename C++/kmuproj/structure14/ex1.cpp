#include <iostream>
using namespace std;

//[Structure]
struct Foo {
    //[멤버]
    int num;
    string data;
};

int main(int argc, char const *argv[]){
    
    Foo foo{}; // default 값으로 structure의 멤버들을 초기화
    //Foo foo = {}; //>> 할당과 같다. 초기화X
    cout << "foo.num = " << foo.num << endl;
    cout << "foo.data = " << foo.data << endl;

    Foo foo2{10,"hello"}; //특정 값으로 멤버 초기화
    // foo.num=10;
    // foo.data="hello";
    cout << "foo2.num = " << foo2.num << endl;
    cout << "foo2.data = " << foo2.data << endl;

    return 0;
}
