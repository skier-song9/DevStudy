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
    // t=1;
    while (t--)
    {
        unsigned int n;
        cin >> n;
        // n=4294967295;
        // cout << "log10값:" << log10(n)+1 << endl;
        if (n / 10 < 1){
            cout << n << endl;
            continue;
        }
        
        unsigned long long result;
        unsigned int temp;
        do { 
            result = n % 10 == 0 ? 1 : n % 10;
            for (int i = 2; i<=log10(n)+1; i++){
                // cout << "i : " << i << ", n =" <<n<<", i="<<i<<endl;
                temp = (unsigned int)(n % (unsigned long long)(pow(10,(unsigned long long)i)) / (unsigned long long)pow(10,i-1));
                result *= temp == 0 ? 1 : temp;
            }
            n = result;
        }while (result / 10 > 0);
        cout << result << endl;
    }////////while

    end = clock();
    result = (double)(end - start);
    cout << "result : " << result << " microseconds" << endl;
    return 0;
}