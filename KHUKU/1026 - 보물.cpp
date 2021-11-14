#include<iostream>
#include<algorithm>
using namespace std;

int N, A[50], B[50], C[50], s = 0;

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
		C[i] = B[i];
	}
	sort(A, A + N);
	sort(C, C + N, greater<int>());
	for (int i = 0; i < N; i++) {
		s += A[i] * C[i];
	}
	cout << s;
	return 0;
}

//S = A[0] * B[0] + A[1] * B[1] + A[2] * B[2] + A[3] * B[3]일 때 A배열의 원소들을 마음껏 재배열 할 수 있으므로 S = A[0] * B[0] + A[3] * B[1] + A[2] * B[2] + A[1] * B[3] 또한 가능할 것이다.
//이 때 항의 순서를 재배열하면 S = A[0] * B[0] + A[1] * B[3] + A[2] * B[2] + A[3] * B[1]이므로 A배열의 원소들을 재배치 할 수 있다는 것은 B배열의 원소들 또한 재배치 할 수 있다는 것을 의미한다는 것을 알 수 있다.