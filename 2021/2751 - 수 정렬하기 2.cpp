#include<iostream>
#include<algorithm>
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
	FASTIO;
	int N, num[1000000];
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	sort(num, num + N);
	for (int i = 0; i < N; i++) {
		cout << num[i] << "\n";
	}
	return 0;
}