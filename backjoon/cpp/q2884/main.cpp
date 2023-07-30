#include <iostream>
using namespace std;
int main(){
	int h,m;
	cin >> h >> m;
	bool minusH{false};
	if(m < 45){
		m = 60 - (45 - m);
		minusH = true;
	}
	else{
		m -= 45;
	}
	h = minusH ? (h==0 ? 23 : h-1) : h ;
	cout << h << " " << m << "\n";
	return 0;
}
