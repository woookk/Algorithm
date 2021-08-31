#include<stdio.h>
int T, R;
char str[21];
int main(void) {
	scanf_s("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf_s("%d", &R);
		scanf_s("%s", str, sizeof(str));
		for (int j = 0; j < strlen(str); j++) {
			for (int k = 0; k < R; k++) {
				printf("%c", str[j]);
			}
		} printf("\n");
	} 
	return 0;
}