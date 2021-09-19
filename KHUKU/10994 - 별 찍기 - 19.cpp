#include<iostream>
#include<cstring>
using namespace std;
char star[401][401];
int k = 0;
void recursive(int N) {
	if (N < 1) return;
	for (int i = 0; i < 4 * N - 3; i++) {
		star[k + i][k] = '*';
		star[k + i][k + 4 * N - 4] = '*';
		star[k][k + i] = '*';
		star[k + 4 * N - 4][k + i] = '*';
	}
	k += 2;
	recursive(N - 1);
}
int main() {
	int N;
	cin >> N;
	memset(star, ' ', sizeof(star));
	recursive(N);
	for (int i = 0; i < 4 * N - 3; i++) {
		for (int j = 0; j < 4 * N - 3; j++)
			cout << star[i][j];
		cout << "\n";
	}
	return 0;
}