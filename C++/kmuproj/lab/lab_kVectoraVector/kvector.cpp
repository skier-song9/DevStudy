#include "kvector.hpp"
#include <iostream>

Kvector::Kvector(int const size,int const value){
	if(size <=0) return;

	std::cout << this << "Kvector (int,int)" << "\n";

	m=new int[size]{};
	for (int i{};i<size;i++){
		m[i] = value;
	}	
	len = size;
}
Kvector::~Kvector(){
	if(m){
		delete[] m;
	}
	m=nullptr;
	len=0;
}

void Kvector::clear(){
	if(m){
		delete[] m;
	}
	m=nullptr;
	len=0;
}
void Kvector::print() const{
	if(!m) return;
	
	for (int i = 0; i < len; i++)
	{
		std::cout << m[i]<<" ";
	}
	std::cout << "\n";
}
int Kvector::size() const{return len;}
