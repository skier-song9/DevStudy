#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int i{10};
    int &r{i};

    // 20 = i; [x] error: lvalue required as left operand of assignment

    // int &r1{100}; [x] error: cannot bind non-const lvalue to an rvalue

    return 0;
}
