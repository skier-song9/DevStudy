#include <iostream>
using namespace std;
void quickSort(int *data, int start, int end);
int main(void){
    int data[] = {5,7,8,6,4,3};
    int number = sizeof(data)/sizeof(data[0]);

    quickSort(data,0,number-1);
    for (int i=0; i<number; i++){
        printf("%d ",data[i]);
    }

    return 0;
}
void quickSort(int *data, int start, int end){
    // start = 정렬하는 부분집합의 시작 원소
	// end = 정렬하는 부분집합의 끝 원소
    if(start>=end){// 정렬할 집합의 원소가 1개인 경우 바로 return
        return;
    }
    int key = start; //키(피봇 값)는 첫번째 원소
    int i = start + 1;
    int j = end;
    int temp;

    while(i<=j){ // 피벗이 최대값이 될 때까지 반복한다.
        while(data[i] <= data[key]) { //피벗보다 큰 값을 찾는다.
            i++;
        }
        while(data[j] >= data[key] && j > start) { //피벗보다 작은 값을 찾는다. 피벗이 최솟값이라면 key = j가 된다.
            j--;
        }
        if (i > j){ // i와 j가 엇갈렸다면 피벗이 집합 내에서 최대값 또는 최소값임.
            temp = data[j];
            data[j] = data[key];
            data[key] = temp;
        }
        else{ // 엇갈리지 않았다면 피벗이 집합 내에서 최소값이거나 아무것도 아님.
            //피벗이 최대값, 최소값이 아니라면 key < i < j
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }
    //스스로를 호출한다.
    quickSort(data,start,j-1);
    quickSort(data,j+1,end);
}