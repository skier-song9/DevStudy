#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int i{10};
    //int *j{1000}; //[x]  error: invalid conversion from ‘int’ to ‘int*’ [-fpermissive]

    int *j{(int *)1000};

    cout << j << endl;
    cout << *j << endl; //Segmentation fault >> 1000번지 주소의 메모리에는 아무것도 할당되지 않음을 의미.
    

    return 0;
}
