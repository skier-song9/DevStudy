#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int i{10};
    cout << &i << endl;

    // &(i++); //[x] >> ref연산에 i의 임시값인 10을 사용하기 때문에 rValue임. >> error
    cout << &(++i) << endl;

    return 0;
}
