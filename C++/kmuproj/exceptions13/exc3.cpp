#include <iostream>
using namespace std;

class NonPositiveException{
public:
	int v;
	NonPositiveException(int v): v(v){}
};
class ZeroException : public NonPositiveException{
public:
    ZeroException(int v): NonPositiveException(v){}
};

void foo(){
    try{
        int v;
        cout << "enter a value: " ;
        cin >> v;
        if (v<0) throw NonPositiveException(v);
        if (v==0) throw ZeroException(v);
        cout << "foo\n";
    }
    catch(...){
        cout << "foo catches exception\n";
        throw;
    }
}

int main(){
	try{
		foo();
	}
	catch(ZeroException& e){ cout << "Zero \n"; }
	catch(NonPositiveException& e){ cout << "Negative Value: " << e.v << endl; }

    cout << "main" << endl;
	return 0;
}
