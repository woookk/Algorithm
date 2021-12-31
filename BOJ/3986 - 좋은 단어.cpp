#include<iostream>
#include<stack>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int main() {
	FASTIO;
	int N, cnt = 0;
	cin >> N;
	while(N--) {
		string temp;
		cin >> temp;
		stack<char> s;
		for (char c : temp) {
			if (!s.empty() && s.top() == c) {
				s.pop();
			}
			else if (!s.empty() && s.top() != c) { // else if, else 둘 다 else로 통합해도 됨.
				s.push(c);
			}
			else {
				s.push(c);
			}
		}
		if (s.empty()) cnt++;
	}
	cout << cnt;
	return 0;
}