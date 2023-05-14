#include <iostream>
using namespace std;
int main(){
	int arr[9]{};
	int max{};
	int c{};
	for(int i=0;i<9;i++){
		cin >> arr[i];
		if(max < arr[i]) {
			max = arr[i];
			c = i+1;
		}
	}
	
	cout << max << endl;
	cout << c << endl;
	return 0;
}
