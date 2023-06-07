#include <iostream>

int main(){
	int arr[10]{};
	for(int i{};i<10;i++){
		int t;
		cin >> t;
		arr[i] = t%42;
	}
	

    return 0;
}
