#include <iostream>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	char ch{};
	cin >> t;
	int sum{};
	while(t--) {
		cin >> ch;
		sum += ch - '0';
	}
	cout << sum << "\n";
	return 0;
}
