#include <iostream>
#include <cstdlib>
#include <math.h>
#include <time.h>
using namespace std;
int main()
{
    clock_t start, end;
    double result;
    start = clock();

    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;

        int n=1;
        int sum=0;
        while(true)
        {
            sum += 9*(int)pow(10,n-1)*n;
            if(k <= sum)
                break;
            n++;
        }
        // if (n == 0)
        // {
        //     cout << k << endl;
        //     continue;
        // }

        cout << "n:" << n << ", k:" << k << ", sum:" << sum << endl;
        sum = sum - 9*(int)pow(10,n-1)*(n);
        cout << "k: " << k << ", sum: " << sum << endl;
        div_t result = div(k - sum,n);
        cout << "result.quot : " << result.quot << ", result.rem: " << result.rem << endl;
        if (result.rem == 0)
        {
            cout << (result.quot - 1 + (int)pow(10,n-1))%10 << endl;
        }
        else
        {
            cout << (result.quot + (int)pow(10,n-1))/(int)pow(10,n-result.rem)%(int)pow(10,result.rem) << endl;
        }
        
    }////////while

    end = clock();
    result = (double)(end - start);
    cout << "result : " << result << " microseconds" << endl;
    return 0;
}