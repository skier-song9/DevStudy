#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int k;
        cin >> k;

        long long digit = 1;
        long long count = 9;
        long long start = 1;

        while (k > count * digit) {
            k -= count * digit;
            digit++;
            count *= 10;
            start *= 10;
        }

        long long num = start + (k - 1) / digit;

        long long index = (k - 1) % digit;

        long long result = (long long)(num / (int)pow(10, digit - 1 - index)) % 10;

        cout << result << endl;
    }
    return 0;
}