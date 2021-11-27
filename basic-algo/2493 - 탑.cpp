#include<iostream>
#include<stack>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int main() {
	FASTIO;

	int N;
	cin >> N;

	stack<pair<int, int>> tower;
	tower.push({ 100000001, 0 });
	for (int i = 1; i <= N; i++) {
		int temp;
		cin >> temp;
		while (tower.top().first < temp) 
			tower.pop();
		cout << tower.top().second << " ";
		tower.push({ temp, i });
	}
	return 0;
}