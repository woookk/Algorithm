#include <iostream>
#include <cmath>
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main() {
	FASTIO
	int T, x, y, n, s, cnt;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> x >> y; s = y - x;
		n = floor(sqrt(s));
		s -= n * n;
		cnt = 2 * n - 1;
		if (s == 0);
		else if (s <= n) cnt += 1;
		else cnt += 2;
		cout << cnt << "\n";
	}
	return 0;
}