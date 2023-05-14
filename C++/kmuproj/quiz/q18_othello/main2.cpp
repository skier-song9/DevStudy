#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    
    while(t--){
        int othello[10][10]={};
        int dir[8][2]{{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1}};
        // 1 = white, -1 = black, 0
        othello[4][4]=1;
        othello[4][5]=-1;
        othello[5][4]=-1;
        othello[5][5]=1;
        int ctn,r,c;
        cin >> ctn;
        for(int i{1};i<=ctn;i++){
            int color = i%2==0 ? 1 : -1 ;
            cin >> r >> c ;
            int R = r;
            int C = c;
            othello[r][c] = color;
            for(int j{0};j<8;j++){
                r=R;
                c=C;
                while (othello[r][c]!=0){
                    r += dir[j][0];
                    c += dir[j][1];
                    if(othello[r][c]==color){
                        while (true){
                            //cout << r <<' '<<c<<' '<<dir[j][1]<<endl;
                            r -= dir[j][0];
                            c -= dir[j][1];
                            if(othello[r][c]==color) {break;}
                            else {othello[r][c]=color;}
                        }
                        break;
                    }
                }
            }
        }
        int b{};
        int w{};
        for(int i{1};i<9;i++){
            for(int j{1};j<9;j++){
                switch (othello[i][j])
                {
                case 1:
                    w++;
                    break;
                case -1:
                    b++;
                    break;
                default:
                    break;
                }
            }
        }
        cout << b << " " << w << endl;
        for(int i{1};i<9;i++){
            for(int j{1};j<9;j++){
                switch (othello[i][j])
                {
                case 1:
                    cout << "O" ;
                    break;
                case -1:
                    cout << "X";
                    break;
                default:
                    cout << "+";
                    break;
                }
            }
            cout << endl;
        }

    }

    return 0;
}
