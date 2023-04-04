#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    char ch = 'A';
    cout << ch << endl;
    cout << sizeof(ch) << endl; // 1

    char *p = &ch;
    cout << *p << endl;
    cout << sizeof(p) << endl; 
    // 8 >> 포인터 변수 p는 64bit머신에서 8byte를 차지한다.
    cout << sizeof(*p) << endl; 
    // 1 >> *p는 ch를 의미하기 때문에 char형으로 1byte를 차지한다.

    // (void *)는 메모리 주소를 정확하게 보기 위해 포인터를 void형으로 캐스팅(변환)한다.
    cout << (void *)&p << endl;
    cout << (void *)p << endl;
    cout << (void *)&ch << endl;

    ch = 'B';
    cout << ch << endl;
    cout << *p << endl;

    *p = 'C';
    cout << ch << endl;
    cout << *p << endl;

    return 0;
}
