#include <iostream>
using namespace std;

class Product {
public:
    Product(int pid, string vid){
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


    return 0;
}
