#include<iostream>
using namespace std;
int N, w[51], h[51];
int compare(int index) {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (w[i] > w[index] && h[i] > h[index]) cnt++;
	}
	return cnt+1;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> w[i] >> h[i];
	}
	for (int i = 0; i < N; i++) {
		cout << compare(i) << ' ';
	}
	return 0;
}