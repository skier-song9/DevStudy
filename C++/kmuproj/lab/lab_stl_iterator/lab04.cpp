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
    vector<char> v(3,'x');
    print_vector(v,"15. v= ");
    char a[] = {'a','b','c','d','e'};
    vector<char>::iterator it;
    it = v.insert(v.begin(),'p');
    
    
    
    
    return 0;
}
