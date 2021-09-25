#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main() {
	string str;
	
	
	while (getline(cin, str)) {
		stack<char> s;
		bool flag = true;
		if (str == ".") break;
		for (int j = 0; j < str.length(); j++)
		{	
			if (str[j] == '(' || str[j] == '[') s.push(str[j]);
			else if (str[j] == ')') {
				if (s.empty() || s.top() == '[') {
					flag = false;
					break;
				}
				else if (s.top() == '(') {
					s.pop();
				}
			}
			else if (str[j] == ']') {
				if (s.empty() || s.top() == '(') {
					flag = false;
					break;
				}
				else if (s.top() == '[') {
					s.pop();
				}
				
			}
		}
		if (s.empty() && flag) cout << "yes" << endl;
		
		else cout << "no" << endl;
	}	

	return 0;
}