#include <iostream>
using namespace std;

class A {
    public:
    A(int x) {
        cout << "A의 생성자 함수 호출!" << endl;
    }
};

struct B{
    int x;
    B(int x) : x{x} {
        cout << "구조체 B의 생성자 호출!" << endl;
    }
};

int main(int argc, char const *argv[])
{
    char ch{'a'};
    string str['abc'];

    cout << ch << ", " << str << endl;
    return 0;
}
