#include<iostream>
#include<deque>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int main() {
	FASTIO;

	int N;
	cin >> N;

	deque<int> DQ;
	while (N--) {
		string q;
		cin >> q;
		if (q == "push_front") {
			int n;
			cin >> n;
			DQ.push_front(n);
		}
		else if (q == "push_back") {
			int n;
			cin >> n;
			DQ.push_back(n);
		}
		else if (q == "pop_front") {
			if (DQ.empty()) cout << -1 << "\n";
			else {
				cout << DQ.front() << "\n";
				DQ.pop_front();
			}
		}
		else if (q == "pop_back") {
			if (DQ.empty()) cout << -1 << "\n";
			else {
				cout << DQ.back() << "\n";
				DQ.pop_back();
			}
		}
		else if (q == "size") {
			cout << DQ.size() << "\n";
		}
		else if (q == "empty") {
			if (DQ.empty()) cout << 1 << "\n";
			else {
				cout << 0 << "\n";
			}
		}
		else if (q == "front") {
			if (DQ.empty()) cout << -1 << "\n";
			else {
				cout << DQ.front() << "\n";
			}
		}
		else { //back
			if (DQ.empty()) cout << -1 << "\n";
			else {
				cout << DQ.back() << "\n";
			}
		}
	}
	return 0;
}