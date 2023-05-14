#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string num, sum{};
        cin >> num;

        while(num.size() > 2){
            cout << num << endl;

            char last{num[num.size()-1]};
            num.pop_back();
            // cout << last << endl;
            sum = last + sum;

            if(num[num.size()-1] < last){
                for(int i=num.size()-1; i>0; i--){
                    num[i] += 10;
                    cout << "num[i]+=10 : " << num << endl;
                    num[i-1]--;
                    cout << "num[i-1]-- : " << num << endl;
                    if(num[i-1]>='0'){
                        break;
                    }
                }
            }
            num[num.size()-1] -= last - '0';
            while(num[0]=='0') {
                num.erase(0,1);
            }
        }
        cout << num << endl;
        sum = num[num.size()-1] + sum;
        if (stoi(num) % 11 == 0){
            cout << sum << endl;
        }
        else {
            cout << 0 << endl;
        }
    }
    return 0;
}