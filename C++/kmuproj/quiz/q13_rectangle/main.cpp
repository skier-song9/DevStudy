#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
void cal(int arr[],int a,int b,int c,int d);
int main()
{
    clock_t start, end;
    double result;
    start = clock();

    int t;
    cin >> t;
    while (t--)
    {
        int a,b,c,d,e,f,g,h;
        int width = 0;
        int length = 0;
        cin >> a >> e >> b >> f >> c >> g >> d >> h;

        cout << a << b << c << d << e << f << g << h << endl;

        int p[2]{};
        int q[2]{};
        cal(p,a,b,c,d);
        cal(q,e,f,g,h);

        cout << p[0] << ", " << q[0] << endl;
        cout << p[1] << ", " << q[1] << endl;

        if (p[0]==0 || q[0]==0)
        {
            width = ((b-a)*(f-e))+((d-c)*(h-g));
            length = (2*(b-a)+2*(f-e))+(2*(d-c)+2*(h-g));
        }
        else
        {
            width = ((b-a)*(f-e))+((d-c)*(h-g))-(p[0]*q[0]);
            length = 2*p[1] + 2*q[1];
        }
        
        cout << width << " " << length << endl;
    }////////while

    end = clock();
    result = (double)(end - start);
    cout << "result : " << result << " microseconds" << endl;
    return 0;
}

void cal(int arr[],int a,int b,int c,int d){
    if (c < a){
        int tc=c; 
        int td=d;
        d=b;
        c=a;
        a=tc;
        b=td;
    }
    if (b < c){
        arr[1] = (b-a)+(d-c);
    }
    else if(c > a && c < b && d > b){
        arr[0] = b-c;
        arr[1] = d-a;
    }
    else{
        arr[0] = d-c;
        arr[1] = b-a;
    }
}