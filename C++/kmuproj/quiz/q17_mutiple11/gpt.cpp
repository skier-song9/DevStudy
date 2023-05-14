#include <iostream>
using namespace std;

void form(string &num);

int main(){
    int t; 
    cin>>t;
    string num, origin, sum{};
    for (int i=0 ; i<t ; i++){
        if (i!=0) cout<<"\n";
        cin>>num;
        origin = num;
        while (true){
            sum = num.back() + sum;
            if (num.size()<=2) {
                if (num[0]=='0') cout<<num[num.size()-1]<<"\n";
                else cout<<num<<"\n";
                break;
            }
            cout<<num<<"\n";
            form(num);
        }

        if (num[0]!=num[1]) cout<<"not ";
        cout<<"divisible by 11.\n";
    }
    return 0;
}
void form(string &num){
    char unit_digit = num[num.size()-1];
    num.pop_back();
    if (num[num.size()-1] < unit_digit){
        for (int i=num.size()-1 ; i>=1 ; i--){
            num[i] += 10;
            num[i-1]--;
            if (num[i-1]>='0') break;
        }
    }
    num[num.size()-1] -= unit_digit-'0';
    while (num[0]=='0') num.erase(0, 1);
}
