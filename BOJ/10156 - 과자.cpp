#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int main() {
	FASTIO;
	int K, N, M;
	cin >> K >> N >> M;
	int ans = K * N - M;
	if (ans < 0) ans = 0;
	cout << ans;
	return 0;
}