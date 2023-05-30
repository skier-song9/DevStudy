#include "max.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    std::cout << "template functions" << std::endl;
    std::cout << "max(10,20) = " << max(10,20) << std::endl;
    std::cout << "max(10.5f,20.7f) = " << max(10.5f,20.7f) << std::endl;
    std::cout << "max(10.5,20.7) = " << max(10.5,20.7) << std::endl;
    std::cout << "max(10.5f,10) = " << max(10.5f,10) << std::endl;
    
    std::cout << "done..." << std::endl;
    return 0;
}
