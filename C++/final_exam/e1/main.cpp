#include <iostream>
#include <list>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;    
    while(t--){
        list<int> li;
        int tt;
        cin >> tt;
        for(int i{}; i<tt; i++){
            int temp;
            cin >> temp;
            li.push_back(temp);
        }
        int k;
        cin >> k;

        list<int> sum_list;
        list<int>::iterator it;
        int size;
        size = li.size() - (k-1);
        for(int i{};i<size;i++){
            it = li.begin();
            int sum{};
            for(int j{};j<k;j++){
                sum += (*it);
                it++;
            }
            sum_list.push_back((sum/k));
            li.pop_front();
        }

        cout << sum_list.size() << " ";
        for(const auto& e:sum_list){
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}
