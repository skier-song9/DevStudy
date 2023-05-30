#include <iostream>
#include <list>

using namespace std;
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
    myTerm& operator = (const myTerm &term);
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
    friend class myPolynomial;
private:
    int coeff; // integer coefficient
    unsigned exp; // exponent (non-negative integer)
};
class myPolynomial{
public:
    myPolynomial(int c = 0, unsigned e = 0);
    myPolynomial(int nTerms, int mono[]);
    // copy constructor
    myPolynomial(const myPolynomial &poly);
    // overloaded operators
    bool operator == (myPolynomial &poly) const;
    bool operator != (const myPolynomial &poly) const;
    myPolynomial& operator = (const myPolynomial &poly);
    myPolynomial& operator += (const myPolynomial &poly);
    myPolynomial& operator -= (const myPolynomial &poly);
    myPolynomial& operator *= (const myPolynomial &poly);
    myPolynomial& operator *= (int k);
    myPolynomial operator -() const;
    myPolynomial operator *(int k) const;
    myPolynomial operator +(const myPolynomial &poly) const;
    myPolynomial operator -(const myPolynomial &poly) const;
    myPolynomial operator *(const myPolynomial &poly) const;
    myPolynomial reduce() const;
    long operator() (int x) const; // evaluate the polynomial
    int getDegree() const; // get a degree of the polynomial
    unsigned getNumTerms() const; // number of terms in the polynomial
    // void setCoeff(int c);
    void quickSort();
    myPolynomial ddx() const; // derivative of a polynomial
    // friend operators and functions
    friend myPolynomial operator *(int k, const myPolynomial &poly);
    friend ostream& operator <<(ostream &outStream, const myPolynomial &poly);
    static const myPolynomial ZERO; // P(x) = 0
    static const myPolynomial ONE; // P(x) = 1
    static const myPolynomial X; // P(x) = x
private:
    int degree; // maximum expnent
public:
    list<myTerm> terms;
};

///////////////////////////////////////////////////
myPolynomial::myPolynomial(int c , unsigned e){
    terms.push_back(myTerm(c,e));
};
myPolynomial::myPolynomial(int nTerms, int mono[]){
    for(int i=0;i<nTerms*2;i+=2){
        terms.push_back(myTerm(mono[i],mono[i+1]));
    }
};
// copy constructor
myPolynomial::myPolynomial(const myPolynomial &poly){
    terms = poly.terms;
};
// overloaded operators
bool myPolynomial::operator == (myPolynomial &poly) const{
    *this = reduce();
    quickSort();
    poly.reduce();
    poly.quickSort();
    for(auto& e:*this->terms){
        for(auto& pe:poly.terms){
            if(e != pe) return false;
        }
    }
    return true;
};
bool myPolynomial::operator != (const myPolynomial &poly) const{
    return !(*this == poly);
};
myPolynomial& myPolynomial::operator = (const myPolynomial &poly){
    *this->terms = poly.terms;
    return *this;
};
myPolynomial& myPolynomial::operator += (const myPolynomial &poly){
    return *this + poly;
};
myPolynomial& myPolynomial::operator -= (const myPolynomial &poly){
    return *this - poly;
};
myPolynomial& myPolynomial::operator *= (const myPolynomial &poly){
    return *this * poly;
};
myPolynomial& myPolynomial::operator *= (int k){
    return *this * k;
};
myPolynomial myPolynomial::operator -() const{
    for (auto& e:terms){
        e = -e;
    }
    return *this;
};
myPolynomial myPolynomial::operator *(int k) const{
    for (auto& e:terms){
        e.setCoeff(e.getCoeff()*k);
    }
    return *this;
};
myPolynomial myPolynomial::operator +(const myPolynomial &poly) const{
    for(auto& e:poly.terms){
        terms.push_back(e);
    }
    return *this->reduce();
    // myPolynomial temp;
    // for(auto& e:terms){
    //     for(auto& pe:poly.terms){
    //         if(e.exp == pe.exp){
    //             temp.terms.push_back(myTerm(e.coeff + pe.exp,e.exp));
    //         }
    //     }
    // }
    // return temp;
};
myPolynomial myPolynomial::operator -(const myPolynomial &poly) const{
    for(auto& e:poly.terms){
        terms.push_back(-e);
    }
    return *this->reduce();
};
myPolynomial myPolynomial::operator *(const myPolynomial &poly) const{
    list<myTerm> temp;
    for(auto& e:terms){
        for(auto& pe:poly.terms){
            temp.push_back(myTerm((e.coeff*pe.coeff),(e.exp+pe.coeff)));
        }
    }
    *this->terms = temp;
    return *this->reduce();
};
myPolynomial myPolynomial::reduce() const{
    myPolynomial copyPoly(*this);
    list<myTerm>::iterator iter = copyPoly.terms.begin();
    list<myTerm> newp;
    while(iter!=copyPoly.terms.end()){
        myTerm element = *iter;
        myTerm temp_e{element};
        for(++iter; iter!=copyPoly.terms.end(); iter++){
            if(element.exp == (*iter).exp){
                temp_e.setCoeff(temp_e.coeff+(*iter).coeff);
                iter = copyPoly.terms.erase(iter);
                iter--;
            }
        }
        newp.push_back(temp_e);
        iter = copyPoly.terms.begin();
    }
    copyPoly.terms = newp;
    return copyPoly;
}
long myPolynomial::operator() (int x) const{}; // evaluate the polynomial
int myPolynomial::getDegree() const{
    int maxD{};
    for(list<myTerm>::iterator iter = terms.begin();iter!=terms.end();iter++){
        if(maxD < (*iter).exp) {maxD = (*iter).exp;}
    }
}; // get a degree of the polynomial
unsigned myPolynomial::getNumTerms() const{
    return terms.size();
}; // number of terms in the polynomial
// void myPolynomial::setCoeff(int c){
//     for(auto& e:terms){
//         e.setCoeff()
//     }
// };
myPolynomial myPolynomial::ddx() const{
    myPolynomial temp = myPolynomial(*this);
    for(auto& e:temp.terms){
        e = e.ddx();
    }
    return temp;
}; // derivative of a polynomial
// friend operators and functions
friend myPolynomial myPolynomial::operator *(int k, const myPolynomial &poly){};
friend ostream& myPolynomial::operator <<(ostream &outStream, const myPolynomial &poly){
    poly.reduce();
    poly.quickSort();
    for(auto& e:poly.terms){
        os << e;
    }
    return os;
};
static const myPolynomial::myPolynomial ZERO = 0; // P(x) = 0
static const myPolynomial::myPolynomial ONE = 1; // P(x) = 1
static const myPolynomial::myPolynomial X; // P(x) = x
///////////////////////////////////////////////////
myTerm::myTerm(int c, unsigned e)
    :coeff(c),exp(e){};
// copy constructor
myTerm::myTerm(const myTerm &term){
    coeff = term.coeff;
    exp = term.exp;
};
// overloaded operators
bool myTerm::operator == (const myTerm& term) const{
    return (coeff==term.coeff) && (exp==term.exp);
};
bool myTerm::operator != (const myTerm& term) const{
    return !(*this == term);
};
bool myTerm::operator < (const myTerm& term) const{
    if (exp == term.exp){
        return coeff < term.coeff;
    }
    return exp > term.exp;
};
myTerm myTerm::operator - () const{
    return myTerm(-coeff,exp);
};
myTerm& myTerm::operator = (const myTerm &term){
    *this->coeff = term.coeff;
    *this->exp = term.exp;
    return *this;
};
// member functions
myTerm myTerm::ddx() const{
    if(exp == 0) return myTerm(0,0);
    return myTerm(exp*coeff,exp-1);
}; // derivative of a term
// friend functions and classes
ostream& operator <<(ostream &outStream, const myTerm& term){

    if(term.getCoeff() == 1 && term.getExp()!=0){ 
        os << "x^" << term.getExp();
    }
    else if(term.getCoeff()==0){ return os; }
    else if(term.getExp()==0){ 
        os << term.getCoeff();
    }
    else{
        os << term.getCoeff() << "x^" << term.getExp();
    }
    return os;
};
void myPolynomial::quickSort(){
    int start = 0;
    int end = (*this).terms.size()-1;
    // start = 정렬하는 부분집합의 시작 원소 index
	// end = 정렬하는 부분집합의 끝 원소 index
    if(start>=end){// 정렬할 집합의 원소가 1개인 경우 바로 return
        return;
    }
    int key = start; //키(피벗)는 해당 집합에서 첫번째 원소
    int i = start + 1;
    int j = end;
    myPolynomial temp;

    list<myTerm> dt = *this->terms;
    list<myTerm>::iterator iter = dt.begin();

    while(i<=j){
        while(true){
            advance(iter,i);
            unsigned data_i = (*iter).getExp();
            advance(iter,key);
            unsigned data_key = (*iter).getExp();
            if(data_i <= data_key && i <= end) {
                i++;
                continue;            
            }
            break;
        }
        while(true){
            advance(iter,j);
            unsigned data_j = (*iter).getExp();
            advance(iter,key);
            unsigned data_key = (*iter).getExp();
            if(data_j >= data_key && j > start) {
                j--;
                continue;            
            }
            break;
        }
        if(i>j){
            list<myTerm>::iterator it_key = next(dt.begin(),key);
            list<myTerm>::iterator it_j = next(dt.begin(),j);
            iter_swap(it_j,it_key);
        }
        else{
            list<myTerm>::iterator it_i = next(dt.begin(),i);
            list<myTerm>::iterator it_j = next(dt.begin(),j);
            iter_swap(it_j,it_i);
        }
    }

    quickSort(data,start,j-1);
    quickSort(data,j+1,end);
}
//////////////////////////////////////////////////////////////
void testSimpleCase();
void testDataFromFile();
int main(){
    testSimpleCase();
    testDataFromFile();
    return 0;
}
void testSimpleCase(){
    // test static variables
    cout << myPolynomial::ZERO << "\n"; //0
    cout << myPolynomial::ONE << "\n";//1
    cout << myPolynomial::X << "\n"; //x
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
    cout << p0 << "\n" << p1 << "\n" << p2 << "\n"; 
    //0
    //1
    //x
    cout << p4 << "\n" << p8 << "\n";
    /*
    x^4+x^3+x^2+x+1
    x^1000000000+x^100000000+x^1000000+x^10000+x^100+1
    */
    // test copy constructor
    cout << p9 << "\n"; // 5x^5+4x^4+3x^3+2x^2+x
    // test accessor function
    cout << p8.getDegree() << " " << p8.getNumTerms() << "\n"; // 1000000000 6
    // test evaluation function
    cout << p1(2) << " " << p2(2) << " " << p3(2) << " " << p4(2) << " " << "\n";// 1 2 96 31
    cout << p5(3) << " " << p6(3) << " " << p7(3) << " " << p9(3) << " " << "\n";// -121 61 1641 1641
    // test comparison operators
    cout << (p7 == p9) << " " << (p7 != p9) << "\n"; // 1 0
    // test derivative function
    cout << myPolynomial::ZERO.ddx() << "\n"; // 0
    cout << myPolynomial::ONE.ddx() << "\n"; // 0 
    cout << myPolynomial::X.ddx() << "\n"; // 1 
    cout << p4.ddx() << "\n"; // 4x^3+3x^2+2x+1
    cout << p8.ddx() << "\n"; // 1000000000x^999999999+100000000x^99999999+1000000x^999999+10000x^9999+100x^99
    // test unary operator -
    cout << -myPolynomial::ZERO << "\n"; // 0
    cout << -p4 << "\n"; // -x^4-x^3-x^2-x-1
    // test k*p(x) or p(x) * k
    cout << 3*myPolynomial::ZERO << "\n"; //0
    cout << 3*myPolynomial::ONE << "\n"; //3
    cout << myPolynomial::X*3 << "\n"; //3x
    cout << 3*p4 << " " << p4*3 << "\n"; //3x^4+3x^3+3x^2+3x+3 3x^4+3x^3+3x^2+3x+3
    cout << 0*p5 << " " << p5*5 << "\n"; //0 -5x^4-5x^3-5x^2-5x-5
    // test binary operator +
    // cout << p4 + p5 << " " << p4 + p6 << "\n";
    // cout << p4 + p8 << " " << p8 + p8 << "\n";
    cout << p4 + p5 << "\n" << p6 - p7 << "\n"; 
    // 0
    // -5x^5-3x^4-4x^3-x^2-2x+1
    cout << p8 * p7 << "\n"; /* 5x^1000000005+4x^1000000004+3x^1000000003+2x^1000000002+x^1000000001+5x^100000005+4x^10
0000004+3x^100000003+2x^100000002+x^100000001+5x^1000005+4x^1000004+3x^1000003+2x^10000
02+x^1000001+5x^10005+4x^10004+3x^10003+2x^10002+x^10001+5x^105+4x^104+3x^103+2x^102+x^
101+5x^5+4x^4+3x^3+2x^2+x */
    // test binary operator -
    cout << p4 - p5 << " " << p4 - p6 << "\n"; // 0
    cout << p4 - p8 << " " << p8 - p8 << "\n"; // 
    // test binary operator *
    cout << p4 * p5 << " " << p4 * p6 << "\n";
    cout << p4 * p8 << " " << p8 * p8 << "\n";
    myPolynomial tmp1(p4), tmp2, tmp3, tmp4;
    tmp4 = tmp3 = tmp2 = tmp1;
    cout << (tmp1 += p5) << "\n";
    cout << (tmp2 -= p5) << "\n";
    cout << (tmp3 *= p5) << "\n";
    cout << (tmp4 *= 3) << endl;
};
void testDataFromFile(){
    int t;
    cin >> t;
    while (t--)
    {
        int numTerms, terms[100];
        /* read first polynomial */
        cin >> numTerms;
        for (int j=0; j<numTerms; j++)
            cin >> terms[2*j] >> terms[2*j+1];
        myPolynomial p1(numTerms, terms);
        /* read second polynomial */
        cin >> numTerms;
        for (int j=0; j<numTerms; j++)
            cin >> terms[2*j] >> terms[2*j+1];
        myPolynomial p2(numTerms, terms);
        cout << p1 << "\n" << p2 << "\n";
        cout << p1.getDegree() << " " << p2.getNumTerms() << "\n";
        cout << p1.ddx() << "\n" << p2.ddx() << "\n";
        cout << (p1 == p2) << " " << (p1 != p2) << "\n";
        cout << p1(1) << "\n";
        cout << -p1 + p1 * 2 * p2 - p2 * 2 + 3 * p1 << "\n";
        myPolynomial p3(myPolynomial::ZERO), p4(myPolynomial::ONE),
        p5(myPolynomial::X);
        p3 += p1;
        p4 -= p2;
        p5 *= p4;
        p5 *= 2;
        cout << p5 << endl;
    }
};
