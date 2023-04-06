#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    unsigned int a = 4294967295;
    unsigned long long b = 10000000000ull;

    cout << "a : " << a << endl;
    cout << "b : " << b << endl;

    unsigned long long result = a % b / (b/10) ;

    cout << result << endl;

    return 0;
}