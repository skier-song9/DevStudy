// #include <iostream>

// int main(int argc, char *argv[])
// {
//     std::cout << "Hello World" << std::endl;
//     return 0;
// }

/*
* g++ -v --save-temps -o hello hello00.cpp
    -c : 오브젝트 파일을 만드는 옵션.
    -o : 파일이름 지정
    -v : 컴파일 과정을 화면에 출력하는 옵션
    --save-temps : 컴파일 중의 생산물을 저장하는 옵션

>> 컴파일 중 생성된 파일들 : .ii , .o , .s
    .ii : 라이브러리 등을 명시해주는 파일(전처리기가 만듦.)
    .s : 어셈블 파일
    .o : 링커 파일. (=collect2)

    📢gcc 컴파일러 12페이지 참고.


    -Wall
    -W
    -g

    정리) 
    g++의 컴파일 과정
        전처리기 - 컴파일 - 어셈블 - 링킹 >> 실행파일이 완성됨.

*/

#include <iostream>
#define MESSAGE "Hello World using Macro"

// Message라는 리터럴변수는 뒤의 문자열임을 표현.
// 자바로 치면 상수 선언.
int main(int argc, char *argv[])
{
    std::cout << MESSAGE << std::endl;
    // hello.ii 파일을 보면 MESSAGE가 선언한 문자열로 '치환'되어 있다. 전처리기가 메크로 치환 과정을 수행한다.
    return 0;
}







