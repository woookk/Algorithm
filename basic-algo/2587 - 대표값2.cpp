#include<iostream>
#include<algorithm>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
	FASTIO;
	int num[5];
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		cin >> num[i];
		sum += num[i];
	}
	sort(num, num + 5);
	cout << sum / 5 << "\n" << num[2];
	return 0;
}