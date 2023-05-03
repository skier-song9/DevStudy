#include <iostream>
// #include <cstdlib>
using namespace std;

bool isLeap(int y);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int year,month,day;
        cin >> year >> month >> day;
        cout << year << " " << month << " " << day << endl;

        int y{1582};
        int date{5};
        while(y<year){
            if (isLeap(y)){
                date+=2;
            }
            else{
                date++;
            }
            y++;
        }

        int m{1};
        int md[12]{31,28,31,30,31,30,31,31,30,31,30,31};
        if(month>2 && isLeap(y)){
            md[1]=29;
        } 
        while(m<month){
               date+=md[(m-1)];
               m++;
        }

        date+=day;

        cout << (date-1)%7 << endl;
    }
    
    return 0;
}

bool isLeap(int y){
    //윤년일 때
    if(y%4==0 && y%100!=0 || y%4==0 && y%100==0 && y%400==0){
        return true;
    }
    else return false;
}