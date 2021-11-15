#include<iostream>
#include<algorithm>
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int N, M, tree[1000000], maxi = 0;

int BinarySearch() {
	int start = 0;
	int end = maxi;
	int mid, temp=0;
	

	while (end - start >= 0) {
		long long int sum = 0;
		mid = (start + end) / 2;

		for (int i = 0; i < N; i++) {
			if (tree[i] > mid) {
				sum += tree[i];
				sum -= mid;
			}
			else continue;
		}

		if (sum == M)
			return mid;

		else if (sum > M) {
			temp = mid;
			start = mid + 1;
		}
		else end = mid - 1; 
	}
	return temp;
}

int main() {
	FASTIO;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> tree[i];
		if (tree[i] > maxi) maxi = tree[i];
	}
	cout << BinarySearch();
	return 0;
}