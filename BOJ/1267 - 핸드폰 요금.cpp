#include<iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int main() {
	FASTIO;
	int N;
	cin >> N;
	int num[20];
	int Y = 0, M = 0;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
		Y += (num[i] / 30 + 1) * 10;
		M += (num[i] / 60 + 1) * 15;
	}
	if (Y < M) cout << "Y " << Y;
	else if (M < Y) cout << "M " << M;
	else cout << "Y M " << Y;
	return 0;
}