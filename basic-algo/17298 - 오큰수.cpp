#include<iostream>
#include<stack>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int a[1000000];
int ans[1000000];
int main(void) {
	FASTIO;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> a[i];
	
	stack<int> S;
	for (int i = n - 1; i >= 0; i--) { // a[i]로 입력 저장 후, 뒤에서 부터 접근
		while (!S.empty() && S.top() <= a[i]) S.pop();
		if (S.empty())
			ans[i] = -1;
		else
			ans[i] = S.top();
		S.push(a[i]);
	}
	for (int i = 0; i < n; i++) cout << ans[i] << ' ';
}