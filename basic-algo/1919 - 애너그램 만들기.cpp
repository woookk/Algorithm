#include<iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int main() {
	FASTIO;
	int cnt[2][26] = {}, ans = 0;
	string a, b;
	cin >> a >> b;
	for (int i = 0; i < a.length(); i++) {
		cnt[0][a[i] - 'a']++;
	}
	for (int i = 0; i < b.length(); i++) {
		cnt[1][b[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		ans += abs(cnt[0][i] - cnt[1][i]);
	}
	cout << ans;
	return 0;
}