#include <stdio.h>
int T, score = 0; 
int cnt = 0;
char ox[80];
int main(void) {
	scanf_s("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf_s("%s", ox, sizeof(ox));
		cnt, score = 0;
		for (int j = 0; j < sizeof(ox); j++) {
			if (ox[j] == 'O') {
				cnt++;
				score = score + cnt;
			}
			else cnt = 0;

			if (ox[j] == NULL) break;
		}
		printf("%d\n", score);
	}
	return 0;
}