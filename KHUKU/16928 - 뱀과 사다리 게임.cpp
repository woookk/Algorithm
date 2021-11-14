#include<iostream>
#include<queue>
using namespace std;
int N, M;
int from, to;
int line[101] = { 0 };
int cnt[101] = { 0 };
queue<int> q;

void bfs() {
	while (!q.empty()) {
		int front = q.front();
		q.pop();

		if (front == 100) return;
		
		for (int i = 1; i <= 6; i++) {
			int next = front + i;
			if (next > 100) {
				continue;
			}
			else {
				if (line[next] == 0) {
					if (cnt[next] == 0) {
						cnt[next] = cnt[front] + 1;
						q.push(next);
					}
				}
				else {
					if (cnt[line[next]] == 0) {
						cnt[line[next]] = cnt[front] + 1;
						q.push(line[next]);
					}
				}
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N + M; i++) {
		cin >> from >> to;
		line[from] = to;
	}
	q.push(1);
	bfs();
	cout << cnt[100];
	return 0;
}