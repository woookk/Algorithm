#include<iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int main() {

	string word;
	cin >> word;
	int A[26] = { 0 };
	for (int i = 0; i < word.length(); i++) {
		A[(int)word[i] - 97]++;
	}
	for (int e : A){
		cout << e << " ";
	}
	return 0;
}