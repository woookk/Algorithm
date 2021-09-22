#include<iostream>
#include<queue>
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
	FASTIO;
	int N;
	cin >> N;
	queue<int> q;
	for (int i = 0; i < N; i++) {
		string command;
		int num;
		cin >> command;
		if (command == "push") {
			cin >> num;
			q.push(num);
		}
		else if (command == "size") {
			cout << q.size() << "\n";
		}
		else if (command == "empty") {
			cout << q.empty() << "\n";
		}
		else {
			if (q.empty()) cout << -1 << "\n";
			else {
				if (command == "pop") {
					cout << q.front() << "\n";
					q.pop();
				}
				else if (command == "front")
					cout << q.front() << "\n";
				else cout << q.back() << "\n";
			}
		}
	}
	return 0;
}