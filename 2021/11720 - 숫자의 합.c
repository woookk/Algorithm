#include <stdio.h>
int N;
int sum;
char num[101];
int main(void) {
	scanf_s("%d", &N);
	scanf_s("%s", num, sizeof(num));
	for (int i = 0; i < N; i++)
		sum += num[i]-48;
		printf("%d\n", sum);
	return 0;
}