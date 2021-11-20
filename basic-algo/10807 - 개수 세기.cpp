#include<iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int main() {
	FASTIO;
	int N, n[100], v, cnt = 0;
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n[i];
	}
	cin >> v;

	for (int i = 0; i < N; i++) {
		if (n[i] == v) cnt++;
	}

	cout << cnt;
	return 0;
}