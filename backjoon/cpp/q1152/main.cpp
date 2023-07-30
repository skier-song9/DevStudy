#include <iostream>
#include <sstream>
using namespace std;
int main(){
	int count{};
	string line{};
	getline(cin, line);	

	stringstream ss;
	ss.str(line);
	
	while(ss >> line){
		count++;
	}

	cout << count << endl;
	
}
