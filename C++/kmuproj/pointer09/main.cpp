#include <iostream>
using namespace std;
int get_sum1(int a[],int n);
int get_sum2(int a[],int n);
int main(int argc, char const *argv[])
{
    int a[]{10,20,30,40,50};
    cout << get_sum1(a,sizeof(a)/sizeof(a[0])) << endl;
    cout << get_sum2(a,sizeof(a)/sizeof(a[0])) << endl;
    return 0;
}
int get_sum1(int a[],int n){
    int i;
    int sum=0;
    for(i=0;i<n;i++)
        sum+=a[i];
    return sum;
}
int get_sum2(int a[],int n){
    int i;
    int *p=a;
    int sum=0;
    for(i=0;i<n;i++)
        sum+= *p++;
    return sum;
}