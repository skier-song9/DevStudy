#include <iostream>

void multiply(int num);

using namespace std;

int main(int argc, char const *argv[])
{
    for (int n=2; n<10; n++)
    {
        multiply(n);
        cout << endl;
    }
    return 0;
}

void multiply(int num){
    for (int i = 1; i < 10; i++)
    {
        cout << num << " X " << i << " = " << num*i << endl;
    }
}