#include <iostream>
#include <cstdlib>
void printstar(int i,int k,int m);
void printLine(int k,int m);
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        int m = (int)(k/2);
        for (int i = 0; i < k; i++){
            if (i == m){
                printLine(k,m);
            }
            else{
                printstar(i,k,m);
            }
            cout << endl;
        }
    }////////while
    return 0;
}
void printstar(int i,int k,int m){
    for (int j = 0; j < k; j++){
        if (j == m){
            cout << "I";
        }
        else if(j==k-1-i){
            cout << "*";
        }
        else{
            cout << ".";
        }
    }
}
void printLine(int k,int m){
    for (int i = 0; i< k; i++){
        if (i == m){
            cout << "O";
        }
        else{
            cout << "+";
        }        
    }
}