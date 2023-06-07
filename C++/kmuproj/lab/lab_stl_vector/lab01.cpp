#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
    vector<int> v1{3};
    cout << "v1.size() = " << v1.size() << endl;
    cout << "v1.max_size() = " << v1.max_size() << endl;
    cout << "v1.empty() = " << v1.empty() << endl;
    cout << "v1.capacity() = " << v1.capacity() << endl;
    cout << "v[0] = " << v1[0] << endl;
    return 0;
}
