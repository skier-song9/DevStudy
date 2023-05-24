#include "MyComplex.h"
// Constructor
myComplex::myComplex(int real, int imag)
{
    realPart = real;
    imaginaryPart = imag;
}
// Copy constructor
myComplex::myComplex(const myComplex& number)
{
    realPart = number.realPart;
    imaginaryPart = number.imaginaryPart;
}
// Accessor functions
int myComplex::getRealPart() const
{
    return realPart;
}
int myComplex::getImaginaryPart() const
{
    return imaginaryPart;
}
// Mutator functions
void myComplex::setRealPart(int real)
{
    realPart = real;
}
void myComplex::setImaginaryPart(int imag)
{
    imaginaryPart = imag;
}
void myComplex::set(int real, int imag)
{
    realPart = real;
    imaginaryPart = imag;
}
// Overloaded binary operators
myComplex myComplex::operator +(const myComplex& number) const
{
    int newReal = realPart + number.realPart;
    int newImag = imaginaryPart + number.imaginaryPart;
    return myComplex (newReal, newImag);
}
myComplex myComplex::operator +(int value) const
{
    return myComplex(value) + (*this);
}
myComplex myComplex::operator +(int value, const myComplex& number) const
{
    return myComplex(value) + (*this);
}
myComplex myComplex::operator -(const myComplex& number) const
{
    int newReal = realPart - number.realPart;
    int newImag = imaginaryPart - number.imaginaryPart;
    return myComplex (newReal, newImag);
}
myComplex myComplex::operator -(int value) const
{
    return myComplex(value) - (*this);
}
myComplex myComplex::operator *(const myComplex& number) const
{
    int newReal = realPart * number.realPart - imaginaryPart * number.imaginaryPart;
    int newImag = realPart * number.imaginaryPart + imaginaryPart * number.realPart;
    return myComplex (newReal, newImag);
}
myComplex myComplex::operator *(int value) const
{
    return myComplex(value) * (*this);
}
// Assignment operators
myComplex& myComplex::operator =(const myComplex& number)
{
    this->realPart = number.realPart;
    this->imaginaryPart = number.imaginaryPart;
    return *this;
}
myComplex& myComplex::operator =(int value)
{
    realPart = value;
    imaginaryPart = 0;
    return *this;
}
myComplex& myComplex::operator +=(const myComplex& number)
{
    return *this + number;
}
myComplex& myComplex::operator +=(int value)
{
    return *this + myComplex(value);
}
myComplex& myComplex::operator -=(const myComplex& number)
{
    return *this - number;
}
myComplex& myComplex::operator -=(int value)
{
    return *this - myComplex(value);
}
myComplex& myComplex::operator *=(const myComplex& number)
{
    return *this * number;
}
myComplex& myComplex::operator *=(int value)
{
    return *this * myComplex(value);
}
// Overloading comparison operators
bool myComplex::operator ==(const myComplex& number) const
{
    return (realPart == number.realPart) && 
    (imaginaryPart == number.imaginaryPart);
}
bool myComplex::operator !=(const myComplex& number) const
{
    return !(*this == number);
}
bool myComplex::operator >(const myComplex& number) const
{
    return norm() > number.norm();
}
bool myComplex::operator <(const myComplex& number) const
{
    return number.norm() > norm();
}
bool myComplex::operator >=(const myComplex& number) const
{
    return !(number.norm() > norm());
}
bool myComplex::operator <=(const myComplex& number) const
{
    return !(norm() > number.norm());
}
// Overloaded unary operators
myComplex myComplex::operator -(const myComplex& number) // unary minus
{
    return myComplex(-realPart, -imaginaryPart);
} 
myComplex operator~(const myComplex& number){
    return 0;
}; 
myComplex &operator++(){};
myComplex &operator++(int){};
myComplex &operator--(){};
myComplex &operator--(int){}; 
// private function
int myComplex::norm() const
{
    return std::sqrt(realPart * realPart + imaginaryPart * imaginaryPart);
}
// friend std::ostream &operator<<(std::ostream &outStream, const myComplex& number)
// {
//     outStream << "(" << number.realPart << "," << number.imaginaryPart << ")";
//     return outStream;
// }
// friend std::istream &operator >>(std::istream &inStream, myComplex& number)
// {
//     inStream >> number.realPart >> number.imaginaryPart;
//     return inStream;
// }