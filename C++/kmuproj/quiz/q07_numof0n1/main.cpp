#include <iostream>
#include <cstdlib>
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
        int n = 0;
        cin >> n;
        int num0=0;
        int num1=0;
        do{
            if (n & 1)
                num1++;
            else
                num0++;
            n = n >> 1;
        } while (n>0);
        
        cout << num0 << " " << num1 << endl;
    }////////while

    end = clock();
    result = (double)(end - start);
    cout << "result : " << result << " microseconds" << endl;
    return 0;
}