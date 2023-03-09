#include <iostream>

namespace ns1 {
void test() {
    std::cout << "Hello World" << "\n";
}
}

// void test() { //[x] redefinition of 'void test()'
//     std::cout << "Kookmin Univ." << "\n";
// }

namespace ns2 { //📢namespace를 구분해주면 된다. >> 각각의  namespace 내에서는 test라는 이름이 유일하기 때문.
void test() {
    std::cout << "Koomin Univ." << "\n";
}
}

namespace ns3{
void test() {
    std::cout << "Good Morning!" << "\n";
}
}

int main(int argc, char const *argv[])
{
    ns1::test(); //namespace를 명시해야 한다. >> "Hello World"
    ns2::test(); //"Kookmin Univ."
    ns3::test(); //"Good Morning!"
    return 0;
}
