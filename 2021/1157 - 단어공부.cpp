#include<iostream>
#include<string>
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
int m(int n[26]) {
	int max=0, alpha, cnt=0;
	for (int i = 0; i < 26; i++) {
		if (n[i] > max) max = n[i], alpha = i;
	}
	for (int i = 0; i < 26; i++) {
		if (n[i] == max) cnt++;
	}
	if (cnt == 1) alpha;
	else alpha = -2;
	return alpha;
}
int main() {
	FASTIO;
	string w;
	int a[26] = { 0 };
	getline(cin, w);

	for (int i = 0; i < w.length(); i++) {
		if (w[i] >= 97) w[i] -= 32;
		for (int j = 0; j < 26; j++) {
			if (w[i] == 65+j) a[j]++;
		}
	}
	cout << (char)(65+m(a));
	return 0;
}

