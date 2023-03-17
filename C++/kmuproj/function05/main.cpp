#include <iostream>

//📢"함수 선언" = 함수의 프로토타입(원형)을 선언한다.
namespace cal{ //📢namespace 선언 시, 프로토타입과 구현부에서 모두 명시해줘야 한다. 
    int add(int,int); // 매개변수명은 달라도 되고 '없어도' 된다. 그러나 매개변수의 개수와 자료형은 같아야 한다❗
}
int sub(int i,int k);
int mul(int x,int y);
int div_(int x,int y);
int rem(int x,int y);//주로 함수에 대한 주석을 달 때, 함수의 프로토타입에 주석을 달기 때문에, 
                    //매개변수명을 정의부의 매개변수명과 맞춰주는 게 좋다.

using namespace cal;

int main(int argc, char const *argv[])
{
    std::cout << "Calculate: Add function" << "\n";

    int x = 10;
    int y = 20;

    int sum = cal::add(x,y);
    std::cout << sum << "\n";
    
    std::cout << sub(x,y) << "\n";
    std::cout << mul(x,y) << "\n";
    std::cout << div_(50,4) << "\n";
    std::cout << rem(9,4) << "\n";

    return 0;
}

//📢관례상 함수는 main함수(entry point)아래에 작성한다. >> 여기선 "함수 구현부"만 작성한다.
//  >> error: 'add' was not declared in this scope 예외가 발생한다.
//  >> 함수 구현부를 제외한 함수 "선언부"만 위로 올려준다.
namespace cal{ //📢namespace 선언 시, 프로토타입과 구현부에서 모두 명시해줘야 한다. 
    int add(int x,int y) {return x+y;}
}
int sub(int x,int y) {return x-y;}
int mul(int x,int y) {return x*y;}
int div_(int x,int y) {return x/y;} // ⚠️함수명 div로 못함 >> div()는 표준 라이브러리 함수이므로 이미 존재한다.
int rem(int x,int y) {return x%y;}
