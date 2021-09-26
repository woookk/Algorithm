#include<iostream>
#include<string>
using namespace std;

int titlenum(int N) {
	string t;
	int cnt = 0, i = 666;
	while (1) {
		t = to_string(i);
		for (int j = 0; j < t.length() - 2; j++) {
			if (t[j] == '6' && t[j + 1] == '6' && t[j + 2] == '6') {
				cnt++;
				if (cnt == N)
					return i;
				break;
			}
		}
		i++;
	}
}
int main() {
	int N;
	cin >> N;
	cout << titlenum(N);
	return 0;
}