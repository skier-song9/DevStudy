#include <iostream>
#include <fstream>
#include <cmath>
class myComplex {
public:
    // ructor (생성자)
    myComplex(int real = 0, int imag = 0);
    // Copy ructor (복사 생성자)
    myComplex(const myComplex& number);
    // Accessor functions (접근자)
    int gr() const;
    int gi() const;
    // Mutator functions (변경자)
    void setRealPart(int real);
    void setImaginaryPart(int imag);
    void set(int real, int imag);
    // Overloaded binary operators
    myComplex operator +(const myComplex& number) const;
    myComplex operator +(int value) const;
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
    myComplex operator++();
    myComplex operator++(int);
    myComplex operator--();
    myComplex operator--(int); 
    // std::ostream &operator <<(std::ostream &outStream,  myComplex& number);
    // std::istream &operator >>(std::istream &inStream, myComplex& number);
    private:
    int realPart;
    int imaginaryPart;
    double norm() const;
};
//////////////////////////////////////////////////////////////////////
myComplex::myComplex(int real, int imag)
{
    realPart = real;
    imaginaryPart = imag;
}
// Copy ructor
myComplex::myComplex(const myComplex& number)
{
    realPart = number.realPart;
    imaginaryPart = number.imaginaryPart;
}
// Accessor functions
int myComplex::gr() const
{
    return realPart;
}
int myComplex::gi() const
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
    return (*this) + myComplex(value);
}
myComplex myComplex::operator -(const myComplex& number) const
{
    int newReal = realPart - number.realPart;
    int newImag = imaginaryPart - number.imaginaryPart;
    return myComplex (newReal, newImag);
}
myComplex myComplex::operator -(int value) const
{
    return (*this) - myComplex(value);
}
myComplex myComplex::operator *(const myComplex& number) const
{
    int newReal = realPart * number.realPart - imaginaryPart * number.imaginaryPart;
    int newImag = realPart * number.imaginaryPart + imaginaryPart * number.realPart;
    return myComplex (newReal, newImag);
}
myComplex myComplex::operator *(int value) const
{
    int newReal = realPart * value;
    int newImag = imaginaryPart * value;
    return myComplex(newReal,newImag);
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
    realPart = realPart + number.realPart;
    imaginaryPart = imaginaryPart + number.imaginaryPart;
    return *this;
}
myComplex& myComplex::operator +=(int value)
{
    realPart = realPart + value;
    return *this;
}
myComplex& myComplex::operator -=(const myComplex& number)
{
    realPart = realPart - number.realPart;
    imaginaryPart = imaginaryPart - number.imaginaryPart;
    return *this;
}
myComplex& myComplex::operator -=(int value)
{
    realPart = realPart - value;
    return *this;
}
myComplex& myComplex::operator *=(const myComplex& number)
{
    int newReal = realPart * number.realPart - imaginaryPart * number.imaginaryPart;
    int newImag = realPart * number.imaginaryPart + imaginaryPart * number.realPart;
    this->realPart = newReal;
    this->imaginaryPart = newImag;
    return *this;
}
myComplex& myComplex::operator *=(int value)
{
    int newReal = realPart * value;
    int newImag = imaginaryPart * value;
    this->realPart = newReal;
    this->imaginaryPart = newImag;
    return *this;
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
double myComplex::norm() const{
    return std::sqrt(realPart*realPart + imaginaryPart*imaginaryPart);
};
bool myComplex::operator >(const myComplex& number) const
{
    bool b = norm() > number.norm();
    return b;
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
myComplex myComplex::operator -() // unary minus
{
    return myComplex(-realPart, -imaginaryPart);
} 
myComplex myComplex::operator~(){
    return myComplex(realPart,-imaginaryPart);
}; 
myComplex myComplex::operator++(){
    ++realPart;
    return *this;
};
myComplex myComplex::operator++(int){
    myComplex number{realPart,imaginaryPart};
    ++realPart;
    return number;
};
myComplex myComplex::operator--(){
    --realPart;
    return *this;
};
myComplex myComplex::operator--(int){
    myComplex number{realPart,imaginaryPart};
    --realPart;
    return number;
}; 
//////////////////////////////////////////////////////////////
void testSimpleCase();
void testDataFromFile();
int main()
{
    testSimpleCase();
    testDataFromFile();

    return 0;
}
void testSimpleCase()
{
    myComplex c0, c1(1), c2(2, 2),ct,ct1,ct2,ct3,ct4;
    myComplex c3(c2);
    myComplex c4, c5, c6, c7, c8, c9;
    // test ructor
    std::printf("(%d,%d)\n",c0.gr(),c0.gi());//0.0
    std::printf("(%d,%d)\n",c1.gr(),c1.gi());//1.0
    std::printf("(%d,%d)\n",c2.gr(),c2.gi());//2.2
    // test copy ructor
    std::printf("(%d,%d)\n",c3.gr(),c3.gi());//2.2
    // test accessor function
    std::printf("(%d,%d)\n",c3.gr(),c3.gi());//2.2
    // test mutator function
    c3.set(3, 3);
    std::printf("(%d,%d)\n",c3.gr(),c3.gi());//3.3
    c3.setRealPart(4);
    std::printf("(%d,%d)\n",c3.gr(),c3.gi());//4.3
    c3.setImaginaryPart(4);
    std::printf("(%d,%d)\n",c3.gr(),c3.gi());//4.4
    // test binary operators
    // printf("test binary operators 1\n");
    c4 = (c1 + c3);//5.4
    c5 = (c1 - c3);//-3.-4
    c6 = (c4 * c5);//1.-32
    std::printf("(%d,%d)\n(%d,%d)\n(%d,%d)\n",c4.gr(),c4.gi(),c5.gr(),c5.gi(),c6.gr(),c6.gi());
    c7 = c6 + 2;//3.-32
    c8 = c6 - 2;//-1.-32
    c9 = c6 * 2; //2.-64 
    // printf("test binary operators 2\n");
    std::printf("(%d,%d)\n(%d,%d)\n(%d,%d)\n",c7.gr(),c7.gi(),c8.gr(),c8.gi(),c9.gr(),c9.gi());
    c7 += c4;//8.-28
    c8 -= c5;//2.-28 
    c9 *= c6;//-2046.-128 //[x]
    // printf("test binary operators 3\n");
    std::printf("(%d,%d)\n(%d,%d)\n(%d,%d)\n",c7.gr(),c7.gi(),c8.gr(),c8.gi(),c9.gr(),c9.gi());
    c7 += 2; //
    c8 -= 2; //
    c9 *= 2; //x //[x]
    // printf("test binary operators 4\n");
    std::printf("(%d,%d)\n(%d,%d)\n(%d,%d)\n",c7.gr(),c7.gi(),c8.gr(),c8.gi(),c9.gr(),c9.gi());
    // test comparison operators
    // printf("test comparison operators \n");
    std::printf("%d %d\n",(c8 != c9),(c8 == c9));
    std::printf("%d %d %d %d\n",(c8 > c9),(c8 >= c9),(c8 < c9),(c8 <= c9));
    c7 = c8 = c9;
    std::printf("%d %d\n",(c8 != c9),(c8 == c9));
    std::printf("%d %d %d %d\n",(c8 > c9),(c8 >= c9),(c8 < c9),(c8 <= c9));
    // test prefix operators
    // printf("test prefix operators \n");
    c7 = -myComplex(2, 3);
    c8 = (++c7) * 2;
    c9 = (c7++) * 2;
    std::printf("(%d,%d) (%d,%d) (%d,%d)\n",c7.gr(),c7.gi(),c8.gr(),c8.gi(),c9.gr(),c9.gi());
    c7 = ~myComplex(2, 3);
    c8 = (--c7) * 2;
    c9 = (c7--) * 2;
    std::printf("(%d,%d) (%d,%d) (%d,%d)\n",c7.gr(),c7.gi(),c8.gr(),c8.gi(),c9.gr(),c9.gi());
    // test expressions with myComplex numbers
    c1 = myComplex(1,2);
    c2 = myComplex(2,3);
    c3 = myComplex(4,5);
    c4 = myComplex(5,6);
    c5 = myComplex(6,7);
    c6 = 3;
    // ct = -(c6) -(c1*c2) - c3*2 + ~c4 * c5 * 3 + 2;
    // ct = -(c1*c2) - (c3*2) + ((((~c4) * c5) * 3) + 2); 
    ct1 = c1*c2;
    ct1 = -ct1;
    ct2 = c3 * 2;
    ct3 = ~c4;
    ct3 *= c5;
    ct3 *= 3;
    ct3 += 2;
    ct4 = ct1 - ct2 + ct3 - c6;
    ct = ct4;
    printf("(%d,%d)\n",ct.gr(),ct.gi());
    // printf("end sample \n");
}
void testDataFromFile()
{
    int t;
    std::scanf("%d",&t);
    while(t--)
    {
        int a,b,c,d,e,f,g,h;
        myComplex c1, c2, c3, c4, tn1, tn2, tn3, tn4, tn5;
        myComplex c5, c6, c7, c8, c9;
        std::scanf("%d %d %d %d %d %d %d %d",&a,&b,&c,&d,&e,&f,&g,&h);
        c1.set(a,b);
        c2.set(c,d);
        c3.set(e,f);
        c4.set(g,h);
        // printf("test1 \n");
        std::printf("(%d,%d) (%d,%d) (%d,%d) (%d,%d)\n",c1.gr(),c1.gi(),c2.gr(),c2.gi(),c3.gr(),c3.gi(),c4.gr(),c4.gi());
        // tnum = (c1 + 2 + 3) + (-c2 + 2 - 3) * (c3 * 2 * 3) - (c4 * 2 - 3);
        // ((c1 + 2)+ 3) + ((((-c2) + 2) - 3) * ((c3 * 2) * 3)) - ((c4 * 2) - 3);
        tn1 = c1 + 2;
        tn1 += 3;
        tn2 = (-c2);
        tn2 += 2;
        tn2 -= 3;
        tn3 = c3 * 2;
        tn3 *= 3;
        tn4 = c4 * 2;
        tn4 -= 3;
        tn2 *= tn3;
        tn5 = tn1 + tn2 - tn4;
        std::printf("(%d,%d)\n",tn5.gr(),tn5.gi()); //x
        // printf("test2 \n");
        c5 = c6 = c7 = c8 = c1;
        std::printf("%d %d\n",(c5 == c2),(c5 != c2));
        std::printf("%d %d %d %d\n",(c5 > c2),(c5 >= c2),(c5 < c2),(c5 <= c2));
        std::printf("%d %d\n",(c5 == c6),(c5 != c6));
        std::printf("%d %d %d %d\n",(c5 > c6),(c5 >= c6),(c5 < c6),(c5 <= c6));
        c5 += c2;
        c6 -= c3;
        c7 *= c4;
        c8 = c2.gr();
        c9 = c3.gi();
        // printf("test3 \n");
        std::printf("(%d,%d) (%d,%d) (%d,%d) (%d,%d) (%d,%d)\n",c5.gr(),c5.gi(),c6.gr(),c6.gi(),c7.gr(),c7.gi(),c8.gr(),c8.gi(),c9.gr(),c9.gi());
        c7 = -c6;
        c8 = (++c7) * 2;
        c9 = (c7++) * 2;
        std::printf("(%d,%d) (%d,%d) (%d,%d)\n",c7.gr(),c7.gi(),c8.gr(),c8.gi(),c9.gr(),c9.gi());
        c7 = ~c6;
        c8 = (++c7) * 2;
        c9 = (c7++) * 2;
        // printf("test4 \n");
        std::printf("(%d,%d) (%d,%d) (%d,%d)\n",c7.gr(),c7.gi(),c8.gr(),c8.gi(),c9.gr(),c9.gi());
    }
}