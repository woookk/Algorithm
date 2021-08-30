#include <stdio.h>
int score[5];
int sum;
int main(void) {
	for (int i = 0; i < 5; i++) {
		scanf_s("%d", &score[i]);
		if (score[i] < 40) score[i] = 40;
		sum += score[i];
	}
	printf("%d", sum / 5);
	return 0;
}