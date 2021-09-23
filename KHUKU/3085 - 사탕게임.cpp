#include<iostream>
using namespace std;
int N, cnt, m = 1;
char candy[51][51];
void rowcheck() {
	for (int i = 0; i < N; i++) { 
		char a = candy[i][0];
		cnt = 1;
		for (int j = 1; j < N; j++) {
			if (candy[i][j] == a) cnt++;
			else {
				cnt = 1;
				a = candy[i][j];
			}
			if (cnt > m) m = cnt;
		}
	}
}
void columncheck() {
	for (int i = 0; i < N; i++) {
		char a = candy[0][i];
		cnt = 1;
		for (int j = 1; j < N; j++) {
			if (candy[j][i] == a) cnt++;
			else {
				cnt = 1;
				a = candy[j][i];
			}
			if (cnt > m) m = cnt;
		}
	}
}
void swap(char& a, char& b) {
	char temp;
	temp = a;
	a = b;
	b = temp;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> candy[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N-1; j++) {
				swap(candy[i][j], candy[i][j + 1]);
				columncheck();
				rowcheck();
				swap(candy[i][j], candy[i][j + 1]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N-1; j++) {
				swap(candy[j][i], candy[j + 1][i]);
				rowcheck();
				columncheck();
				swap(candy[j][i], candy[j + 1][i]);
		}
	}
	cout << m;
	return 0;
}