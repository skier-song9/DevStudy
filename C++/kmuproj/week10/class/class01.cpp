#include <iostream>
#include <string>
using namespace std;

class Car {
public:
    // 멤버 변수 선언
    int speed;
    int gear;
    string color;

    void speedUp(){
        speed += 10;
    }
    void speedDown(){
        speed -= 10;
    }
};

Car globalCar;
int main(int argc, char const *argv[])
{
    Car localCar;

    globalCar.speed=100;
    localCar.speed=60;
    localCar.color = "white";

    cout << "현재 global 차의 속도는 " << globalCar.speed << endl;
    cout << "현재 local 차의 속도는 " << localCar.speed << endl;

    return 0;
}
