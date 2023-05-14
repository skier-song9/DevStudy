#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    // t=1;
    while(t--){
        string num;
        cin >> num;
        // num = "100000001";
        string sum{};
        int len{};
        
        while((int)(num.length()) > 1){ 
            len = (int)(num.length());
            sum = num[len-1] + sum;
            if (len >= 3){
                int x{stoi(num.substr(len-3,2))};
                int y{stoi(num.substr(len-1,1))};
                int sub = x-y;
                string add{};
                if(len==3){
                    num = to_string(sub);
                    continue;
                }
                if(sub>=10){
                    add = to_string(sub);
                    num = num.substr(0,len-3)+add;
                }
                else if (sub<10 && sub>=0){
                    add = "0" + to_string(sub);
                    num = num.substr(0,len-3)+add;
                }
                else {
                    add = to_string(100+sub);
                    string origin{num.substr(0,len-3)};
                    int i{len-3-1};
                    int temp{i};
                    while(origin[i]=='0'){
                        origin[i] = '9';
                        i--;
                        temp = i;
                    }
                    origin.replace(temp,1,to_string(stoi(origin.substr(temp,1))-1));
                    if(temp==0){
                        origin = origin.substr(1,((int)origin.length())-1);
                    }
                    num = origin+add;
                }
            }
            else if (len ==2) { 
                num = to_string(stoi(num.substr(0,1)) - stoi(num.substr(1,1)));
                break;
            }
            else { 
                break;
            }
        }
        if(num=="0"){
            cout << sum << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
    return 0;
}
