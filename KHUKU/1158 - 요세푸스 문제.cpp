#include<iostream>
#include<queue>
using namespace std;
int main() {
	int N, K;
	queue<int> q;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	while (!q.empty()) {
		for (int i = 0; i < K-1; i++) {
			int move = q.front();
			q.pop();
			q.push(move);
		}
		if (q.size() == N) cout << '<';
		cout << q.front();
		if (q.size() != 1)cout << ", ";
		if (q.size() == 1)cout << '>';
		q.pop();
	}
	return 0;
}