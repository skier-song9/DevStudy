#include <iostream>

void multiply(int n,int size,int arr[]);

using namespace std;

int main(int argc , char *argv []){
    const int SIZE = 9;
    int arr[SIZE]{};

    int n = 7;
    multiply(n,SIZE,arr); // Call By Reference
    for (int i = 1; i <= SIZE; i++)
    {
        cout << n << " X " << i << " = " << arr[i-1] << "\n";
    }
    cout << "\n";

    n=3;
    multiply(n,SIZE,arr);
    for (int i = 1; i <= SIZE; i++)
    {
        cout << n << " X " << i << " = " << arr[i-1] << "\n";
    }
    return 0;
}

void multiply(int n,int size,int arr[]){
    // using for
    // 곱셈결과를 배열에 저장
    for (int k = 0; k < size; k++)
    {
        arr[k] = n * (k + 1);
    }         
}