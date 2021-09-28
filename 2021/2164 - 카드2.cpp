#include<iostream>
#include<queue>
using namespace std;
int main() {
	queue<int> q;
	int N, temp;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	while (q.size() > 1) {
		q.pop();
		temp = q.front();
		q.pop();
		q.push(temp);
	}
	cout << q.front();
	return 0;
}