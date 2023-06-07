#include <iostream>
#include <list>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

class myPolynomial;

class myTerm
{
public:
    myTerm(int c = 0, unsigned e = 0);
    // copy constructor
    myTerm(const myTerm& term);

    // overloaded operators
    bool operator==(const myTerm& term) const;
    bool operator!=(const myTerm& term) const;
    bool operator<(const myTerm& term) const;
    myTerm operator-() const;

    // accessor functions
    int getCoeff() const { return coeff; }
    unsigned getExp() const { return exp; }

    // mutator functions
    void setCoeff(int c) { coeff = c; }
    void setExp(unsigned e) { exp = e; }

    // member functions
    myTerm ddx() const; // derivative of a term

    // friend functions and classes
    friend ostream& operator<<(ostream& outStream, const myTerm& term);
    friend class myPolynomial;

private:
    int coeff;      // integer coefficient
    unsigned exp;   // exponent (non-negative integer)
};


// Constructor
myTerm::myTerm(int c, unsigned e) : coeff(c), exp(e) {}

// copy constructor
myTerm::myTerm(const myTerm& term) : coeff(term.coeff), exp(term.exp) {}

// overloaded operators
bool myTerm::operator==(const myTerm& term) const {
    if (this->exp == term.exp && this->coeff == term.coeff) 
        return true;
    else
        return false;
}

// overloaded operators
bool myTerm::operator!=(const myTerm& term) const {
    if (this->exp != term.exp || this->coeff != term.coeff) 
        return true;
    else 
        return false;
}

// overloaded operators
bool myTerm::operator<(const myTerm& term) const
{
    return this->exp > term.exp;
}

myTerm myTerm::operator-() const {
    return myTerm(-(this->coeff), this->exp);
}

// derivative of a term
myTerm myTerm::ddx() const
{
    if (exp == 0)
        return myTerm(0, 0);
    return myTerm(exp * coeff, exp - 1);
}

// output operator
ostream& operator<<(ostream& outStream, const myTerm& term)
{
    if (term.exp == 0)
    {
        if (term.coeff == 0)
            return outStream;
        else
            return outStream << term.coeff;
    }

    if (term.coeff == 1)
        outStream << "x";
    else if (term.coeff == -1)
        outStream << "-x";
    else
        outStream << term.coeff << "x";

    if (term.exp == 1)
        return outStream;
    else
        return outStream << "^" << term.exp;
}

/*-----------------------------------------------------------------------------*/

class myPolynomial
{
public:
    myPolynomial(int c = 0, unsigned e = 0);
    myPolynomial(int nTerms, int mono[]);
    // copy constructor
    myPolynomial(const myPolynomial& poly);
    static int compare(myTerm& f, myTerm& l);
    // overloaded operators
    bool operator==(const myPolynomial& poly) const;
    bool operator!=(const myPolynomial& poly) const;
    myPolynomial& operator+=(const myPolynomial& poly);
    myPolynomial& operator-=(const myPolynomial& poly);
    myPolynomial& operator*=(const myPolynomial& poly);
    myPolynomial& operator*=(int k);

    myPolynomial operator-() const;
    myPolynomial operator*(int k) const;
    myPolynomial operator+(const myPolynomial& poly) const;
    myPolynomial operator-(const myPolynomial& poly) const;
    myPolynomial operator*(const myPolynomial& poly) const;

    long operator()(int x) const;                                   // evaluate the polynomial
    int getDegree() const { return degree; };                       // get the degree of the 
polynomial
    unsigned getNumTerms() const { return termList.size(); }        // get the 
number of terms in the polynomial
    myPolynomial ddx() const;                                       // derivative of a 
polynomial

    // friend operators and functions
    friend myPolynomial operator*(int k, const myPolynomial& poly);
    friend ostream& operator<<(ostream& outStream, const myPolynomial& 
poly);

    static const myPolynomial ZERO;
    static const myPolynomial ONE;
    static const myPolynomial X;

private:
    int degree;                 // maximum exponent
    list<myTerm> termList;      // list of terms
};

myPolynomial::myPolynomial(int c, unsigned e) 
{
    myTerm temp = myTerm(c, e);
    termList.clear();
    termList.push_front(temp);
    this->degree = e;
    this->termList.sort(compare);
}

myPolynomial::myPolynomial(int nTerms, int mono[])
{
    int range = nTerms;
    for (int i = 0; i < range; i++) {
        myTerm temp = myTerm(mono[2*i], mono[2*i+1]);
        termList.push_front(temp);
    }
    this->termList.sort(compare);
    this->degree = this->termList.front().exp;

}

myPolynomial::myPolynomial(const myPolynomial& poly)
{
    this->degree = poly.degree;
    this->termList = poly.termList;
}

// compare operator

int myPolynomial::compare(myTerm& f, myTerm& l)
{
    if (f.exp > l.exp)
        return 1;
    else 
        return 0;
}

bool myPolynomial::operator ==(const myPolynomial& poly) const 
{   
    if(this->degree != poly.degree) 
    return false;
    else {
        bool flag = true;
        list<myTerm>::const_iterator it1 = this->termList.begin();
        list<myTerm>::const_iterator it2 = poly.termList.begin();

        for(it1; it1 != this->termList.end(); it1++) {
            if ((*it1) != (*it2)) {
                flag = false;
                it2++;
                break;
            }
        }
        return flag;
    }
    
}

bool myPolynomial::operator !=(const myPolynomial& poly) const 
{   
    if (this->termList == poly.termList)
        return false;
    else
        return true;
}

myPolynomial myPolynomial::operator +(const myPolynomial& poly) const 
{
myPolynomial result;
result.termList.clear();
list<myTerm>::const_iterator it1 = this->termList.begin();
list<myTerm>::const_iterator it2 = poly.termList.begin();

while (it1 != this->termList.end() && it2 != poly.termList.end()) {
        if (it1->exp == it2->exp) {
            if (it1->coeff + it2->coeff != 0)
                result.termList.push_back(myTerm(it1->coeff + it2->coeff, it1->exp));
            it1++;
            it2++;
        }
        else if (it1->exp < it2->exp) {
            result.termList.push_back(*it2);
            it2++;
        }
        else {
            result.termList.push_back(*it1);
            it1++;
        }
}
if (it1 != this->termList.end()) {
    for (it1; it1 != this->termList.end(); it1++) {
        result.termList.push_back(*it1);
    }
}
else {
    for (it2; it2 != poly.termList.end(); it2++) {
        result.termList.push_back(*it2);
    }
}
result.termList.sort(compare);
result.degree = result.termList.front().exp;
return result;


}

myPolynomial myPolynomial::operator -(const myPolynomial& poly) const 
{
    myPolynomial temp;
    temp = *this + -(poly);
    return temp;
}

myPolynomial myPolynomial::operator *(const myPolynomial& poly) const 
{
    list<myTerm> temp;
    myPolynomial result;
    set<int> set;
    result.termList.clear();
    list<myTerm>::const_iterator itt;
    list<myTerm>::const_iterator itp;
    for (itt = this->termList.begin(); itt != this->termList.end(); itt++) {
        for (itp = poly.termList.begin(); itp != poly.termList.end(); itp++) {
            temp.push_back(myTerm(itt->coeff*itp->coeff, itt->exp + itp->exp));
        }
    }
    list<myTerm>::const_iterator it2;
    for (it2 = temp.begin(); it2 != temp.end(); it2++) {
        if (it2->coeff != 0) {
            int exp = it2->exp;
            if (set.count(exp) == 0) {
                set.insert(exp);
                result.termList.push_back(myTerm(*it2));
            }
            else {
                list<myTerm>::const_iterator iit;
                for (iit = result.termList.begin(); iit != result.termList.end(); iit++) {
                    if (iit->exp == exp) {
                        if (it2->coeff + iit->coeff == 0) {
                            set.erase(exp);
                            result.termList.erase(iit);
                        }
                        else {
                            myTerm tempTerm = myTerm(it2->coeff + iit->coeff, it2-
>coeff);
                            iit = result.termList.erase(iit);
                            result.termList.insert(iit, tempTerm);
                        }
                        break;
                    }
                    
                }
            }
        }
        
    }
    result.termList.sort(compare);
    result.degree = result.termList.front().exp;
    return result;
}

myPolynomial myPolynomial::operator* (const int n) const
{
    list<myTerm>::const_iterator it = this->termList.begin();
    myPolynomial result;
    result.termList.clear();
    if (n == 0) {
        result.degree = 0;
        return myPolynomial::ZERO;
    }
    else {
        result.degree = this->degree;
        for (it; it != this->termList.end(); it++) {
            result.termList.push_front(myTerm((it->coeff)*n, it->exp));
        }
        result.termList.sort(compare);
        result.degree = result.termList.front().exp;
        return result;
    }
        
}

// double operator

myPolynomial& myPolynomial::operator+=(const myPolynomial& poly)
{
    *this = *this + poly;
    return *this;
}

myPolynomial& myPolynomial::operator-=(const myPolynomial& poly)
{
    *this = *this - poly;
    return *this;
}

myPolynomial& myPolynomial::operator*=(const myPolynomial& poly)
{
    *this = *this * poly;
    return *this;
}

myPolynomial& myPolynomial::operator*=(const int n)
{
    *this = *this * n;
    return *this;
}


// output operator
ostream& operator<<(ostream& outStream, const myPolynomial& poly)
{
    if (poly == myPolynomial::ZERO)
        return outStream << 0;

    else if (poly.termList.size() == 1) 
        return outStream << poly.termList.front();
        
    else {
        list<myTerm>::const_iterator it;
        for (it = poly.termList.begin(); it != poly.termList.end(); it++) {
            if (it == poly.termList.begin())
                outStream << *it;
            else {
                if (it->getCoeff() > 0)
                    outStream << "+" << *it;
                else 
                    outStream << *it;
            }
        }
        return outStream;
        }
}

//  friend multiply operator

myPolynomial operator*(int k, const myPolynomial& poly) 
{
    return poly * k;
}

//  insert value function
long myPolynomial::operator()(int x) const
{
    long sum = 0;
    list<myTerm>::const_iterator it = this->termList.begin();
    for (it; it != this->termList.end(); it++) {
        sum += it->coeff * pow(x, it->exp);
    }
    return sum;
}
//  menber function

myPolynomial myPolynomial::ddx() const 
{
    myPolynomial temp;
    temp.termList.clear();
    if (this->degree > 0) {
        temp.degree = this->degree-1;
        list<myTerm>::const_iterator it;
        for (it = this->termList.begin(); it != this->termList.end(); it++) {
            temp.termList.push_front(it->ddx());
        }
        temp.termList.sort(compare);
        return temp;
    }
    else 
        return myPolynomial::ZERO;
}

myPolynomial myPolynomial::operator -() const
{
    myPolynomial Rlist;
    Rlist.termList.clear();
    list<myTerm>::const_iterator it;
    if (this->termList.size() == 1) 
        return myPolynomial(-this->termList.front().coeff, this-
>termList.front().exp); 
    else {
        for (it = this->termList.begin(); it != this->termList.end(); it++) {
            myTerm temp = myTerm(-(it->coeff), it->exp);
            Rlist.termList.push_front(temp);
        }
        Rlist.degree = this->degree;
        Rlist.termList.sort(compare);
        return Rlist;
    }
    
}

const myPolynomial myPolynomial::ZERO(0);                  // the zero polynomial 
P(x) = 0
const myPolynomial myPolynomial::ONE(1, (unsigned)0);      // the monomial 
P(x) = 1
const myPolynomial myPolynomial::X(1, 1);                  // the monomial P(x) = x

/*-----------------------------------------------------------------------------*/

void testSimpleCase();
void testDataFromFile();

int main(void)
{
    testSimpleCase();
    testDataFromFile();
    return 0;
}

void testSimpleCase()
{
    // test static variables
    cout << myPolynomial::ZERO << endl;
    cout << myPolynomial::ONE << endl;
    cout << myPolynomial::X << endl;

    myPolynomial p0, p1(1), p2(1, 1), p3(3, 5);
    int testData4[10] = {1, 0, 1, 1, 1, 2, 1, 3, 1, 4};
    int testData5[10] = {-1, 0, -1, 1, -1, 2, -1, 3, -1, 4};
    int testData6[10] = {1, 0, -1, 1, 1, 2, -1, 3, 1, 4};
    int testData7[10] = {2, 2, 5, 5, 4, 4, 1, 1, 3, 3};
    int testData8[12] = {1, 1000000000, 1, 100000000, 1, 1000000, 1, 10000, 1, 
100, 1, 0};

    myPolynomial p4(5, testData4);
    myPolynomial p5(5, testData5);
    myPolynomial p6(5, testData6);
    myPolynomial p7(5, testData7);
    myPolynomial p8(6, testData8);
    myPolynomial p9(p7);

    // test constructor
    cout << p0 << endl << p1 << endl << p2 << endl;
    cout << p4 << endl << p8 << endl;
    // test copy constructor
    cout << p9 << endl;
    // test accessor function
    cout << p8.getDegree() << " " << p8.getNumTerms() << endl;
    // test evaluation function
    cout << p1(2) << " " << p2(2) << " " << p3(2) << " " << p4(2) << " " << endl;
    cout << p5(3) << " " << p6(3) << " " << p7(3) << " " << p9(3) << " " << endl;
    // test comparison operators
    cout << (p7 == p9) << " " << (p7 != p9) << endl;
    // test derivative function
    cout << myPolynomial::ZERO.ddx() << endl;
    cout << myPolynomial::ONE.ddx() << endl;
    cout << myPolynomial::X.ddx() << endl;
    cout << p4.ddx() << endl;
    cout << p8.ddx() << endl;
    // test unary operator -
    cout << -myPolynomial::ZERO << endl;
    cout << -p4 << endl;
    // test k*p(x) or p(x) * k
    cout << 3 * myPolynomial::ZERO << endl;
    cout << 3 * myPolynomial::ONE << endl;
    cout << myPolynomial::X * 3 << endl;
    cout << 3 * p4 << " " << p4 * 3 << endl;
    cout << 0 * p5 << " " << p5 * 5 << endl;
    // test binary operator +
    cout << p4 + p5 << endl << p6 - p7 << endl;
    cout << p8 * p7 << endl;

}

void testDataFromFile()
{
    int numTestCases;
    cin >> numTestCases;

    for (int i = 0; i < numTestCases; i++)
    {
        int numTerms, terms[100];

        /* read first polynomial */
        cin >> numTerms;

        for (int j = 0; j < numTerms; j++)
            cin >> terms[2 * j] >> terms[2 * j + 1];

        myPolynomial p1(numTerms, terms);

        /* read second polynomial */
        cin >> numTerms;

        for (int j = 0; j < numTerms; j++)
            cin >> terms[2 * j] >> terms[2 * j + 1];

        myPolynomial p2(numTerms, terms);

        cout << p1 << endl << p2 << endl;
        cout << p1.getDegree() << " " << p2.getNumTerms() << endl;
        cout << p1.ddx() << endl << p2.ddx() << endl;
        cout << (p1 == p2) << " " << (p1 != p2) << endl;
        cout << p1(1) << endl;
        cout << -p1 + p1 * 2 * p2 - p2 * 2 + 3 * p1 << endl;

        myPolynomial p3(myPolynomial::ZERO), p4(myPolynomial::ONE), 
p5(myPolynomial::X);
        p3 += p1;
        p4 -= p2;
        p5 *= p4;
        p5 *= 2;
        cout << p5 << endl;
    }
}
