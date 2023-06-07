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
    vector<int> v1(5,5);
    print_vector(v1,"v1 = ");
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    vector <int> v2{&a[0], &a[5]};
    print_vector(v2, "v2 = ");
    vector <int> v3(v2); //copy constructor
    print_vector(v3, "v3 = ");

    vector<int> v5(v3.begin()+1,v3.begin()+4);
    print_vector(v5, "v5 = ");
    

    return 0;
}
