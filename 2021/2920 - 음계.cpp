#include<iostream>
using namespace std;

int main() {
	int str[8];
	for (int i = 0; i < 8; i++) {
		cin >> str[i];
	}
	int asc=0, desc=0;
	for (int i = 0; i < 7; i++) {
		if (str[i + 1] > str[i]) asc++;
		else if (str[i + 1] < str[i] ) desc++;
	}
	if (asc == 7) cout << "ascending";
	else if (desc == 7) cout << "descending";
	else cout << "mixed";

	return 0;
}