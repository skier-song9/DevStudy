#include <iostream>
using namespace std;

int f3(int a,int b,int &sum,int &diff);

int main(int argc, char const *argv[])
{
    int i=1,j=2,k=10,l=11;

    f3(i,j,k,l);

    cout << "k = " << k << endl;
    cout << "l = " << l << endl;

    return 0;
}
int f3(int a,int b,int &sum,int &diff){
    sum = a+b;
    diff = a-b;
    return sum;
}