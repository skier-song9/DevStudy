#include <iostream>
#include <set>
using namespace std;
int main(int argc, char const *argv[])
{
    set<int> numset;
    for (int i{};i<10;i++){
        int temp;
        cin >> temp;
        numset.insert((temp%42));
    }
    cout << numset.size() << "\n";
    return 0;
}
