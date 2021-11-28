#include<iostream>
#include<stack>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

	stack<int> s;
	int n;
	long long ans; // ans int범위 넘을 수 있음.

	int main() {
		FASTIO;

		cin >> n;
		int h; 
		while (n--) {
			cin >> h;
			while (!s.empty() && s.top() <= h) // s.top() 확인하려면 !s.empty()인지 선확인 필수.
				s.pop();
			ans += s.size(); //쌓여있는 개수 = 높이 h인 빌딩을 볼 수 있는 개수.
			s.push(h);
		}
		cout << ans;
		return 0;
	
}