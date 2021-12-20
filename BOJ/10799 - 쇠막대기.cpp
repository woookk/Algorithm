#include<iostream>
#include<stack>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int main() {
	FASTIO;
	string pipe;
	cin >> pipe;
	stack<char> s;
	int res = 0;
	for (int i = 0; i < pipe.length(); i++) {
		if (pipe[i] == '(')
			s.push(pipe[i]);
		else if (pipe[i] == ')') {
			if (pipe[i - 1] == '(') {
				s.pop();
				res += (int)s.size();
			}
			else {
				s.pop();
				res ++;
			}
		}
	}
	cout << res;
	return 0;
}
