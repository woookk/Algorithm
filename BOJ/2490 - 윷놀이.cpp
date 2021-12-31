#include<iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int main() {
	int A, B, C, D;
	for (int i = 0; i < 3; i++) {
		cin >> A >> B >> C >> D;
		int sum = A + B + C + D;
		if (sum == 0) 
			cout << "D\n";
		else if (sum == 1)
			cout << "C\n";
		else if (sum == 2)
			cout << "B\n";
		else if (sum == 3)
			cout << "A\n";
		else 
			cout << "E\n";

	}
	return 0;
}
// 이런 방식으로도 풀이 가능.
/*
string res = "DCBAE"; 
for(int r = 0; r < 3; r++) {
	result = 0;
	for(int c = 0; c < 4; c++) {
	  cin >> input;
	  result += input;
	}
	cout << res[result] << '\n';
  }
*/