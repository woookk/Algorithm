#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int N, num[1000];
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