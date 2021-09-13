#include<iostream>
using namespace std;
int arr[1001];
void chkprimenum() {
	for (int i = 2; i <= 1000; i++) {
		arr[i] = i;
	}
	for (int i = 2; i <= 1000; i++) {
		if (arr[i] == 0) continue;

		for (int j = i*2; j <= 1000; j = j + i) {
			if (arr[j] == 0) continue;
			else arr[j] = 0;
		}
	}
}
int main() {
	chkprimenum();
	for (int i = 2; i < 1000; i++) {
		if (arr[i] != 0) cout << arr[i] << ' ';
	}
	return 0;
}