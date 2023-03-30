#include <iostream>
#include <cstdlib>
int add(int n,int total, int addnum);
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n = 0;
        cin >> n;

        int total=0;
        int addnum=0;
        
        // for (int i = 0; i < n-1; i++)
        // {
        //     cin >> add;
        //     total += add;
        // }
        total = add(n,total,addnum);

        cout << total << "\n";
    }
    return 0;
}

int add(int n,int total, int addnum)
{
    for (int i = 0; i < n; i++)
    {
        cin >> addnum;
        if (addnum%2==0){
            total += addnum;
        }
    }
    return total;
}