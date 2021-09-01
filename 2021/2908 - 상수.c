#include<stdio.h>
int a[2];
int main(void) {
	for (int i = 0; i < 2; i++) {
		scanf_s("%d", &a[i]);
		a[i] = a[i] % 10 * 100 + a[i] / 10 % 10 * 10 + a[i] / 100;
	}
	if (a[0] > a[1]) printf("%d", a[0]);
	else printf("%d", a[1]);
	return 0;
}