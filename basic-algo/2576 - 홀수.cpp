#include<iostream>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
	int n[7];
	int sum = 0, min = 100;
	for (int i = 0; i < 7; i++) {
		cin >> n[i];
		if (n[i] % 2 == 1) {
			sum += n[i];
			if (min > n[i]) min = n[i];
		}
	}
	if (sum != 0) cout << sum << "\n" << min;
	else cout << -1;
	return 0;
}