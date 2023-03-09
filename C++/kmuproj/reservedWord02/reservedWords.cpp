#include <iostream>
int main(int argc , char argv []) {

    /*
    예약어인 것은 변수명으로 사용이 불가능하다.
    */

    std::cout << "Hello World!" << "\n";

    std:: string include {"include."}; //string타입의 include변수명에 "include"문자열을 저장하겠다는 문장.
    std::string iostream{"iostream."};
    std::string main{"main."};
    // std::string int{"int"}; //[x] expected primary-expression before 'int'
    // std::string char{"char"}; //[x]
    // std::string return {"return"}; //[x]

    std::cout << include << "\n";  //변수 출력
    std::cout << iostream << "\n";
    std::cout << main << "\n";

    // std::cout << int << "\n"; //[x]
    // std::cout << char << "\n"; //[x]
    // std::cout << return << "\n"; //[x]
}
