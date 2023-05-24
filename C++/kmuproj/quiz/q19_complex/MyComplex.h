#ifndef _MYCOMPLEX_H_
#define _MYCOMPLEX_H_
#include <iostream>
#include <cmath>
class myComplex {
public:
    // Constructor (생성자)
    myComplex(int real = 0, int imag = 0);
    // Copy constructor (복사 생성자)
    myComplex(const myComplex& number);
    // Accessor functions (접근자)
    int getRealPart() const;
    int getImaginaryPart() const;
    // Mutator functions (변경자)
    void setRealPart(int real);
    void setImaginaryPart(int imag);
    void set(int real, int imag);
    // Overloaded binary operators
    myComplex operator +(const myComplex& number) const;
    myComplex operator +(int value) const;
    friend myComplex myComplex::operator +(int value, const myComplex& number);
    myComplex operator -(const myComplex& number) const;
    myComplex operator -(int value) const;
    myComplex operator *(const myComplex& number) const;
    myComplex operator *(int value) const;
    // Overloaded assignment operators
    myComplex& operator =(const myComplex& number);
    myComplex& operator =(int value);
    myComplex& operator +=(const myComplex& number);
    myComplex& operator +=(int value);
    myComplex& operator -=(const myComplex& number);
    myComplex& operator -=(int value);
    myComplex& operator *=(const myComplex& number);
    myComplex& operator *=(int value);
    // Overloading relational operators
    bool operator ==(const myComplex& number) const;
    bool operator !=(const myComplex& number) const;
    bool operator <=(const myComplex& number) const;
    bool operator <(const myComplex& number) const;
    bool operator >=(const myComplex& number) const;
    bool operator >(const myComplex& number) const;
    // Overloaded unary operators
    myComplex operator-(); 
    myComplex operator~(); 
    myComplex &operator++();
    myComplex &operator++(int);
    myComplex &operator--();
    myComplex &operator--(int); 

    // std::ostream &operator <<(std::ostream &outStream, const myComplex& number);
    // std::istream &operator >>(std::istream &inStream, myComplex& number);
    friend std::ostream &operator<<(std::ostream &outStream, const myComplex& number)
    {
        outStream << "(" << number.realPart << "," << number.imaginaryPart << ")";
        return outStream;
    }
    friend std::istream &operator >>(std::istream &inStream, myComplex& number)
    {
        inStream >> number.realPart >> number.imaginaryPart;
        return inStream;
    }
    private:
    int realPart;
    int imaginaryPart;
    int norm() const;
};
#endif