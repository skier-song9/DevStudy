#include <iostream>
#include <cstdlib>
#include <time.h>
int funcA(int n,int i,int j);
using namespace std;
int main()
{
    clock_t start, end;
    double result;
    start = clock();

    int t;
    cin >> t;
    // t=1;
    while (t--)
    {
        int n ; 
        int a ; 
        int b ; 
        cin >> n; 
        cin >> a ;
        cin >> b;
        
        int nsqrt = n*n;
        int idx = 0;
        int temp;
        int i=0,j=0;
        // printf("n=%d,a=%d,b=%d" ,n,a,b); cout << endl;
        for (int cnt_for=0;cnt_for<n;cnt_for++){
            i++;
            for (j++; j <= n-cnt_for; j++)
            {
                temp=funcA(n,i,j);
                if (idx >= a-1 && idx <= b-1)
                    cout << temp << " ";
                idx++;
            }
            j--;
            for (i++; i <= n-cnt_for; i++)
            {
                temp=funcA(n,i,j);
                if (idx >= a-1 && idx <= b-1)
                    cout << temp << " ";
                idx++;
            }
            i--;
            for (j--; j >= 1+cnt_for; j--)
            {
                temp=funcA(n,i,j);
                if (idx >= a-1 && idx <= b-1)
                    cout << temp << " ";
                idx++;
            }
            j++;
            for (i--; i >= 2+cnt_for; i--)
            {
                temp=funcA(n,i,j);
                if (idx >= a-1 && idx <= b-1)
                    cout << temp << " ";
                idx++;
            }
        }///////for
        cout << endl;
    }////////while

    cout << endl;
    end = clock();
    result = (double)(end - start);
    cout << "result : " << result << " microseconds" << endl;
    return 0;
}
int funcA(int n,int i,int j){
    return (i-1)*n + j;
}