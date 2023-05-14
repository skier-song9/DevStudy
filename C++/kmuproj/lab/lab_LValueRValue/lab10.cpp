#include <iostream>
using namespace std;

int makeRvalue() {return 1000;}

int main(int argc, char const *argv[])
{
    int &&ret_rvalue{makeRvalue()};
    cout << "ret_rvalue = " << ret_rvalue << endl;

    // int &ret_lvalue = makeRvalue(); [x]

    return 0;
}
