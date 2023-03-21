#include <iostream>
using namespace std;

// int main(int argc, char const *argv[])
// {
//     int arr[5];

// //📢 & : address operater
//     cout << &arr << "\n"; //0x124afffbd0
//     cout << &arr[0] << "\n"; //0x124afffbd0 >> arr과 arr[0]의 메모리는 동일. 
//         //🔔인덱스를 갖는 변수의 경우, 특정 인덱스의 메모리 주소는 "변수의 메모리주소+(인덱스번호*자료형크기)"이다.
//     cout << &arr[1] << "\n"; //0x124afffbd4 >> int가 4bytes이기 때문에 4늘어남

//     return 0;
// }

int main(int argc, char const *argv[])
{
    char arr[10];
    int i;

    for (i=0; i<10; i++){
        arr[i] = 'a';
    }

    for (i=0; i<10; i++){
        cout << arr[i] << endl;
    }

    int arr_[3]{1,2,3};
    for (i=0; i<3; i++){
        cout << arr_[i] << endl;
    }

    return 0;
}

