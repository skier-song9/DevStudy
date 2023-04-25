#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int ctn;
    cin >> ctn;
    int arr[1001]{};
    for(int i=0;i<ctn;i++){
        cin >> arr[i];
    }
    // 선택 정렬
    int i,j,min,index,temp;
    for(i=0;i<ctn;i++){
        min=1001;
        for(j=i;j<ctn;j++){
            if (min > arr[j]){
                min = arr[j];
                index=j;
            }
        }
        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }
    
    for(i=0; i<ctn; i++){
        cout << arr[i] << " " ;
    }

    return 0;
}
