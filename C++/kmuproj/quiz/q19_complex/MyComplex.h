Complex c(1,2);
cout << c << endl;
의 출력값이 c객체의 메모리 주소가 아니라 "(1,2)"가 되도록 하려면 어떻게 해야 하는가?

#ifndef _MYCOMPLEX_H_
#define _MYCOMPLEX_H_

#include <iostream>
#include <math.h>
using namespace std;

class myComplex{
public:
	//Ctor
	myComplex(int real=0, int imag=0);
	myComplex(const myComplex& number);

	//Getter
	int getRealPart() const;
	int getImaginaryPart() const;
	//Setter
	void setRealPart(int real);
	void setImaginaryPart(int imag);
	void set(int real, int imag);

	//Overloaded binary operators
	myComplex operator +(const myComplex& number) const;
	myComplex operator +(int value) const;
	myComplex operator -(const myComplex& number) const;
	myComplex operator -(int value) const;
	myCOmplex operator *(const myComplex& number) const;
	myComplex operator *(int value) const;

	//Overloaded assignment operators
	myComplex& operator =(const myComplex& number);
	myComplex& operator =(int value);
	myComoplex& operator +=(const myComplex& number);
	myComplex& operator +=(int value);
	myComoplex& operator -=(const myComplex& number);
    myComplex& operator -=(int value);
	myComoplex& operator *=(const myComplex& number);
    myComplex& operator *=(int value);

	//Conjugate
	myComplex conjugate(const myComplex& number) const;
	myComplex conjugate(int value) const; 

	//Overloaded relational operators
	bool operator ==(const myComplex& number) const;
	bool operator !=(const myComplex& number) const;
	bool operator >(const myComplex& number) const;
	bool operator >=(const myComplex& number) const;
	bool operator <(const myComplex& number) const;
	bool operator <=(const myComplex& number) const;
	
	//Overloaded unary operators
	myComplex operator -(const myComplex& number) const;
	myComplex operator ~(const myComplex& number) const;

	//Overloaded ostream
	friend ostream& operator<<(ostream os, const Complex& number) const;
private:
	int realPart;
	int imaginaryPart;
	int norm() const;

};

#endif
