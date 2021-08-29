#include <stdio.h>
int f(int N) {
	if (N < 100)
		return 1;
	else if (N >= 100 && N / 100 + N % 10 == 2 * (N % 100 / 10))
		return 1;
	else 
		return 0;
}
int N, cnt = 0;;
int main(void) {
	scanf_s("%d", &N);
	for (int i = 1; i <= N; i++) {
		if (f(i) == 1) cnt++;
	}
	printf("%d", cnt);
	return 0;
}