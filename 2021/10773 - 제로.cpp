#include<iostream>
#include<stack>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main() {
	FASTIO;
	int K, num, cnt=0, sum=0;
	stack<int> book;
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> num;
		if (num!=0) book.push(num);
		else {
			book.pop();
			cnt++;
		}
	}
	for (int i = 0; i < K - 2*cnt; i++) {
		sum += book.top();
		book.pop();
	}
	cout << sum;
	return 0;
}