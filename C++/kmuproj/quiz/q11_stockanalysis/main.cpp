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
        int n;
        cin >> n;
        int prev, curr;
        int total = 0;
        cin >> prev;
        bool isHigh = false;
        bool isSame = false;
        for (int i = 1; i < n; i++){
            cin >> curr;
            if (curr > prev)
                isHigh = true;
            else if (curr == prev)
                isSame = true;
            else {
                if(isHigh)
                    total++;
                isHigh = false;
                isSame = false;
            }
            prev = curr;
        }
        cout << total << endl;
    }////////while

    end = clock();
    result = (double)(end - start);
    cout << "result : " << result << " microseconds" << endl;
    return 0;
}