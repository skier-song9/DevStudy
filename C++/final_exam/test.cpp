#include <iostream>
#include <sstream>
#include <string>
#include <list>
using namespace std;
int main(int argc, char const *argv[])
{
    stringstream ss;
    string str;
    getline(cin,str);
    list<int> li;
    ss << str;
    while(true){
        string temp{"-1"};
        ss >> temp ;
        try
        {
            cout << "temp: " << temp << endl;
            if(stoi(temp)>0) {
               li.push_back(stoi(temp)); 
            }
            else {
                cout << "end" << endl;
                break;
            }
        }
        catch(const std::exception& e)
        {}
        
    }
    // getline(ss,str," ");

    cout << str << endl;
    int k;
    cin >> k;
    cout << k << endl;

    return 0;
}
