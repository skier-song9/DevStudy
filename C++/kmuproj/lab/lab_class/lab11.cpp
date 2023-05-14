#include <iostream>
using namespace std;

class Product{
public:
    explicit Product() = default;
    // explicit Product (int pid, string vid){
    //     this->pid = pid; //[x]error: assignment of read-only member ‘Product::pid’
    //     this->vid = vid;
    // };
    explicit Product (int pid, string vid)
        :pid{pid}, vid{vid}{
    };

public:
    virtual ~Product() { cout << "dtor : " << pid << endl;};

public:
    const int pid{9};
    string vid{"kmu"};
};

int main(int argc, char const *argv[])
{
    Product prod{100, "hello"};
    cout << "prod.pid = " << prod.pid << endl;
    cout << "prod.vid = " << prod.vid << endl;

    return 0;
}
