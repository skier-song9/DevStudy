/*************************************************************************
* *
* Problem: 배열을 사용하지 않고, 가위바위보 게임에서 승리한 사람의 수를 구하기
    위해서는 각 게임마다 가위, 바위, 보를 낸 사람의 수의 누적합을 구한 뒤,
    비기는 경우의 수는 0을 출력하고, 이외에는 (가위,바위),(바위,보),(가위,보)
    경우의 수별로 이기는 것의 수를 출력하면 된다.
    예를 들어, 1 1 2 2 2 1 1 1 은 가위 5, 바위3 으로 (가위,바위)의 경우에 해당
    하므로 바위가 이기는 경우이고, 바위의 누적합인 3을 출력하면 된다.
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

#define SCISSOR 1
#define ROCK 2
#define PAPER 3

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int scissor=0; 
        int rock=0; 
        int paper=0; 

        for (int k = 0; k < n; k++)
        {
            int person;
            cin >> person ;
            if (person == SCISSOR)
                scissor++;
            else if (person == ROCK)
                rock++;
            else
                paper++;
        }////////for

        if(rock>0 && scissor>0 && paper>0 ||
            rock>0 && scissor==0 && paper==0 ||
            scissor>0 && rock==0 && paper==0 ||
            paper>0 && rock==0 && scissor==0 
            )
        {
            cout << 0 << "\n";
        }
        else if (rock>0 && scissor>0)
        {
            cout << rock << "\n";
        }
        else if (rock>0 && paper>0)
        {
            cout << paper << "\n";
        }
        else if (scissor>0 && paper>0)
        {
            cout << scissor << "\n";
        }
        
    }////////while

    return 0;
}