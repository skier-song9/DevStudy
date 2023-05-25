#include <iostream>
#include <fstream>
using namespace std;
int main(){

	ifstream inputFile();
	int t;
	if (inputFile.is_open()){
		inputFile >> t;
		inputFile.close();
		cout << "t: " << t << endl;
	}
	else{}

	return 0;
}
