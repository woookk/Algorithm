#include<iostream>
using namespace std;

int main() {
	int M, N, sum, card[100], max=3;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> card[i];
	}
	for (int i = 0; i < N-2; i++) {
		for (int j = i + 1; j < N-1; j++) {
			for (int k = j + 1; k < N; k++) {
				sum = card[i] + card[j] + card[k];
				if (sum <= M) 
					if(sum>max) max = sum;
			}
		}
	}
	cout << max;
	return 0;
}