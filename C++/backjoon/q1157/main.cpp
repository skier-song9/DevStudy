#include <iostream>

using namespace std;
void quickSort(int *data, int start, int end);
int main(){
	string word;
	cin >> word;
	int size = int(word.size());
	// 대문자의 경우 32를 더하면 소문자가 됨.
	// 퀵 정렬로 우선 정렬
	int arr[size]{};
	for (int i=0; i<size; i++){
		int k = int(word[i]);
		if(k>=97) arr[i] = k-32;
		else arr[i] = k;
	}
	int alphabet[26]{};
	for(int i=0;i<size;i++){
		alphabet[arr[i]-65]++;
    }
	int max{};
	for(int i=0;i<26;i++){
		if(alphabet[i] > max) max = alphabet[i];
	}
	int count{};
	int result{};
	for(int i=0;i<26;i++){
		if(alphabet[i]==max) {
			count++;
			result+=i;
		}
	}
	if(count > 1) cout << "?" << endl;
	else cout << char(result+65) << endl;

	return 0;
}
