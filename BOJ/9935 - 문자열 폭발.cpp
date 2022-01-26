#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

char ans[1000001];

int main() {
	FASTIO;
	string init, bomb;
	cin >> init >> bomb;
	int idx = 0;
	for (char c : init) {
		ans[idx++] = c;
		int i = (int)bomb.length();
		if (c == bomb[--i]) {
			bool check = false;
			int size = idx - (int)bomb.length();
			for (int j = idx - 1; j >= size; j--) {
				if (ans[j] == bomb[i--]) {
					check = true;
				}
				else {
					check = false;
					break;
				}
			}
			if (check) idx -= bomb.size();
		}
	}
	if (idx == 0)
		cout << "FRULA";
	else
	{
		for (int i = 0; i < idx; i++) {
			cout << ans[i];
		}
			
	}
	return 0;
}