#include "shape.hpp"
#include <iostream>
Shape::~Shape(){
	std::cout << "Shape::dtor()" << "\n";
}
void Shape::draw() const {
	std::cout << "Shape::draw()" << "\n";
}
