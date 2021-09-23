#include<iostream>
using namespace std;
int main() {
	int N, cnt=0;
	cin >> N;
	for (int i = 1; i < N; i++) {
		if (N == i + i % 10 + i / 10 % 10 + i / 100 % 10 + i / 1000 % 10 + i / 10000 % 10 + i / 100000 % 10 + i / 1000000 % 10) {
			cout << i;
			cnt++;
			break;
		}
	}
	if (cnt == 0) cout << 0;
	return 0;
}