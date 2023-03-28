#include <iostream>
#include <cstdlib>
using namespace std;
#define N 3
int main()
{
    int v[N];

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < N; i++)
    {
        cout << v[i] + 10 << " ";
    }
    cout << endl;   
    
    return 0;
}

//📢 실행파일 실행 시, 
//      실행파일명 < in.txt > out.txt