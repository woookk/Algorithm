#include<iostream>
#include<string>
using namespace std;

int main() {
	string num;
	
	while (getline(cin, num)) {
		bool flag = true;
		if (num == "0") break;

		for (int i = 0; i < num.length() / 2; i++) 
			if (num[i] != num[num.length() - i - 1]) {
				flag = false;
				break;
			}
		if (flag)
			cout << "yes\n";
		else
			cout << "no\n";
	}
	return 0;
}