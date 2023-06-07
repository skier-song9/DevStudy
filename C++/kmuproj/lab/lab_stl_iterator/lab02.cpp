#include <iostream>
#include <vector>
using namespace std;

template <class T>
void print_vector(vector<T> v, string s=""){
    cout << s << "(" << v.size() << ") ";
    for(vector<int>::iterator it = v.begin(); it!=v.end(); ++it){
        cout << *it << " ";
    }
    // for (int i{};i<v.size();i++) cout << v[i] << " ";
    cout << endl;
}

int main(int argc, char const *argv[])
{
    vector<int> v(5);
    int i=0;
    vector<int>::reverse_iterator rit = v.rbegin();
    for(;rit!=v.rend();++rit){
        *rit = ++i;
    }

    print_vector(v,"assigned by reverse iterator v: ");

    return 0;
}
