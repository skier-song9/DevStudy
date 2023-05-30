#include <iostream>
#include <fstream>
#include <list>
using namespace std;
int main(){

	list<int> ll;
	ll.push_back(10);
	ll.push_back(10);
	ll.push_back(200);
	ll.push_back(4000);
	ll.push_back(10);
	ll.push_back(200);
	ll.push_back(10);

	list<int>::iterator iter = ll.begin();
	list<int> newll{};
	int count = 0;
	while(iter!=ll.end()){
		cout << "while문 안" << endl;
		int c = *iter;
		int temp_c{c};
		cout << "c = " << c << endl;
		for(++iter; iter!=ll.end(); iter++){
			cout << "*iter = " << *iter << "\n";
			if (c==*iter){
				temp_c+= *iter;
				iter = ll.erase(iter);
				iter--;
			}
		}
		cout << "for문 이후 temp_c = " << temp_c << "\n";
//		cout << "for문 끝" << endl;
		newll.push_back(temp_c);
		iter = ll.begin();
		count++;
		for(int i=0;i<count;i++){iter++;}
		//++iter;	
	}

	for(auto& e:newll){
		cout << e << " ";
	}

	cout << endl;

	return 0;
}
