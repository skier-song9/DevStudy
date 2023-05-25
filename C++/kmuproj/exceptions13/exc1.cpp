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

int main(){
	int v;
	try{
		cout << "enter a value: ";
		cin >> v;
		if (v<0) throw NonPositiveException(v);
		if (v==0) throw ZeroException(v);
	}
	catch(ZeroException& e){ cout << "Zero \n"; }
	catch(NonPositiveException& e){ cout << "Negative Value: " << e.v << endl; }

	cout << v << endl;
	return 0;
}
