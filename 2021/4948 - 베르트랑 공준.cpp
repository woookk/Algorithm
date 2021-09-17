#include<iostream>
using namespace std;
bool num[250000] = { false };

int primecheck(int n) {
	int cnt=0;
	for (int i = 2; i <= 2*n; i++) {
		num[i] = true;
	}
	for (int i = 2; i <= 2 * n; i++) {
		if (num[i] == false) continue;

		for (int j = i * 2; j <= 2 * n; j =j + i) {
			if (num[j] == false) continue;
			else num[j] = false;
		}
	}
	for (int i = n + 1; i <= 2 * n; i++) {
		if (num[i]) cnt++;
	}
	return cnt;
}
int main() {
	int n;
	while (1) {
		cin >> n;
		if (n == 0) break;
		cout << primecheck(n) <<"\n";
	}
	
	return 0;
}