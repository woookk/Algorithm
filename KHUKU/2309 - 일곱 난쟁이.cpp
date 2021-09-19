#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int h[9], sum=0, a, b;
	for (int i = 0; i < 9; i++) {
		cin >> h[i];
		sum += h[i];
	}
	sort(h, h + 9);
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - (h[i] + h[j]) == 100)	a = i, b = j;
		}
	}
	for (int i = 0; i < 9; i++) {
		if (i == a || i == b);
		else cout << h[i] << "\n";
	}
	return 0;
}