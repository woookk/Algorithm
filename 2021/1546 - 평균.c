#include <stdio.h>
int N;
double s[1000] = { 0 };
double max; double sum = 0;
int main(void) {
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf_s("%lf", &s[i]);
		if (s[i] > max)
			max = s[i];
	}
	for (int i = 0; i < N; i++) {
		s[i] = (s[i] / max) * 100;
		sum += s[i];
	}
	printf("%lf", sum/N);
	return 0;
}