#include <stdio.h>
int N, F, a;
int main(void) {
	scanf_s("%d %d", &N, &F);
	a = N / 100; // a: 백의자릿수
	for (int i = 0; i < F; i++) {
		N = 100*a + i;
		if (N % F == 0)
			break;
	}
	printf("%.2d\n", N%100);
	return 0;
}