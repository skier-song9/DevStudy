/*************************************************************************
* *
* Problem: 각 숫자의 일의 자리를 구해서 곱한 후, 다시 그 결과의 일의 자리를 구해서
            또 일의 자리끼리 곱한다. 
* *
*************************************************************************/
/*************************************************************************
* *
* 국민대학교 경영대학 경영정보학부 3학년 *
* 20190385 송규헌 *
* *
*************************************************************************/
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

        int init;
        int repeat;
        cin >> init;
        
        for (int i = 0; i < n-1; i++)
        {
            init = init % 10;            
            cin >> repeat;

            if ((int)pow(10,(int)log10(repeat)) != 1){
                repeat = repeat % 10;    
            }

            init = init*repeat;
        }////////for
        cout << init % 10 << "\n";
    }////////while
    return 0;
}