#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int i = 0;
    // while (i++<5)
    // while (++i<5)
    while(i<5)
    {
        cout << "정수 : " << i << endl;
        i++;//이게 기본이다. while문의 조건식에 증감연산자를 사용할 필요가 없다.
    }
    
    return 0;
}
