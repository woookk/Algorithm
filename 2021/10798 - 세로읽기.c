#include<stdio.h>
char str[5][16];

int main(void) {
	for (int i = 0; i < 5; i++) {
		scanf_s("%s", str[i], sizeof(str[i]));
	}

	for (int i = 0; i < 15; i++)
		printf("%c\n", str[0][i]);


	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 5; j++) {
			if (str[j][i] == NULL) continue;
			printf("%c", str[j][i]);
		}
	}
	return 0;
}