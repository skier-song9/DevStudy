#include <iostream>
using namespace std;

class Product{
public:
    explicit Product() = default;
    explicit Product (int pid, string vid)
        :pid{pid}, vid{vid}{
            ++Product::count;
    };

public:
    virtual ~Product() { cout << "dtor : " << pid << endl;};

public:
    int pid{9};
    string vid{"kmu"};

public:
    static int count;
};

//static 변수를 외부에서 초기화해준다.
int Product::count{0};

int main(int argc, char const *argv[])
{
    Product prod1{100, "hello"};
    cout << "prod1.pid = " << prod1.pid << endl;
    cout << "prod1.vid = " << prod1.vid << endl;
    cout << "prod1.count = " << prod1.count << endl;

    Product prod2{200, "hello"};
    cout << "prod2.pid = " << prod2.pid << endl;
    cout << "prod2.vid = " << prod2.vid << endl;
    cout << "prod2.count = " << prod2.count << endl;

    Product prod3{300, "hello"};
    cout << "prod3.pid = " << prod3.pid << endl;
    cout << "prod3.vid = " << prod3.vid << endl;
    cout << "prod3.count = " << prod3.count << endl;
    return 0;
}
