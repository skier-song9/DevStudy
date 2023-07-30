#include <iostream>
using namespace std;
int main(){
	int t;
	cin >> t;
	for (int i=0;i<t;i++){
		for (int j=0;j<t;j++){
			if(j >= t-1-i) cout << "*";
			else cout << " ";
		}
		cout << endl;
	}
	return 0;
}
