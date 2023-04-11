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
        int a,b,c,d;
        cin >> a >> b >> c >> d;

        cout << a << " " << b << " " << c << " " << d << endl;

        if (c < a){
            int tc=c; 
            int td=d;
            d=b;
            c=a;
            a=tc;
            b=td;
        }
        cout << a << " " << b << " " << c << " " << d << endl;
 
        if (b < c)
            cout << 0 << " " << (b-a)+(d-c) << endl;
        else if(c > a && c < b && d > b)
            cout << b-c << " " << d-a << endl;
        else
            cout << d-c << " " << b-a << endl;
        
    }////////while

    end = clock();
    result = (double)(end - start);
    cout << "result : " << result << " microseconds" << endl;
    return 0;
}