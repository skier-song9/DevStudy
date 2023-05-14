#include <iostream>
#include <sstream>
#include <random>
using namespace std;

void pp(char othello[8][8]){
    cout << othello[0][0] << endl;
    cout << othello[4][4] << endl;
    cout << othello[5][5] << endl;
}

int main()
{
    
    char othello[8][8]{};
    for (int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(othello[i][j]=='\0'){
                cout << '+' << " ";
            }
            else cout << othello[i][j];
            // cout << othello[i][j] == ''?'+':othello[i][j] ;
        }
        cout << endl;
    }
    othello[4][4] = '-';
    othello[5][5] = '*';

    pp(othello);
    return 0;
}