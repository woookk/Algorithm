#include<iostream>
using namespace std;
int main() {
	int N, cnt=0;
	cin >> N;
	while (N>=3) {
		if (N % 5 == 0) {
			cnt += N / 5;
				N = 0;
		}
		else { 
			N -= 3;
			cnt++;
		}
	}
	if (N) cout << -1; 
	else cout << cnt;

	return 0;
}