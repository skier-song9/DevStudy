#include <iostream>

using namespace std;

class myRational{
private:
    // 분수는 항상 내부적으로 기약분수로 표현하며, 또한 항상 _den>0 이다.
    long _num; // numerator
    long _den; // denominator
public:
    //ctor
    myRational();
    myRational(int p=0,int q=1);
    myRational(const myRational& r);
    //getter/setter
    long getNum();
    long getDen();
    void setNum(long n);
    void setDen(long d);
    void set(long n, long d);
    //operator overloading
    long gcd(long m, long n); // 최대공약수
    void reduce();
};

myRational::myRational()
    :_num(0),_den(0){};
myRational::myRational(int p=0,int q=0)
    :_num(p),_den(q){};
myRational::myRational(const myRational& r){
    _num = r._num;
    _den = r._den;
};
long myRational::getNum(){ return _num; };
long myRational::getDen(){ return _den; };
void myRational::setNum(long n){ _num = n; };
void myRational::setDen(long d){ _den = d; };
void myRational::set(long n, long d){
    _num = n;
    _den = d;
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