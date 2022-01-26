#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int arr[1000001];
int cnt[1000001];
int NGF[1000001];

int main() {
	FASTIO;
	int N;
	cin >> N;
	stack<int> s;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		cnt[arr[i]]++;
	}
	for (int i = 1; i <= N; i++) {
		while (!s.empty() && cnt[arr[s.top()]] < cnt[arr[i]]) {
			NGF[s.top()] = arr[i];
			s.pop();
		}
		s.push(i);
	}

	for (int i = 1; i <= N; i++) {
		if (NGF[i] == 0) NGF[i] = -1;
		cout << NGF[i] << " ";
	}
	return 0;
}