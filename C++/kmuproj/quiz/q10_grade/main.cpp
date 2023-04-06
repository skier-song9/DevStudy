#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
void grade(int score, int arr[]);
int main()
{
    clock_t start, end;
    double result;
    start = clock();

    int t;
    cin >> t;
    while (t--)
    {
        int n,score;
        cin >> n;
        int arr[5]{};
        for (int i = 0; i<n; i++){
            cin >> score;
            grade(score,arr);
        }
        for (int i=0; i<sizeof(arr)/sizeof(arr[0]);i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }////////while

    end = clock();
    result = (double)(end - start);
    cout << "result : " << result << " microseconds" << endl;
    return 0;
}
void grade(int score, int arr[]){
    switch (score/10)
    {
    case 10:
    case 9: arr[0]+=1; break;
    case 8: arr[1]+=1; break;
    case 7: arr[2]+=1; break;
    case 6: arr[3]+=1; break;
    default: arr[4]+=1;
    }
}