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
    vector<int> v(3,5);
    print_vector(v,"15. v: ");
    v[0] = 0; v[1] = 1; v[2] =2;
    print_vector(v,"17. v: ");
    // v[3] = 5;
    v.at(3) = 5; //at()을 사용하면 runtime error를 발생시킴
    print_vector(v,"18. v: ");
    v.push_back(5);
    print_vector(v, "20. v: ");
    
    return 0;
}   

