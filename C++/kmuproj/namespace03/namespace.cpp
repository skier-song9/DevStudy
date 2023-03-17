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

//📢 using namespace 네임스페이스명 
//    : main()함수에서 해당 네임스페이스명을 '기본값'으로 사용한다.
//  ex) using namespace ns1; >> ns1의 test()함수는 ns1::test()처럼 호출하지 않고,
//      그냥 test()로 호출한다.

int main(int argc, char const *argv[])
{
    ns1::test(); //namespace를 명시해야 한다. >> "Hello World"
    ns2::test(); //"Kookmin Univ."
    ns3::test(); //"Good Morning!"
    return 0;
}
