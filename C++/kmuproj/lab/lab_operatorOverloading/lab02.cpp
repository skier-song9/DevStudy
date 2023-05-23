#include <iostream>
class Number {
	friend bool operator==(Number const &n1, Number const &n2) {
		return n1.value == n2.value;
	}
	friend Number operator+(Number const &n1, Number const &n2) {
		return {n1.value + n2.value};
	}
public:
	int value{};
};
int main(intargc , char argv []){
	Number n1{10};
	Number n2{20};
	std::cout << boolalpha;
	std::cout << "(n1 + n2) = " << (n1 + n2).value << "\n";
	std::cout << noboolalpha;
	return 0;
}
