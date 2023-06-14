#include <iostream>
#include <list>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--){
        int num_student;
        cin >> num_student;
        
        list<int> scores;
        for(int i{}; i< num_student; i++){
            int temp;
            cin >> temp;
            scores.push_back(temp);
        }

        map<int,int> smap;
        for(const auto& e : scores){
            map<int,int>::iterator it = smap.find(e);
            if(it == smap.end()){
                smap.insert(pair<int,int>(e,1));
            }
            else{
                it->second ++;
            }
        }

        //print
        for(const auto& e:smap){
            cout << e.first << " " << e.second << " ";
        }

        cout << "\n";
    }
    return 0;
}
