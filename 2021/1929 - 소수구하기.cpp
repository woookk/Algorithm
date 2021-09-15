#include<iostream>
using namespace std;
bool arr[1000001] = { false };
void primecheck(int M, int N) {
	for (int i = 2; i <= N; i++) {
		arr[i] = true;
	}
	for (int i = 2; i <= N; i++) {
		if (arr[i] == false) continue;
		
		for (int j = 2 * i; j <= N; j = j + i) {
			if (arr[j] == false) continue;
			else arr[j] = false;
		}
	}
	for (int i = M; i <= N; i++) {
		if (arr[i]) cout << i << "\n";
	}
}
int main() {
	int M, N;
	cin >> M >> N;
	primecheck(M, N);
	return 0;
}