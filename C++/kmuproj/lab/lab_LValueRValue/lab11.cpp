#include <iostream>
using namespace std;

int &makeReference() {
    int *i = new int{7000};    
    return *i;
}

int main(int argc, char const *argv[])
{
    int &ret_lvalue{makeReference()};
    cout << "ret_lvalue = " << ret_lvalue << endl;

    delete &ret_lvalue;

    return 0;
}
