#include <iostream>
#define BLACK 'X'
#define WHITE 'O'

using namespace std;
void init(char othello[8][8]);
void check(char othello[8][8], int r, int c, int count, int max);
void getResult(char othello[8][8],const int max);



int main()
{
    int t;
    cin >> t;
    // t = 1;
    const int max{8};
    while(t--){
        char othello[8][8]{};
        init(othello);
        int ctn,r,c;
        cin >> ctn;
        for(int count{1};count<=ctn;count++){
            cin >> r >> c;
            check(othello,r-1,c-1,count,max);
        }
        getResult(othello,max);
    }

    return 0;
}

void init(char othello[8][8]){
    othello[3][3] = WHITE;
    othello[4][3] = BLACK;
    othello[3][4] = BLACK;
    othello[4][4] = WHITE;
}
void check(char othello[8][8], int r, int c, int count, int max){
    //othello : 오셀로판
    //r,c : r = row, c = column
    //count : 둔 횟수. 홀수=BLACK, 짝수=WHITE
    char color = count%2==0 ? WHITE : BLACK; //color = 돌의 색
    //돌 두기
    othello[r][c] = color;
    max--;
    //북
    int tr{r};
    int tc{};
    while (true){
        tr--;
        if(tr<0 || othello[tr][c] == color || othello[tr][c] == '\0') break;
    }
    if(tr>=0 && othello[tr][c] == color){
        for(int i{r-1};i>tr;i--){
            othello[i][c] = color;
        }
    }
    //북동
    tr = r;
    tc = c;
    while (true){
        tr--;
        tc++;
        if(tr<0 || tc>max || 
        othello[tr][tc] == color || othello[tr][tc] == '\0') break;
    }
    if(tr>=0 && tc<=max && othello[tr][tc] == color){
        for(int i{r-1};i>tr;i--){
            for(int j{c+1};j<tc;j++){
                othello[i][j] = color;
            }
        }
    }
    //동
    tc = c;
    while (true){
        tc++;
        if(tc>max || othello[r][tc] == color || othello[r][tc] == '\0') break;
    }
    if(tc<=max && othello[r][tc] == color){
        for(int i{c+1};i>tc;i--){
            othello[r][i] = color;
        }
    }
    //남동
    tr = r;
    tc = c;
    while (true){
        tr++;
        tc++;
        if(tc>max || tr>max || 
        othello[tr][tc] == color || othello[tr][tc] == '\0') break;
    }
    if(tr<=max && tc<=max && othello[tr][tc] == color){
        for(int i{r+1};i<tr;i++){
            for(int j{c+1};j<tc;j++){
                othello[i][j] = color;
            }
        }
    }
    //남
    tr = r;
    while (true){
        tr++;
        if(tr>max || othello[tr][c] == color || othello[tr][c] == '\0') break;
    }
    if(tr<=max && othello[tr][c] == color){
        for(int i{r+1};i<tr;i++){
            othello[i][c] = color;
        }
    }
    //남서
    tr = r;
    tc = c;
    while (true){
        tr++;
        tc--;
        if(tc<0 || tr>max || 
        othello[tr][tc] == color || othello[tr][tc] == '\0') break;
    }
    if(tr<=max && tc>=0 && othello[tr][tc] == color){
        for(int i{r+1};i<tr;i++){
            for(int j{c-1};j>tc;j--){
                othello[i][j] = color;
            }
        }
    }
    //서
    tc = c;
    while (true){
        tc--;
        if(tc<0 || othello[r][tc] == color || othello[r][tc] == '\0') break;
    }
    if(tc>=0 && othello[r][tc] == color){
        for(int i{c-1};i>tc;i--){
            othello[r][i] = color;
        }
    }
    //북서
    tr = r;
    tc = c;
    while (true){
        tr--;
        tc--;
        if(tc<0 || tr<0 || 
        othello[tr][tc] == color || othello[tr][tc] == '\0') break;
    }
    if(tr>=0 && tc>=0 && othello[tr][tc] == color){
        for(int i{r-1};i>tr;i--){
            for(int j{c-1};j>tc;j--){
                othello[i][j] = color;
            }
        }
    }
}

void getResult(char othello[8][8],const int max){
    int b{0};
    int w{0};
    for(int i{0};i<max;i++){
        for(int j{0};j<max;j++){
            switch (othello[i][j])
            {
            case BLACK:
                b++;
                break;
            case WHITE:
                w++;
                break;
            default:
                break;
            } 
        }
    }
    cout << b << " " << w << endl;
    for(int i{0};i<max;i++){
        for(int j{0};j<max;j++){
            if (othello[i][j] == '\0') cout << '+';
            else cout << othello[i][j];
        }
        cout << endl;
    }
}