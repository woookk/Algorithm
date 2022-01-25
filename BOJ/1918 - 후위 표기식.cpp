#include <iostream>
#include <stack>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int main() {
	FASTIO;
	string init;
	cin >> init;
	stack<char> s;
	for (char c : init) {
		if (c == '+' || c == '-') {
			while (!s.empty() && (s.top() != '(')) {
				cout << s.top();
				s.pop();
			}
			s.push(c);
		}
		else if (c == '*' || c == '/') {
			while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
				cout << s.top();
				s.pop();
			}
			s.push(c);
		}
		else if (c == '(') {
			s.push(c);
		}
		else if (c == ')') {
			while (!s.empty() && s.top() != '(') {
				cout << s.top();
				s.pop();
			}
			s.pop();
		}
		else {
			cout << c;
		}
	}
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	return 0;
}