#include "max.hpp"
#include <iostream>

template <typename T> T max(T const a, T const b){
    std::cout << "T max()" << "\n";
    return (a>b)?(a):(b);
}