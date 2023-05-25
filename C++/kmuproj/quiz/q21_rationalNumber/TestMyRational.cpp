#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

class myRational{
private:
    // 분수는 항상 내부적으로 기약분수로 표현하며, 또한 항상 _den>0 이다.
    long _num; // numerator
    long _den; // denominator
public:
    //ctor
    myRational(long p=0,long q=1);
    myRational(const myRational& r);
    //getter/setter
    long gn() const;
    long gd() const;
    void sn(long n);
    void sd(long d);
    void set(long n, long d);
    long gcd(long m, long n); // 최대공약수
    void reduce();
    myRational reciprocal() const;
    // Overloaded binary operators
    myRational operator +(const myRational& mr) const;
    myRational operator +(int value) const;
    myRational operator -(const myRational& mr) const;
    myRational operator -(int value) const;
    myRational operator *(const myRational& mr) const;
    myRational operator *(int value) const;
    myRational operator /(const myRational& mr) const;
    myRational operator /(int value) const;
    // Assignment operators
    myRational& operator =(const myRational& mr);
    myRational& operator =(int value);
    myRational& operator +=(const myRational& mr);
    myRational& operator +=(int value);
    myRational& operator -=(const myRational& mr);
    myRational& operator -=(int value);
    myRational& operator *=(const myRational& mr);
    myRational& operator *=(int value);
    myRational& operator /=(const myRational& mr);
    myRational& operator /=(int value);
    // Overloading comparison operators
    bool operator ==(const myRational& mr) const;
    bool operator ==(int value) const;
    bool operator !=(const myRational& mr) const;
    bool operator !=(int value) const;
    bool operator >(const myRational& mr) const;
    bool operator >(int value) const;
    bool operator <(const myRational& mr) const;
    bool operator <(int value) const;
    bool operator >=(const myRational& mr) const;
    bool operator >=(int value) const;
    bool operator <=(const myRational& mr) const;
    bool operator <=(int value) const;
    // Overloaded unary operators
    myRational operator -(); 
    // myRational myRational::operator~();
    myRational operator++();
    myRational operator++(int);
    myRational operator--();
    myRational operator--(int);
};/////////////class

myRational::myRational(long p,long q)
    :_num(p),_den(q){ reduce(); };
myRational::myRational(const myRational& r){
    _num = r._num;
    _den = r._den;
    reduce();
};
long myRational::gn() const{ return _num; };
long myRational::gd() const{ return _den; };
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
    return myRational(_den,_num);
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
    long newNum = _num * mr._den - mr._num * _den;
    long newDen = _den * mr._den;
    return myRational(newNum,newDen);
}
myRational myRational::operator -(int value) const
{
    long newNum = _num - value * _den;
    long newDen = _den;
    return myRational(newNum,newDen);
}
myRational myRational::operator *(const myRational& mr) const
{
    long newNum = _num * mr._num;
    long newDen = _den * mr._den;
    return myRational(newNum,newDen);
}
myRational myRational::operator *(int value) const
{
    long newNum = _num * value;
    long newDen = _den;
    return myRational(newNum,newDen);
}
myRational myRational::operator /(const myRational& mr) const
{
    if (mr._num == 0) return myRational(0,1);
    return myRational(*this * mr.reciprocal());
}
myRational myRational::operator /(int value) const
{
    if (value == 0) return myRational(0,1);
    long newNum = _num;
    long newDen = _den * value;
    return myRational(newNum,newDen);
}
// Assignment operators
myRational& myRational::operator =(const myRational& mr)
{
    this->_num = mr._num;
    this->_den = mr._den;
    return *this;
}
myRational& myRational::operator =(int value)
{
    _num = value;
    _den = 1;
    return *this;
}
myRational& myRational::operator +=(const myRational& mr)
{
    long newNum = _num*mr._den + mr._num*_den;
    long newDen = _den * mr._den;
    *this=myRational(newNum,newDen);
    return *this;
}
myRational& myRational::operator +=(int value)
{
    long newNum = _num + value*_den;
    long newDen = _den;
    *this=myRational(newNum,newDen);
    return *this;
}
myRational& myRational::operator -=(const myRational& mr)
{
    long newNum = _num*mr._den - mr._num*_den;
    long newDen = _den * mr._den;
    *this=myRational(newNum,newDen);
    return *this;
}
myRational& myRational::operator -=(int value)
{
    long newNum = _num - value*_den;
    long newDen = _den;
    *this=myRational(newNum,newDen);
    return *this;
}
myRational& myRational::operator *=(const myRational& mr)
{
    long newNum = _num*mr._num;
    long newDen = _den*mr._den;
    *this=myRational(newNum,newDen);
    return *this;
}
myRational& myRational::operator *=(int value)
{
    long newNum = _num*value;
    long newDen = _den;
    *this=myRational(newNum,newDen);
    return *this;
}
myRational& myRational::operator /=(const myRational& mr)
{
    if (mr._num == 0) {*this = myRational(0,1);}
    else {*this= *this * mr.reciprocal();}
    return *this;
}
myRational& myRational::operator /=(int value)
{
    if (value == 0) {*this = myRational(0,1);}
    else{
        long newNum = _num;
        long newDen = _den*value;
        *this=myRational(newNum,newDen);
    }
    return *this;
}
// Overloading comparison operators
bool myRational::operator ==(const myRational& mr) const
{
    return (_num == mr._num) && 
    (_den == mr._den);
}
bool myRational::operator ==(int value) const
{
    return (_num == value) && 
    (_den == 1);
}
bool myRational::operator !=(const myRational& mr) const
{
    return !(*this == mr);
}
bool myRational::operator !=(int value) const
{
    return !(*this == value);
}
bool myRational::operator >(const myRational& mr) const
{
    return (_num*mr._den > mr._num*_den);
}
bool myRational::operator >(int value) const
{
    return (_num > value*_den);
}
bool myRational::operator <(const myRational& mr) const
{
    return (mr._num*_den > _num*mr._den);
}
bool myRational::operator <(int value) const
{
    return (value*_den > _num);
}
bool myRational::operator >=(const myRational& mr) const
{
    return !(mr._num*_den > _num*mr._den);
}
bool myRational::operator >=(int value) const
{
    return !(value*_den > _num);
}
bool myRational::operator <=(const myRational& mr) const
{
    return !(_num*mr._den > mr._num*_den);
}
bool myRational::operator <=(int value) const
{
    return !(_num > value*_den);
}
// Overloaded unary operators
myRational myRational::operator -() // unary minus
{
    return myRational(-_num, _den);
} 
// myRational myRational::operator~(){
//     return myRational(_num,-_den);
// }; 
myRational myRational::operator++(){
    *this += 1;
    return *this;
};
myRational myRational::operator++(int){
    myRational mr{_num,_den};
    *this += 1;
    return mr;
};
myRational myRational::operator--(){
    *this -= 1;
    return *this;
};
myRational myRational::operator--(int){
    myRational mr{_num,_den};
    *this -= 1;
    return mr;
};

ostream &operator << (ostream &os, const myRational& r){
    if(r.gn() == 0)
        os << 0;
    else if (r.gd() == 1)
        os << r.gn();
    else 
        os << r.gn() << "/" << r.gd();
    return os;
}
// istream &operator >> (istream &is, myRational r){
//     long a,b;
//     is >> a >> b;
//     r.set(a,b);
//     if(r.gd() == 0){
//         r.sn(0);
//         r.sd(1);
//     }
//     r.reduce();
//     return is;
// }


void testSimpleCase();
void testDataFromFile();
void quickSort(myRational *data, int start, int end);
int main(){
    testSimpleCase();
    testDataFromFile();
    return 0;
}
void testSimpleCase(){
    myRational frac1(2), frac2(3, 2), frac3(6, 4), frac4(12, 8), frac5, frac6, frac7;
    cout << frac1 << " " << frac2 << " " << frac3 << " " << frac4 << " " << frac5 << "\n";
    cout << frac1.gn() << " " << frac1.gd() << "\n";
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
    frac7 = (frac4++) + 2;
    cout << frac4 << " " << frac6 << " " << frac7 << "\n";
    frac6 = (--frac4) - 2;
    frac7 = -(frac4--);
    frac7 += 2;
    cout << frac4 << " " << frac6 << " " << frac7 << "\n";
    cout << frac3 * 2 << " " << frac3 * 2 << " "
        << frac3.reciprocal() * 2 << " " << frac3 / 2 << endl;
};
void testDataFromFile(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        myRational *arr = new myRational[n];
        for(int i{0}; i<n;i++){
            long a,b;
            cin >> a >> b;
            arr[i] = myRational(a,b);
        }
        quickSort(arr,0,n-1);
        for(int i{0}; i<n;i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        delete[] arr;
    }
};
void quickSort(myRational *data, int start, int end){
    // start = 정렬하는 부분집합의 시작 원소
	// end = 정렬하는 부분집합의 끝 원소
    if(start>=end){// 정렬할 집합의 원소가 1개인 경우 바로 return
        return;
    }
    int key = start; //키(피벗)는 해당 집합에서 첫번째 원소
    int i = start + 1;
    int j = end;
    myRational temp;

    while(i<=j){ // 피벗이 최대값이 될 때까지 반복한다.
        while(data[i] <= data[key] && i <= end) { //피벗보다 큰 값을 찾는다.
            i++;
        }
        while(data[j] >= data[key] && j > start) { //피벗보다 작은 값을 찾는다. 피벗이 최솟값이라면 key = j가 된다.
            j--;
        }
        if (i > j){ // i와 j가 엇갈렸다면 피벗이 집합 내에서 최대값 또는 최소값임.
            temp = data[j];
            data[j] = data[key];
            data[key] = temp;
        }
        else{ // 엇갈리지 않았다면 피벗이 집합 내에서 최소값이거나 아무것도 아님.
            //피벗이 최대값, 최소값이 아니라면 key < i < j
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }
    //스스로를 호출한다.
    quickSort(data,start,j-1);
    quickSort(data,j+1,end);
}