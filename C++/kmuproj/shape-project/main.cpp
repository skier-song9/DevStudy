#include "circle.hpp"
#include "rect.hpp"
#include "triangle.hpp"

#include <iostream>

int main(int argc, char *argv[]){
	std::cout << "project example" << "\n";

	Shape *rect = new Rect{};
	delete rect;

	Shape *circle = new Circle{};
	circle->draw();
	delete circle;

	Shape *triangle = new Triangle{};
	triangle->draw();
	delete triangle;

	return 0;
}
