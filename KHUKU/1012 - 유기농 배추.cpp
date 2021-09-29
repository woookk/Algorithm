#include<iostream>
using namespace std;
bool cab[51][51] = { 0 };
int T, M, N, K;
void dfs(int W, int H) {
	cab[W][H] = 0;
	int next1 = 1, next2 = -1;
	if (W < 50 && cab[W + next1][H]) dfs(W + next1, H);
	if (H < 50 && cab[W][H + next1]) dfs(W, H + next1);
	if (W > 0 && cab[W + next2][H]) dfs(W + next2, H);
	if (H > 0 && cab[W][H + next2]) dfs(W, H + next2);
}
int main() {
	cin >> T;
	int W, H, cnt;
	for (int i = 0; i < T; i++) {
		cin >> M >> N >> K;
		cnt = 0;
		for (int j = 0; j < K; j++) {
			cin >> H >> W;
			cab[W][H] = 1;
		}
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (cab[j][k] == 1) {
					dfs(j, k);
					cnt++;
				}
				else continue;
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}