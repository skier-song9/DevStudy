#include <iostream>

using namespace std;

class myRational{
private:
    // 분수는 항상 내부적으로 기약분수로 표현하며, 또한 항상 _den>0 이다.
    long _num; // numerator
    long _den; // denominator
public:
    //ctor
    myRational(int p=0,int q=1);
    myRational(const myRational& r);
    //getter/setter
    long gn();
    long gd();
    void sn(long n);
    void sd(long d);
    void set(long n, long d);
    long gcd(long m, long n); // 최대공약수
    void reduce();
    //operator overloading
};/////////////class

myRational::myRational(int p=0,int q=1)
    :_num(p),_den(q){ reduce(); };
myRational::myRational(const myRational& r){
    _num = r._num;
    _den = r._den;
    reduce();
};
long myRational::gn(){ return _num; };
long myRational::gd(){ return _den; };
void myRational::sn(long n){ _num = n; };
void myRational::sd(long d){ _den = d; };
void myRational::set(long n, long d){
    if(n==0){
        _num = n;
        _den = 1;
    }
    else{
        _num = n;
        _den = d;
    }
};
//Member Functions
long myRational::gcd(long m, long n){
    if (m ==n)
        return n;
    else if (m<n)
        return gcd(m,n-m);
    else 
        return gcd(m-n,n);
}; 
void myRational::reduce(){
    if (_num == 0 || _den ==0){
        _num = 0;
        _den = 1;
        return;
    }
    if (_den < 0 ){
        _den *= -1;
        _num *=-1;
    }
    if (_num==1){
        return;
    }
    int sgn = (_num < 0 ? -1 : 1);
    long g = gcd(sgn * _num, _den);
    _num /= g;
    _den /= g;
};
myRational myRational::reciprocal() const{
    long temp = _num;
    _num = _den;
    _den = temp;
    return *this;
};
//Overloaded Operators
// Overloaded binary operators
myRational myRational::operator +(const myRational& mr) const
{
    long newNum = _num * mr._den + mr._num * _den;
    long newDen = _den * mr._den;
    return myRational(newNum,newDen);
}
myRational myRational::operator +(int value) const
{
    long newNum = _num + value * _den;
    long newDen = _den;
    return myRational(newNum,newDen);
}
myRational myRational::operator -(const myRational& mr) const
{
    long newNum = _num * mr._den + mr._num * _den;
    long newDen = _den * mr._den;
    return myRational(newNum,newDen);
}
myRational myRational::operator -(int value) const
{
    long newNum = _num + value * _den;
    long newDen = _den;
    return myRational(newNum,newDen);
}
myRational myRational::operator *(const myRational& mr) const
{
    long newNum = _num * mr._den + mr._num * _den;
    long newDen = _den * mr._den;
    return myRational(newNum,newDen);
}
myRational myRational::operator *(int value) const
{
    long newNum = _num + value * _den;
    long newDen = _den;
    return myRational(newNum,newDen);
}
myRational myRational::operator /(const myRational& mr) const
{
    long newNum = _num * mr._den + mr._num * _den;
    long newDen = _den * mr._den;
    return myRational(newNum,newDen);
}
myRational myRational::operator /(int value) const
{
    long newNum = _num + value * _den;
    long newDen = _den;
    return myRational(newNum,newDen);
}
// Assignment operators
myRational& myRational::operator =(const myRational& mr)
{
    this->realPart = mr.realPart;
    this->imaginaryPart = mr.imaginaryPart;
    return *this;
}
myRational& myRational::operator =(int value)
{
    realPart = value;
    imaginaryPart = 0;
    return *this;
}
myRational& myRational::operator +=(const myRational& mr)
{
    realPart = realPart + mr.realPart;
    imaginaryPart = imaginaryPart + mr.imaginaryPart;
    return *this;
}
myRational& myRational::operator +=(int value)
{
    realPart = realPart + value;
    return *this;
}
myRational& myRational::operator -=(const myRational& mr)
{
    realPart = realPart - mr.realPart;
    imaginaryPart = imaginaryPart - mr.imaginaryPart;
    return *this;
}
myRational& myRational::operator -=(int value)
{
    realPart = realPart - value;
    return *this;
}
myRational& myRational::operator *=(const myRational& mr)
{
    int newReal = realPart * mr.realPart - imaginaryPart * mr.imaginaryPart;
    int newImag = realPart * mr.imaginaryPart + imaginaryPart * mr.realPart;
    this->realPart = newReal;
    this->imaginaryPart = newImag;
    return *this;
}
myRational& myRational::operator *=(int value)
{
    int newReal = realPart * value;
    int newImag = imaginaryPart * value;
    this->realPart = newReal;
    this->imaginaryPart = newImag;
    return *this;
}
// Overloading comparison operators
bool myRational::operator ==(const myRational& mr) const
{
    return (realPart == mr.realPart) && 
    (imaginaryPart == mr.imaginaryPart);
}
bool myRational::operator !=(const myRational& mr) const
{
    return !(*this == mr);
}
bool myRational::operator >(const myRational& mr) const
{
    bool b = norm() > mr.norm();
    return b;
}
bool myRational::operator <(const myRational& mr) const
{
    return mr.norm() > norm();
}
bool myRational::operator >=(const myRational& mr) const
{
    return !(mr.norm() > norm());
}
bool myRational::operator <=(const myRational& mr) const
{
    return !(norm() > mr.norm());
}
// Overloaded unary operators
myRational myRational::operator -() // unary minus
{
    return myRational(-realPart, -imaginaryPart);
} 
myRational myRational::operator~(){
    return myRational(realPart,-imaginaryPart);
}; 
myRational myRational::operator++(){
    ++realPart;
    return *this;
};
myRational myRational::operator++(int){
    myRational mr{realPart,imaginaryPart};
    ++realPart;
    return mr;
};
myRational myRational::operator--(){
    --realPart;
    return *this;
};
myRational myRational::operator--(int){
    myRational mr{realPart,imaginaryPart};
    --realPart;
    return mr;
};




ostream &operator << (ostream &os, const myRational& r){
    if(r._num == 0)
        os << 0;
    else if (r._den == 1)
        os << r._num;
    else 
        os << r._num << "/" << r._den << "\n";
    return os;
}
istream &operator >> (istream &is, myRational r){
    is >> r._num >> r._den;
    if(r._den == 0){
        r._num=0;
        r._den=1;
    }
    r.reduce();
    return is;
}







void testSimpleCase();
void testDataFromFile();
int main(){
    testSimpleCase();
    testDataFromFile();
    return 0;
}
void testSimpleCase(){
    myRational frac1(2), frac2(3, 2), frac3(6, 4), frac4(12, 8), frac5, frac6, frac7;
    cout << frac1 << " " << frac2 << " " << frac3 << " " << frac4 << " " << frac5 << "\n";
    cout << frac1.getNumerator() << " " << frac1.getDenominator() << "\n";
    // Check arithmetic operators
    cout << frac1 * frac2 << " "
        << frac1 + frac3 << " "
        << frac2 - frac1 << " "
        << frac3 / frac2 << "\n";
    // Check comparison operators
    cout << ((frac1 < frac2) ? 1 : 0) << " "
        << ((frac1 <= frac2) ? 1 : 0) << " "
        << ((frac1 > frac2) ? 1 : 0) << " "
        << ((frac1 >= frac2) ? 1 : 0) << " "
        << ((frac1 == frac2) ? 1 : 0) << " "
        << ((frac1 != frac2) ? 1 : 0) << " "
        << ((frac2 < frac3) ? 1 : 0) << " "
        << ((frac2 <= frac3) ? 1 : 0) << " "
        << ((frac2 > frac3) ? 1 : 0) << " "
        << ((frac2 >= frac3) ? 1 : 0) << " "
        << ((frac2 == frac3) ? 1 : 0) << " "
        << ((frac2 != frac3) ? 1 : 0) << "\n";
    cout << (frac6 = frac3) << " ";
    cout << (frac6 += frac3) << " ";
    cout << (frac6 -= frac3) << " ";
    cout << (frac6 *= frac3) << " ";
    cout << (frac6 /= frac3) << "\n";
    cout << -frac6 << "\n";
    frac6 = (++frac4) + 2;
    frac7 = 2 + (frac4++);
    cout << frac4 << " " << frac6 << " " << frac7 << "\n";
    frac6 = (--frac4) - 2;
    frac7 = 2 - (frac4--);
    cout << frac4 << " " << frac6 << " " << frac7 << "\n";
    cout << 2 * frac3 << " " << frac3 * 2 << " "
        << 2 / frac3 << " " << frac3 / 2 << endl;
};
void testDataFromFile(){

};