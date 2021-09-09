#include<iostream>
#include<string>
using namespace std;

int Groupword(string word) {
	int a[26] = { 0 }; bool check = true;
	for (int i = 0; i < word.length(); i++) {
		word[i] -= 97;
		if (i == 0) a[word[i]] ++;
		else if (word[i] != word[i - 1] && a[word[i]] == 0) {
			a[word[i]] ++;
			check = true;
		}
		else if (word[i] == word[i - 1]) check = true;
		else {
			check = false;
			break;
		}
	} return check;
}

int main() {
	int N, cnt = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string word;
		cin >> word;
		if (Groupword(word)) cnt++;
	} cout << cnt;
	return 0;
}