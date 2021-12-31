#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int main() {
	FASTIO;
	int N, M, ans = 0;
	cin >> N >> M;
	deque<int> DQ;
	for (int i = 0; i < N; i++) {
		DQ.push_back(i + 1);
	}
	while (M--) {
		int temp, cnt = 0;
		cin >> temp;
		while (DQ.front() != temp) { // if (idx < DQ.size() - idx)를 통해 계산전 위치 파악하고 계산할수도.
			DQ.push_back(DQ.front());
			DQ.pop_front();
			cnt++;
		}
		ans += min((int)DQ.size() - cnt, cnt);
		DQ.pop_front();
	}
	cout << ans;
	return 0;
}

/*
20번째 줄에서, 지금은 idx가 항상 DQ.size()보다 작아서 문제가 없지만
DQ.size()는 unsigned int(or unsigned long long)이기
때문에 만약 idx가 DQ.size()보다 컸다면 overflow가 발생해
의도한대로 동작하지 않을 수 있음을 인지해야 함. 그래서 size()로
받아온 값에 대해서는 안전하게 (int)DQ.size() 로 항상 형변환을
하는 것도 괜찮음.
*/