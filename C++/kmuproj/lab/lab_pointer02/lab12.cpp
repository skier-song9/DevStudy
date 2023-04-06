#include <iostream>
void replace(char *pch, char new_ch);
void rp(char ch, char v);
using namespace std;
int main(int argc, char const *argv[])
{
    char ch = 'A';
    cout << "ch before : " << ch << endl;

    //함수의 호출은 아래와 같다.
    // ?1 : ch ('A')
    // ?2 : 바꾸어야할 문자 ('B')
    replace(&ch, 'B');
    cout << "ch after : " << ch << endl;

    rp(ch, 'C');
    cout << "ch after rp : " << ch << endl;

    return 0;
}
void replace(char *pch, char new_ch)
{
    //함수가 호출되는 순간 char *pch=&ch; 즉, 포인터변수 pch가 메모리에 생성되는 것이다.
    *pch = new_ch;
}
void rp(char ch, char v){
    ch = v; // main함수의 ch는 바뀌지 않는다. 왜? 여기서의 ch는 rp함수 내부에서 새롭게 메모리에 할당된 '지역변수'이다.
}
