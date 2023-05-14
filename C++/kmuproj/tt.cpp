#include <iostream>
#include <string>
using namespace std;

char pop(string &str);

int main(){

	string str{"1234"};
	char last{str[str.size()-1]};
	string newstr = last + str;
	cout << newstr << endl;

	cout << str[3] + 10 << endl;
	str[3] += 10;
	cout << str << endl;


	return 0;
}

char pop(string &str){
    char ch = str.back();
    str.pop_back();
    return ch;
}
