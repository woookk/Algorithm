#include<iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int main() {
	FASTIO;
	int day, n[5], cnt = 0;
	cin >> day;
	for (int i = 0; i < 5; i++) {
		cin >> n[i];
		if (day % 10 == n[i]) cnt++;
	}
	cout << cnt;
	return 0;
}