#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n = 0;
        cin >> n;

        int min;
        int max;
        int repeat;
        cin >> min;
        max = min;
        
        for (int i = 0; i < n-1; i++)
        {
            cin >> repeat;

            if (min > repeat){
                min = repeat;
            }
            if (max < repeat){
                max = repeat;
            }
        }

        cout << max << " " << min << "\n";
    }////////while
    return 0;
}