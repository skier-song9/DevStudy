#include <iostream>

using namespace std;

int main(int argc , char *argv []){
    const int SIZE = 9;
    int n = 7;
    int arr[SIZE]{};
    // using for
    // 곱셈결과를 배열에 저장
    for (int k = 0; k < SIZE; k++)
    {
        arr[k] = n * (k + 1);
    }
    
    // using for
    // 배열에 저장된 값을 출력
    for (int i = 1; i <= SIZE; i++)
    {
        cout << n << " X " << i << " = " << arr[i-1] << "\n";
    }    

    return 0;
}