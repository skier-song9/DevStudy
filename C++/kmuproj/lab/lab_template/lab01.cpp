#include <iostream>
// using namespace std;
template <> float max(float const a, float const b){
    std::cout << "float max(float const a, float const b)" << "\n";
    return (a>b)?(a):(b);
}
template <typename T> T max(T const a, T const b){
    return (a>b) ? (a) : (b);
}
template <> float max(float const a, float const b){
    std::cout << "float max(float const a, float const b)" << "\n";
    return (a>b)?(a):(b);
}
template <> double max(double const a, double const b){
    std::cout << "double max(double const a, double const b)" << "\n";
    return (a>b)?(a):(b);
}

int main(int argc, char const *argv[])
{
    std::cout << "template functions" << std::endl;
    std::cout << "max(10,20) = " << max<int>(10,20) << std::endl;
    std::cout << "max(10.5f,20.7f) = " << max(10.5f,20.7f) << std::endl;
    std::cout << "max(10.5,20.7) = " << max(10.5,20.7) << std::endl;
    std::cout << "max(10.5f,10) = " << max(10.5f,10) << std::endl;
    
    std::cout << "done..." << std::endl;
    return 0;
}
