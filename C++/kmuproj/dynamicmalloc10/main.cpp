#include <iostream>
using namespace std;
int main()
{
    int *pi=nullptr;

    pi = new int;
     
    *pi = 100;
    delete pi;

    int *q = new int;
    return 0;
}
