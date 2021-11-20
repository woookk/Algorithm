#include<iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int n, x, cnt = 0;
int num[1000001] = {};
bool chk[2000001];

int main() {
	FASTIO;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	cin >> x;

	for (int i = 0; i < n; i++) {
		if(x - num[i]>=0)
			if (chk[x - num[i]] == 1) {
				cnt++;
			}
		chk[num[i]] = 1;
	}
	cout << cnt;
	return 0;
}

/*
공간복잡도 O(2000000), 시간복잡도 O(n)에 풀이가 가능. 만약 입력 형식에서
x가 a 배열보다 먼저 주어졌다면 int a[] 배열은 필요가 없었음.
*/