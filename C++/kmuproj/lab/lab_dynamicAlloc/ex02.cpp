#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int i = 10;
    int *ptr = &i; 

    cout << i << endl; 
    cout << *ptr << endl;
    cout << ptr << endl;
    cout << &ptr << endl;

    // delete ptr; //[x]
    /* 다음과 같은 runtime 에러가 발생한다.
    munmap_chunk(): invalid pointer
    Aborted (core dumped)
    */
    
    return 0;
}
