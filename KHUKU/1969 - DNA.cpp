#include<iostream>
using namespace std;
int sum = 0;
int max(int arr[4]) {
	int max=-1, index;
	for (int i = 0; i < 4; i++) {
		if (arr[i] > max) {
			max = arr[i];
			index = i;
		}
	}
	return index;
}

char DNA[1000][50], s[50];
int main() {
	int N, M, cnt[4];
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> DNA[i];
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < 4; j++) cnt[j] = 0;
		for (int j = 0; j < N; j++) {
			if (DNA[j][i] == 'A') cnt[0]++;
			else if (DNA[j][i] == 'C') cnt[1]++;
			else if (DNA[j][i] == 'G') cnt[2]++;
			else if (DNA[j][i] == 'T') cnt[3]++;
		}
		sum += N;
		if(max(cnt)==0) s[i] = 'A';
		else if(max(cnt) == 1) s[i] = 'C';
		else if (max(cnt) == 2) s[i] = 'G';
		else s[i] = 'T';
		sum -= cnt[max(cnt)];
	}
	cout << s << "\n" << sum;
	return 0;
}