#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        cout << str << endl;
        int tf{1};
        for (int i{0}; i < (int)(str.length()); i++){    
            if('a'<=str[i] && str[i]<='z' ||
                'A'<=str[i] && str[i]<='Z' ||
                str[i]=='_'){
                continue;
            }
            else if(i!=0 && '0'<=str[i] && str[i]<='9'){
                continue;
            }
            else{
                tf=0;
                break;
            }
        }
        cout << tf << endl;
    }
    return 0;
}
