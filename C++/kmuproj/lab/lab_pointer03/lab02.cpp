#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    
    int n=99;
    int *ptr = &n;

    cout << "n = " << n << endl; 
    cout << "&n = " << &n << endl;
    cout << "ptr = " << ptr << endl; //&n 값
    cout << "*ptr = " << *ptr << endl; // n값
    cout << "&ptr = " << &ptr << endl; // ptr의 주소s

    cout << "========================" << endl;
    int **pptr = &ptr;
    cout << "pptr = " << pptr << endl; // &ptr 값
    cout << "*pptr = " << *pptr << endl; // &n 값, ptr의 값
    cout << "**pptr = " << **pptr << endl; // n의 값

    cout << "========================" << endl;
    void **vpptr = (void **)&ptr;
    cout << "vpptr = " << vpptr << endl; // &ptr 값
    // cout << "**vpptr = " << **vpptr << endl; //[x] 
    cout << "**vpptr = " << **((int **)vpptr) << endl; // n의 값

    int *p = (int *)*vpptr;
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;
    // cout << "*vpptr = " << vpptr << endl;

    return 0;
}
