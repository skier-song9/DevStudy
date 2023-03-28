#include <iostream>

void find(int arr[], int size, int target);
int find_index(int arr[],int size, int target);

using namespace std;

int main(int argc, char const *argv[])
{
    const int SIZE = 6;

    int arr[SIZE] = {11,22,33,44,55,33};
    int target = 33;

    // for (int i = 0; i< SIZE; i++){
    //     if(arr[i]==target){
    //         std::cout << "found = " << i << "\n";
    //     }
    // }
    find(arr,SIZE,target);

    //📢 sizeof() : 데이터 타입 또는 객체의 크기를 byte단위로 반환하는 연산자
    //  

    cout << sizeof(arr) << "\n"; //24(bytes)
    cout << "length of array : " << sizeof(arr)/sizeof(arr[0]) << "\n"; 

    cout << "find_index : " << find_index(arr,SIZE,target) << "\n";

    return 0;
}

void find(int arr[],int size, int target){
    cout << sizeof(arr) << "\n"; // this is size of pointer >> pointer is 8bytes in 64bit machine. 4bytes in 32bit machine
    //⚠️여기서 sizeof(arr)이 '포인터 상수'의 크기를 반환한 이유: find()함수에서 매개변수 arr배열은 크기가 정해져있지 않음. 따라서 arr을 포인터로 판단하고 포인터의 크기를 반환한 것이다.
    for (int i = 0; i< size; i++){
        if(arr[i]==target){
            std::cout << "found = " << i << "\n";
            break;
        }
    }
}

int find_index(int arr[],int size,int target){
    int ret = -1;
    for (int i = 0; i < size; i++)
    {
        if(target==arr[i]){
            return i;
            //continue, break 사용 시,
            //ret = i;
            //break; 를 추가한다.

            //또는
            /*
            if (target != arr[i]){
                continue;
            }
            ret = i;
            */
        }
    }
    return ret;
}
