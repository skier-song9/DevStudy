#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    const int size = 5;
    int arr[size] = {1,2,3,4,5};

    cout<<"arr[0] = " << arr[0] << "\n";
    cout<<"arr[1] = " << arr[1] << "\n";
    cout<<"arr[2] = " << arr[2] << "\n";
    cout<<"arr[3] = " << arr[3] << "\n";
    cout<<"arr[4] = " << arr[4] << "\n";

    // cout<<"arr[5] = " << arr[5] << "\n";
    // >> 예외가 발생하지 않고, arr[5] = 326 출력 됨.
    // >> why? OS의 메모리가 남아 있는 경우, 컴파일러가 arr[5]를 자동으로 생성함. 남은 메모리가 없다면 예외 발생.

    arr[5] = 20;
    cout << arr[5] << "\n";
    arr[6] = 30;
    cout << arr[6] << "\n";

    return 0;
}
