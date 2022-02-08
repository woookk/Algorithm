#include<iostream>
#include<stack>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main() {
	FASTIO;
	stack<int> s;
	string command;
	int N, num;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> command;
		if (command == "push") {
			cin >> num;
			s.push(num);
		}
		else if (command == "size") {
			cout << s.size() << "\n";
		}
		else if (command == "empty") {
			cout << s.empty() << "\n";
		}
		else {
			if (s.empty()) cout << -1 << "\n";
			else {
				if (command == "pop") {
					cout << s.top() << "\n";
					s.pop();
				}
				else cout << s.top() << "\n";
			}
		}
	}	
	return 0;
}