#include <iostream>

namespace first{
    std::string say(std::string str){
        return str;
    }
}

int main(int argc, char const *argv[])
{
    std::string greeting = first::say("Hello!");
    std::cout << greeting << "\n";

    return 0;
}
