#include <iostream>

using namespace std;

int main(){
	cout << fixed;
	cout.precision(10);
	int size;
	cin >> size;
	double arr[size]{};
	int max{};
	for (int i=0; i<size; i++){
		cin >> arr[i];
		if(max<arr[i]) max = arr[i];
	}
	double sum{};
	for (int i=0; i<size; i++){
		arr[i] = arr[i]/max*100;
		sum += arr[i];
	}
	cout << sum/size << endl;
	return 0;
}
