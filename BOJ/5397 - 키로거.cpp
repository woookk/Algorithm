#include<iostream>
#include<list>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int main() {
	FASTIO;
	int T;
	cin >> T;

	while (T--) {

		string init;

		list<char> L = {};
		auto cursor = L.begin();

		cin >> init;
		for (auto c : init) {
			if (c == '<') {
				if (cursor != L.begin()) cursor--;
			}
			else if (c == '>') {
				if (cursor != L.end()) cursor++;
			}
			else if (c == '-') {
				if (cursor != L.begin()) {
					cursor--;
					cursor = L.erase(cursor);
				}
			}
			else L.insert(cursor, c);
		}
		for (auto c : L) cout << c;
		cout << "\n";
	}
	return 0;
}

// 문제 제대로 생각하고 풀기.