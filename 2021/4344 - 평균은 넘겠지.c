#include <stdio.h>
int C, N;
int score[1000];
int sum, cnt;
double avg;
int main(void) {
	scanf_s("%d", &C);
	for (int i = 0; i < C; i++) {
		cnt = 0, sum = 0;
		scanf_s("%d", &N);
		for (int j = 0; j < N; j++) {
			scanf_s("%d", &score[j]);
			sum += score[j];
		}
		for (int j = 0; j < N; j++) {
			avg = (double)sum / N;
			if (score[j] > avg) cnt++;
		}
		printf("%.3lf%%\n", (double)cnt * 100 / N);
	}
	return 0;
}