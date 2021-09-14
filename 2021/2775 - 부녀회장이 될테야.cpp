#include<iostream>
using namespace std;
int T, k, n, output = 0;

int reculsive(int k, int n) {
	if (k == 0) output += n;
	else if (n == 1) output += 1;
	else reculsive(k - 1, n) + reculsive(k, n - 1);
	return output;
}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> k >> n;
		output = 0;
		cout << reculsive(k, n) << "\n";
	}	
	return 0;
}