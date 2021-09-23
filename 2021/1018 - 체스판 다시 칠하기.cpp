#include<iostream>
using namespace std;
char color[51][51];
int check(int r, int c) {
	int cnt[2] = { 0 };
	for (int i = 0; i < 4; i++) 
		for (int j = 0; j < 4; j++) {
			if (color[r + 2 * i][c + 2 * j] != 'W') cnt[0]++;
			if (color[r + 2 * i + 1][c + 2 * j + 1] != 'W') cnt[0]++;
			if (color[r + 2 * i][c + 2 * j + 1] != 'B') cnt[0]++;
			if (color[r + 2 * i + 1][c + 2 * j] != 'B') cnt[0]++;
		}
	for (int i = 0; i < 4; i++) 	
		for (int j = 0; j < 4; j++) {
			if (color[r + 2 * i][c + 2 * j] != 'B') cnt[1]++;
			if (color[r + 2 * i + 1][c + 2 * j + 1] != 'B') cnt[1]++;
			if (color[r + 2 * i][c + 2 * j + 1] != 'W') cnt[1]++;
			if (color[r + 2 * i + 1][c + 2 * j] != 'W') cnt[1]++;
		}
	if (cnt[0] < cnt[1]) return cnt[0];
	else return cnt[1];
}

int main() {
	int N, M, min = 64;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> color[i][j];
		}
	}
	for (int i = 0; i < N-7; i++) {
		for (int j = 0; j < M-7; j++) {
			if(min > check(i, j)) min=check(i, j);
		}
	}
	cout << min;
	return 0;
}