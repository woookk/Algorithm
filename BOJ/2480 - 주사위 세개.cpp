#include<iostream>
#include<algorithm>
using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0)

int main() {
	FASTIO;
	int d[3]; //dice
	for (int i = 0; i < 3; i++) {
		cin >> d[i];
	}
	if (d[0] == d[1] && d[1] == d[2]) cout << 10000 + d[0] * 1000;
	else if (d[0] != d[1] && d[1] != d[2] && d[0] != d[2]) {
		cout << max({ d[0], d[1], d[2]}) * 100;
	}
	else {
		if (d[0] == d[1]) cout << 1000 + d[0] * 100;
		else if (d[1] == d[2]) cout << 1000 + d[1] * 100;
		else cout << 1000 + d[2] * 100;
	}
	return 0;
}

//정렬하고 하는 방법
/*if (a[0] == a[2]) cout << 10000 + a[0] * 1000; // 세 수가 동일
else if (a[0] == a[1] || a[1] == a[2]) cout << 1000 + a[1] * 100; // 두 수가 동일
else cout << a[2] * 100;*/