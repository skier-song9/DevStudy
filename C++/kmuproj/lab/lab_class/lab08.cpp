#include <iostream>
using namespace std;

class Product{
public:
    explicit Product() = default;
    explicit Product (int pid, string vid){
        this->pid = pid;
        this->vid = vid;
    }
public:
    int pid{};
    string vid{};
};

// class Product{
// public:
// explicit Product(int pid, string vid)
//     : pid{pid}, vid{vid}{
// }
// public:
//     int pid{};
//     string vid{};
// };

int main(int argc, char const *argv[])
{
    // Product prod1{60.5, "kmu"}; [x] Error
    Product prod1{int(60.5), "kmu"};
    cout << "prod1.pid = " << prod1.pid << endl;
    cout << "prod1.vid = " << prod1.vid << endl;
    
    Product prod2(60.5, "kmu");
    cout << "prod2.vid = " << prod2.pid << endl;
    cout << "prod2.vid = " << prod2.vid << endl;
    

    return 0;
}
