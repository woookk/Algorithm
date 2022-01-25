#include <iostream>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int board[100001];
int pre[100001];

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	board[N] = 1;
	pre[N] = N;

	queue<int> q;
	q.push(N);

	while (!board[K]) {
		auto cur = q.front();
		q.pop();
		for (int nx : {cur - 1, cur + 1, 2 * cur}) {
			if (nx < 0 || nx > 100000) continue;
			if (board[nx]) continue;
			board[nx] = board[cur] + 1;
			pre[nx] = cur;
			q.push(nx);
		}
	}

	cout << board[K] - 1 << "\n";
	deque<int> track = { K };
	while (track.front() != N)
		track.push_front(pre[track.front()]);
	for (int n : track) cout << n << " ";
	return 0;
}