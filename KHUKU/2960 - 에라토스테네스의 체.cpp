#include<iostream>
using namespace std;
int N, K, cnt=0;
int arr[1001];
int chkprimenum(int num, int K) {
	for (int i = 2; i <= num; i++) {
		arr[i] = i;
	}
	for (int i = 2; i <= num; i++) {
		if (arr[i] == 0) continue;

		for (int j = i; j <= num; j = j + i) {
			if (arr[j] == 0) continue;
			else {
				arr[j] = 0;
				cnt++;
				if (cnt == K) return j;
			}
		}
	}
}
int main() {
	cin >> N >> K;
	cout <<chkprimenum(N, K);
	
	return 0;
}