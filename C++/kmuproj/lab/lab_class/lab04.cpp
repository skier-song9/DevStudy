#include <iostream>
using namespace std;

class Product {
public:
    int pid{}; //product id
    string vid{}; //vendor id
};

int main(int argc, char const *argv[])
{
    Product prod{30,"kmu"};

    cout << "&prod = " << &prod << endl;

    cout << "prod.pid = " << prod.pid << endl; 
    cout << "prod.vid = " << prod.vid << endl; 


    return 0;
}
