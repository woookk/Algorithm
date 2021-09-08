#include<iostream>
#include <string>
using namespace std;
int sum=0, cnt;
int main() {
	string dial;
	cin >> dial;
	for(int i=0; i<dial.length(); i++){
		dial[i] -= 65;
		if (dial[i] > 17) dial[i] -= 1;
		if (dial[i] == 24) dial[i] -= 1;
		cnt = 3 + (int)dial[i] / 3;
		sum += cnt;
	}
	cout << sum;
	return 0;
}