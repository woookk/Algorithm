#include <stdio.h>
int n[10];
int count = 0, result = 0;
int main(void) {
	for (int i = 0; i < 10; i++) {
		scanf_s("%d", &n[i]);
		n[i] = n[i] % 42;
	}
	for (int i = 0; i < 10; i++) {
		count = 0;
		for (int j = i+1; j < 10; j++) {
			if (n[i] == n[j]) count++;
		} 
		if (count == 0) result++;
	}
	printf("%d", result);
		return 0;
}