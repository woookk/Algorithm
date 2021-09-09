#include<iostream>
#include<string>

using namespace std;
int main() {

	string word;
	getline(cin, word);
	int cnt = word.length();
	for (int i = 0; i < word.length(); i++) {
		if (word[i] == 'd' && word[i + 1] == 'z' && word[i+2]=='=') cnt -= 1;
		else if ((word[i] == 'l' || word[i] == 'n')&& word[i + 1] == 'j') cnt -= 1;
		else if (word[i] == '-' || word[i] == '=') cnt -= 1;
	}
	cout << cnt;
	return 0;
}