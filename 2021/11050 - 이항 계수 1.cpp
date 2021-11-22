#include<iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int main() {
	FASTIO;

	int N, K, ans = 1;
	cin >> N >> K;
	
	for (int i = N; i > N - K; i--) {
		ans *= i;
	}
	for (int i = 1; i <= K; i++) {
		ans /= i;
	}
	cout << ans;
	return 0;
}

/*이항계수(Binomial Coefficient)는 조합론에서 등장하는 개념으로 주어진 크기 집합에서 
원하는 개수만큼 순서없이 뽑는 조합의 가짓수를 일컫는다.*/