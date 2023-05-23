#include <iostream>
using namespace std;
class Shape{
public:
	Shape(){
		cout << this << "Shape::ctor" << endl;
	}
public:
	virtual void draw() const {
		cout << "Shape::draw()" << endl;
	}
public:
	double area;
};

class Rect : public Shape{
public:
	Rect(){
		cout << this << "Rect::ctor" << endl;
	}
public:
	void draw() const{
		cout << "Rect::draw()" << endl;
	}
	int width{};
	int height{};
};

int main(){
	Shape *rect = new Rect{};

	cout << "siazeof(Shape) = " << sizeof(Shape) << endl;
	cout << "sizeof(Rect) = " << sizeof(Rect) << endl;

	
	return 0;
}
