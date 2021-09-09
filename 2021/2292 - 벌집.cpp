#include<iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		if (N <= 3*(i+1)*i + 1) { cout << i+1; break; }
	}
	return 0;
}