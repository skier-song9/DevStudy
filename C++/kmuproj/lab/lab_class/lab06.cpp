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

protected:
    int pid_protected{};
    string vid_protected{};

private:
    int pid_private{};
    string vid_private{};
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

    cout << "prod.pid_protected = " << prod.pid_protected << endl; 
    cout << "prod.vid_protected = " << prod.vid_protected << endl; 

    cout << "prod.pid_private = " << prod.pid_private << endl; 
    cout << "prod.vid_private = " << prod.vid_private << endl; 

    return 0;
}
