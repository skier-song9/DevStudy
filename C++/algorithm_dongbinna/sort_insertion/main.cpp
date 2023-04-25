#include <iostream>

int main(void){
	int arr[10] = {5, 3, 9, 8, 1, 10, 2, 4, 6, 7};
	int i,j,temp; 
	int n = sizeof(arr)/sizeof(arr[0]);
	for (i=1; i<n; i++){
		for(j=i; j>=0; j--){		
			if(arr[j]<arr[j-1]){ // j번째 숫자와 j-1번째를 비교하며 작은 값을 앞으로 보낸다.
				temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
			}
		}//inner for

        //while문으로 할 시,
        // j=i;
        // while(j>0 && arr[j-1] > arr[j]){
        //     temp = arr[j];
        //     arr[j] = arr[j-1];
        //     arr[j-1] = temp;
        //     j--;
        // }
	}
	
	//결과 출력
	for (i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}//main