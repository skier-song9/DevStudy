#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    char arr[] = "Hello";
    cout << arr << endl;
    cout << sizeof(arr) << endl; // 6bytes인 이유: null terminator(\0)이 포함되어 있기 때문.

    char *p = arr;
    cout << p << endl;

    cout << p+0 << endl; //Hello
    cout << p+1 << endl; //ello

    cout << *(p+0) << endl; //H
    cout << *(p+1) << endl; //e

    cout << (void *)(p + 1) << endl; //0x2aabdff6a3 >> arr[1]의 주소
    cout << (void *)&arr[1] << endl; //0x2aabdff6a3

    return 0;
}
