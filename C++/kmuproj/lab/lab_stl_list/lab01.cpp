#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

template <class T>
void print_container(const T& container, string s=""){
    cout << s << "(" << container.size() << ")";
    auto it = container.begin();
    for(;it != container.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    char a[] = {'a','b','c','d','e','f','x','y','z','w'};
    vector<char> v(&a[5],&a[9]);   
    list<char> l1(3,'x');
    print_container(l1,"l1 = ");
    l1.push_front('*');
    l1.push_back('a');
    print_container(l1,"l1 after push = ");
    return 0;
}
