#include <iostream>
using namespace std;
int main(){
	int t,n;
	cin >> t;
	int minmax[2]{};
	cin >> minmax[0];
	minmax[1] = minmax[0];
	for(int i=1;i<t;i++){
		cin >> n;
		if(minmax[0] > n) minmax[0] = n;
		else if(minmax[1] < n) minmax[1] = n; 
	}
	cout << minmax[0] << " " << minmax[1] ;
	return 0;
}
