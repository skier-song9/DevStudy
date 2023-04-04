#include <iostream>
void addVector(int cnt,int arr[],int sum);
using namespace std;
int main()
{
    int cntTest = 0;
    cin >> cntTest;
    for (; cntTest > 0; cntTest--)
    {
        int cnt = 0;
        int sum = 0;
        cin >> cnt;
        int arr[cnt]{};
        for (int i = 0; i < cnt; i++)
        {
            int num = 0;
            cin >> num;
            arr[i] = num;
        }
        addVector(cnt,arr,sum);
    }   
    return 0;
}
void addVector(int cnt,int arr[],int sum)
{
    for (int i = 0; i < cnt; i++)
    {
        sum += arr[i];
    }
    cout << sum << endl;
}