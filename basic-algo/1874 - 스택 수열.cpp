#include<iostream>
#include<stack>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);



int main() {
	FASTIO;
	
	stack<int> s;
	int n;

	cin >> n;
	int cnt = 1;
	string ans;
	while (n--) {
		int t;
		cin >> t;
		while (cnt <= t) {
			s.push(cnt++);
			ans += "+\n";
		}
		if (s.top() != t) {
			cout << "NO\n";
			return 0;
		}
		s.pop();
		ans += "-\n";
	}
	cout << ans;
}

//string에 \n도 들어갈 수 있음.