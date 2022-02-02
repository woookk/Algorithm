#include<iostream>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
bool arr[1001] = { false };
void primecheck() {
	for (int i = 2; i <= 1000; i++) {
		arr[i] = true;
	}
	for (int i = 2; i * i <= 1000; i++) {
		if (arr[i] == false) continue;

		for (int j = i * i; j <= 1000; j =j + i) {
			if (arr[j] == false) continue;
			else arr[j] = false;
		}
	}
	return;
		
}
int main() {
	FASTIO;
	int N, num[101], cnt=0;
	cin >> N;
	primecheck();
	for (int i = 0; i < N; i++) {
		cin >> num[i];
		if (arr[num[i]]) cnt++;
	}
	cout << cnt;
	return 0;
}