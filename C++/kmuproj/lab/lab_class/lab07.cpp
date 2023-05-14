#include <iostream>
using namespace std;

class Product {
public:
    explicit Product(int pid, string vid){
        this -> pid = pid;
        this -> vid = vid;
    }

public:
    int pid{}; //product id
    string vid{}; //vendor id
};

int main(int argc, char const *argv[])
{
    Product prod(30,"kmu");
    //[x]  error: no matching function for call to ‘Product::Product(int, const char [4])’
    //>> 방법1) 생성자 함수를 만든다.
    //   방법2) 유니폼 초기화자{}를 사용한다.

    cout << "&prod = " << &prod << endl;

    cout << "prod.pid = " << prod.pid << endl; 
    cout << "prod.vid = " << prod.vid << endl; 

    // uniform initialization
    Product prod2{60,"kmu"};
    cout << "prod2.pid = " << prod2.pid << endl; 
    cout << "prod2.vid = " << prod2.vid << endl;

    // assign. class 타입으로 형변환되면서 할당된다. (비권장)
    // class의 생성자 함수명 앞에 "explicit"을 붙이면 이렇게 
    // 인스턴스를 생성하는 것을 컴파일 타임에서 방지한다❗
    Product prod3 = {90,"c++"};
    cout << "prod3.pid = " << prod3.pid << endl; 
    cout << "prod3.vid = " << prod3.vid << endl;

    return 0;
}
