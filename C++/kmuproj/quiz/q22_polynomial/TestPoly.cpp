#include <iostream>

using namespace std;
class myPolynomial{
public:
    myPolynomial(int c = 0, unsigned e = 0);
    myPolynomial(int nTerms, int mono[]);
    // copy constructor
    myPolynomial(const myPolynomial &poly);
    // overloaded operators
    bool operator == (const myPolynomial &poly) const;
    bool operator != (const myPolynomial &poly) const;
    myPolynomial& operator += (const myPolynomial &poly);
    myPolynomial& operator -= (const myPolynomial &poly);
    myPolynomial& operator *= (const myPolynomial &poly);
    myPolynomial& operator *= (int k);
    myPolynomial operator -() const;
    myPolynomial operator *(int k) const;
    myPolynomial operator +(const myPolynomial &poly) const;
    myPolynomial operator -(const myPolynomial &poly) const;
    myPolynomial operator *(const myPolynomial &poly) const;
    long operator() (int x) const; // evaluate the polynomial
    int getDegree() const; // get a degree of the polynomial
    unsigned getNumTerms() const; // number of terms in the polynomial
    myPolynomial ddx() const; // derivative of a polynomial
    // friend operators and functions
    friend myPolynomial operator *(int k, const myPolynomial &poly);
    friend ostream& operator <<(ostream &outStream, const myPolynomial &poly);
    static const myPolynomial ZERO; // P(x) = 0
    static const myPolynomial ONE; // P(x) = 1
    static const myPolynomial X; // P(x) = x
private:
    int degree; // maximum expnent
};

class myTerm
{
public:
    myTerm(int c = 0, unsigned e = 0);
    // copy constructor
    myTerm(const myTerm &term);
    // overloaded operators
    bool operator == (const myTerm& term) const;
    bool operator != (const myTerm& term) const;
    bool operator < (const myTerm& term) const;
    myTerm operator - () const;
    // accessor functions
    int getCoeff() const { return coeff; }
    unsigned getExp() const { return exp; }
    // mutator functions
    void setCoeff(int c) { coeff = c; }
    void setExp(unsigned e) { exp = e; }
    // member functions
    myTerm ddx() const; // derivative of a term
    // friend functions and classes
    friend ostream& operator <<(ostream &outStream, const myTerm& term);
    friend myPolynomial;
private:
    int coeff; // integer coefficient
    unsigned exp; // exponent (non-negative integer)
};
myTerm::myTerm(int c, unsigned e)
    :coeff(c),exp(e){};
// copy constructor
myTerm::myTerm(const myTerm &term){
    coeff = term.coeff;
    exp = term.exp;
};
// overloaded operators
bool myTerm::operator == (const myTerm& term) const{};
bool myTerm::operator != (const myTerm& term) const{};
bool myTerm::operator < (const myTerm& term) const{};
myTerm myTerm::operator - () const{};
// member functions
myTerm myTerm::ddx() const{}; // derivative of a term
// friend functions and classes
ostream& operator <<(ostream &outStream, const myTerm& term){};