#include <iostream>
using namespace std;
int main(){
	int a,b;
	int diff{};
	cin >> a;
	for(int i{};i<7;i++){
		cin >> b;
		if(i>=1 && diff!=(b-a)){
			cout << "mixed" << "\n";
			return 0;
		}
		diff = b-a;
		a = b;
	}
	if (diff==1){cout << "ascending" << "\n";}
	else {cout << "descending" << "\n";}
	return 0;
}
