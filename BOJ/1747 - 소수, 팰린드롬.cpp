#include <iostream>
#include <string>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

bool prime[1010001];

void primecheck(int MX) {
	for (int i = 2; i <= MX; i++)
		prime[i] = 1;
	for (int i = 2; i * i <= MX; i++) {
		if (prime[i] == 0) continue;

		for (int j = i * i; j <= MX; j += i) {
			if (prime[j] == 0) continue;
			else prime[j] = 0;
		}
	}
}

int main() {
	FASTIO;
	int N, MX;
	cin >> N;
	MX = 1010000;
	primecheck(MX);
	for (int i = N; i < MX; i++) {
		if (prime[i]) {
			bool flag = true;
			string str = to_string(i);
			int len = str.length() / 2;
			for (int j = 0; j < len; j++) {
				if (str[j] == str[str.length() - 1 - j]) flag = true;
				else {
					flag = false;
					break;
				}
			}
			if (flag) {
				cout << i;
				break;
			}
		}
	}
	return 0;
}