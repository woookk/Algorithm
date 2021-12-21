#include<iostream>
#include<stack>
using namespace std;
int main() {
	string str;
	cin >> str;
	int sum = 0;
	int num = 1;
	stack<char> s;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			s.push(str[i]);
			num *= 2;
		}
		else if (str[i] == '[') {
			s.push(str[i]);
			num *= 3;
		}
		else if (str[i] == ')') {
			if (s.empty() || s.top() == '[') {
				cout << 0;
				return 0;
			}
			if (str[i - 1] == '(') sum += num;
			s.pop();
			num /= 2;
		}
		else {
			if (s.empty() || s.top() == '(') {
				cout << 0;
				return 0;
			}
			if (str[i - 1] == '[') sum += num;
			s.pop();
			num /= 3;
		}
	}
	if (s.empty()) cout << sum;
	else cout << 0;
	return 0;
}