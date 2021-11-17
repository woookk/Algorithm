#include<iostream>
#include<algorithm>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
	FASTIO;
	int A[3];
	for (int i = 0; i < 3; i++) {
		cin >> A[i];
	}
	sort(A, A + 3);
	for (int i = 0; i < 3; i++) {
		cout << A[i] << " ";
	}
	return 0;
}

//max(a, b, c), min(a, b, c), a+b+c-max(a,b,c)-min(a,b,c)로도 풀이 가능.