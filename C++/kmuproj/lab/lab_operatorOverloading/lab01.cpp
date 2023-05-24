#include <iostream>
//using namespace std;
class Number{
public:
	Number(int const value) : value{value} {}
public:
	bool operator==(Number const &rhs) const {return value == rhs.value;}
//	bool operator!=(Number const &rhs) const {return !(value==rhs.value);}	
	bool operator!=(Number const &rhs) const {return !(*this==rhs);}
	Number operator+(Number const &rhs) const {
		return (value + rhs.value);
	} 
	bool operator<(Number const &rhs) const {return value < rhs.value;}
	bool operator>(Number const &rhs) const {return rhs < *this;}
	bool operator<=(Number const &rhs) const {return !(*this > rhs);}
	bool operator>=(Number const &rhs) const {return !(*this < rhs);}

	Number &operator++(){
		++value;
		return *this;
	}
	Number operator++(int){
		Number ret{value};
		++value;
		return ret;
	}

	friend Number operator++(Number &n1,int){
		Number ret{n1.value};
		n1.value++;
		return ret;
	}
	

//	friend bool operator==(Number const &n1, Number const &n2) {
//		return n1.value == n2.value;
//	}

public:
//private:
	int value{};
};

int main(){
	Number n1{10};
	Number n2{20};

//	cout << boolalpha;
	std::cout << "(n1 == n2) : " << (n1 == n2) << "\n";
	
	n1 = Number{19};
	std::cout << "(n1==n2) : " << (n1==n2) << "\n";

	std::cout << "(n1+n2) = " << (n1+n1) << "\n";

//	cout << noboolalpha;

	return 0;
}