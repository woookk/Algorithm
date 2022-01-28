#include <iostream>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int main() {
	FASTIO;
	int N;
	cin >> N;
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	while (q.size() != 1) {
		cout << q.front() << " ";
		q.pop();
		q.push(q.front());
		q.pop();
	}
	cout << q.front();
	return 0;
}