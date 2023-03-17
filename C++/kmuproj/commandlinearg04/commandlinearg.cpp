#include <iostream>
int main(int argc , char *argv [])
{
    std::string title{"Command Line Arguments"};
    std::cout << title << "\n";

    std::cout << "argument count : " << argc << "\n";

    std::cout << "argument vector : " << std::endl;

    // std::cout << argv[0] << std::endl;
    // std::cout << argv[1] << std::endl ;
    // std::cout << argv[2] << std::endl ;

    for (int i=0; i<argc; i++){
        std::cout << argv[i] << std::endl;
    }
    return 0;
}