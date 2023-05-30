#include <iostream>

using namespace std;

template <typename T>
void increase(T& v) { v+=1; }

template <>
void increase(int *& v) { v+=2; }

int main(int argc, char const *argv[])
{
    int i=1;
    cout << "i= " << i << endl;
    increase(i);
    cout << "i= " << i << endl;

    int *p = &i;
    cout << "p= " << p << endl;
    increase(p);
    cout << "p= " << p << endl;
    return 0;
}
