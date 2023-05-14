#include <iostream>
using namespace std;
int main (){
	int t;
	cin >> t;
	cin.ignore();
	//cout << t << endl;
	while(t--){	
		int total{};
		int seq{};
		string line{};
		getline(cin,line);
		//cout << "line : " << line << endl;
		for(int i=0;i<line.size();i++){
			if(line[i]=='O'){
				seq++;
				total += seq;
			}
			else{
				seq = 0;
			}
		}
		cout << total << "\n";
	}
	return 0;
}
