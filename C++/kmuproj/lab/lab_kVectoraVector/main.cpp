#include "kvector.hpp"
#include <iostream>
int main(int argc, char const *argv[])
{
    std::cout << "using kvector..." << "\n";

    Kvector vec{5,9};
    vec.print();

    return 0;
}
