#include <iostream>
#include <cmath>
using namespace std;

class MyPoint{
private:
    int x{};
    int y{};
public:
    //ctor
    MyPoint ();
    MyPoint (int x,int y);
    MyPoint (const MyPoint& p);
    //getter/setter
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
    void set(int x,int y);

    //comparison operators
    bool operator== (const MyPoint& p) const;
    bool operator!= (const MyPoint& p) const;

    //util
    //직선거리 sqrt((x1-x2)^2 + (y1-y2)^2)
    int dist2sqr(const MyPoint& p) const ;
    //직각거리 |x1-x2| + |y1-y2|
    int dist1(const MyPoint& p) const;
};

//ctor
MyPoint::MyPoint ()
:x(0),y(0){};
MyPoint::MyPoint (int x,int y)
    :x(x),y(y){};
MyPoint::MyPoint (const MyPoint& p)
    :x(p.x),y(p.y){};
//getter/setter
int MyPoint::getX() const {
    return x;
}
int MyPoint::getY() const {
    return y;
}
void MyPoint::setX(int x){
    this->x = x;
}
void MyPoint::setY(int y){
    this->y = y;
}
void MyPoint::set(int x,int y){
    this->x = x;
    this->y = y;
}
//comparison operators
bool MyPoint::operator== (const MyPoint& p) const{
    return ((x == p.x) == (y == p.y));
}
bool MyPoint::operator!= (const MyPoint& p) const{
    return !(*this == p);
}
//util
//직선거리 sqrt((x1-x2)^2 + (y1-y2)^2)
int MyPoint::dist2sqr(const MyPoint& p) const {
    return int(pow(double(x-p.getX()),2) + pow(double(y-p.getY()),2));
}
//직각거리 |x1-x2| + |y1-y2|
int MyPoint::dist1(const MyPoint& p) const{
    return abs(x-p.getX()) + abs(y-p.getY());
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int x,y;
        cin >> x >> y;
        MyPoint p1(x,y);
        cin >> x >> y;
        MyPoint p2(x,y);

        if(p1 == p2) 
            cout << "1" << " ";
        if(p1 != p2)
            cout << "0" << " ";
        cout << p1.dist2sqr(p2) << " " << p1.dist1(p2) << " ";
        x = p1.getY();
        y = p1.getX();

        MyPoint p3(p1);
        p3.setX(y);
        p3.setY(x);

        cout << p1.dist2sqr(p3) << " " << p1.dist1(p3) << endl;

    }
    return 0;
}