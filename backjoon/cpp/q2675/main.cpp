#include <iostream>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		string s;
		cin >> n >> s;
		for(int i=0;i<s.size();i++){
			for(int j=0;j<n;j++) {cout << s[i];}
		}
		cout << endl;
	}
	return 0;
}
