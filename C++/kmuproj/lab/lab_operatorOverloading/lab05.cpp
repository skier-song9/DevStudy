#include <iostream>
class Number {
    friend bool operator==(Number const &n1, Number const &n2) {
        return n1.value == n2.value;
    }
    friend Number operator+(Number const &n1, Number const &n2) {
        return {n1.value + n2.value};
    }
    //friend bool operator!=(Number const &n1, Number const &n2){
    //      return n1.value!=n2.value;
    //}
    friend bool operator!=(Number const &n1, Number const &n2){
        return !(n1.value == n2.value);
    }
	friend bool operator>(Number const &n1, Number const &n2){
		return n1>n2;
	}
	friend bool operator<(Number const &n1, Number const &n2){
		return n2>n1;
	}
	friend bool operator<=(Number const &n1, Number const &n2){
		return !(n1>n2);
	}
	friend bool operator>=(Number const &n1, Number const &n2){
		return !(n1<n2);
	}
public:
    int value{};
};
int main(){
    Number n1{10};
    Number n2{20};
    std::cout << std::boolalpha;
    std::cout << "(n1 + n2) = " << (n1 + n2).value << "\n";
    std::cout << std::noboolalpha;
    return 0;
}
