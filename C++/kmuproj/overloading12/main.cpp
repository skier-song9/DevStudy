#include <iostream>
using namespace std;

int square(int i);
double square(double i);

int main(int argc, char const *argv[])
{
    cout << square(10) << endl;
    cout << square(2.0) << endl;
    return 0;
}
int square(int i){
    return i*i;
}
double square(double i){
    return i*i;
}