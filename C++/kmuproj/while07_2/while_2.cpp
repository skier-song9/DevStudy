#include <iostream>

void multiply(int num);

using namespace std;

int main(int argc, char const *argv[])
{
    int n = 2;
    while (n<10)
    {
        multiply(n);
        cout << endl;
        n++;
    }
    return 0;
}

void multiply(int num){
    int i=1;
    while (i<10)
    {
        cout << num << " X " << i << " = " << num*i << endl;
        i++;
    }
}