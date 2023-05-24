#include <iostream>
class bok{
public:
	explicit bok(int real=0,int imag=0)
	:real(real),imag(imag){};
	
	int getReal(){return real;}
	int getImag(){return imag;}

	bok& operator=(const bok& b){
		this->real = b.real;
		this->imag = b.imag;
		return *this; 
	}

	bok operator+(const bok& num){
		return bok(real + num.real, imag + num.imag);
	}
	
//	friend std::ostream &operator<<(std::ostream& os, bok& b){
//		os << "(" << b.real << "," << b.imag << ")" << "\n";
//		return os;
//	}
//	friend std::istream &operator>>(std::istream& is, bok& b){
//		is >> b.real >> b.imag;
//		return is;
//	}
	
private:
	int real{};
	int imag{};

};

int main(){
	bok b1{1,2};
	bok b2{3,4};

	bok bt = b1+b2;
	printf("(%d,%d)\n",bt.getReal(),bt.getImag()); 


	return 0;
}
