#include <stdio.h>
int T, score = 0;
char ox[80];
int main(void) {
	scanf_s("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf_s("%s", ox, sizeof(ox));
		score = 0;
		for (int j = 0; j < sizeof(ox); j++) {
			if (ox[j] == 'O') {
				score++;
				for (int k = 0; k < j; k++) {
					if (ox[j] == ox[j - k - 1]) score++;
					else break;
				}
			}
			if (ox[j] == NULL) break;			
		} printf("%d\n", score);
	}
	return 0;
}