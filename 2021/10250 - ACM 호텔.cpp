#include<iostream>
using namespace std;

int main() {
	int T, H, W, N;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> H >> W >> N;
		if (N % H != 0)
			if (N / H  < 9)
				cout << N % H << "0" << N / H + 1 << "\n";
			else
				cout << N % H << N / H + 1 << "\n";
		else
			if (N / H < 10)
				cout << H << "0" << N / H << "\n";
			else
				cout << H << N / H << "\n";
	}
	return 0;
}