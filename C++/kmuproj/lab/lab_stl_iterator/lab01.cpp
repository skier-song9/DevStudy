#include <iostream>
#include <vector>
using namespace std;

template <class T>
void print_vector(vector<T> v, string s=""){
    cout << s << "(" << v.size() << ") ";
    for (int i{};i<v.size();i++) cout << v[i] << " ";
    cout << endl;
}

int main(int argc, char const *argv[])
{
    vector<int> v1(3,5);
    print_vector(v1,"v1= ");
    // vector<int>::iterator it = v1.begin();
    auto it{v1.begin()};

    // for(;it!=v1.end();it++) *it = 10;
    for(auto& e:v1) e = 20;

    print_vector(v1,"v1 = ");

    return 0;
}
