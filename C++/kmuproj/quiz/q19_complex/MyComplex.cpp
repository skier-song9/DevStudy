#include "MyComplex.h"

//Ctor
myComplex::myComplex(int real, int imag){
	realPart = real;
	imaginaryPart = imag;
}
myComplex::myComplex(int real){
	realPart = real;
	imaginaryPart = 0;
}

//Copy Ctor
myComplex::myComplex(const myComplex& number){
	realPart = number.realPart;
	imaginaryPart = number.imaginaryPart;
}
//Getter
int myComplex::getRealPart() const{
	return realPart;
}
int myComplex::getImaginaryPart() const{
	return imaginaryPart();
}
//Setter
void myComplex::setRealPart(int real){
	realPart = real;
}
void myComplex::setImaginaryPart(int imag){
	imaginaryPart = imag;
}
void myComplex::set(int real, int imag){
	realPart = real;
	imaginaryPart = imag;
}
//Operators
myComplex myComplex::operator +(const myComplex& number) const{
	int newReal = realPart + number.realPart;
	int newImag = imaginaryPart + number.imaginaryPart;
	return myComplex (newReal, newImag);
}
myComplex myComplex::operator +(int value) const{
	return myComplex(value) + (*this);
}
myComplex myComplex::operator -(const myComplex& number) const{
     int newReal = realPart - number.realPart;
     int newImag = imaginaryPart - number.imaginaryPart;
	return myComplex (newReal, newImag);
}
myComplex myComplex::operator -(int value) const{
	return myComplex(value) - (*this);
}
myComplex myComplex::operator *(const myComplex& number) const{
     int newReal = realPart * number.realPart - imaginaryPart * number.imaginaryPart;
     int newImag = realPart * number.imaginaryPart + imaginaryPart * number.realPart;
	return myComplex (newReal, newImag);
}
myComplex myComplex::operator *(int value) const{
	return myComplex(value) * (*this);
}

// Assignment operators
myComplex& myComplex::operator =(const myComplex& number){
	this->realPart = number.realPart;
	this->imaginaryPart = number.imaginaryPart;
	return *this;
}
myComplex& myComplex::operator =(int value){
	realPart = value;
	imaginaryPart = 0;
	return *this;
}

// Overloading comparison operators
bool myComplex::operator ==(const myComplex& number) const{
	return (realPart == number.realPart) && 
		(imaginaryPart == number.imaginaryPart);
}
bool myComplex::operator >(const myComplex& number) const{
	return norm() > number.norm();
}
// Overloaded unary operators
myComplex myComplex::operator -() // unary minus{
	return myComplex(-realPart, -imaginaryPart);
}

friend ostream& myComplex::operator <<(ostream cout,const Complex& number){
	cout << "(" << number.realPart << "," << number.imaginaryPart << ")" << "\n";
	return cout;
}

int myComplex::norm() const{
	return realPart * realPart + imaginaryPart * imaginaryPart;
}
ostream &operator << (ostream &outStream, const myComplex& number){
	outStream << "(" << number.realPart << ", " << number.imaginaryPart << ")";
	return outStream;
}
istream &operator >> (istream &inStream, myComplex& number){
	inStream >> number.realPart >> number.imaginaryPart;
	return inStream;
}

