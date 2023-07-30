#include <iostream>
using namespace std;
int main(){
	int a,b,c;
	cin >> a >> b >> c;
	int arr[10]{};
	int multi = a*b*c;
	cout << "multi = " << multi << endl;
	while(true){
		int k{-1};
		k = multi % 10;
		cout << "k: " << k << endl;
		multi = multi/10;
		arr[k]++;
		if(multi==0) break;
	}

	for (int i=0;i<10;i++) { cout << arr[i] << endl;}
	return 0;
}
