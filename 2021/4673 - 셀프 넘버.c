#include <stdio.h>
int d(int num) {
	int ans = 0;
	if (num < 10)
		ans = num + num % 10;
	else if (num < 100)
		ans = num + num / 10 + num % 10;
	else if (num < 1000)
		ans = num + num / 100 + num % 100 / 10 + num % 10;
	else
		ans = num + num / 1000 + num % 1000 / 100 + num % 100 / 10 + num % 10;
	return ans;
}

int arr[10001] = { 0 };
int main(void) {
	for (int i = 1; i < 10000; i++) {
		arr[d(i)] = 1;
	}
	for (int i = 1; i < 10000; i++) {
		if (arr[i] == 0)
			printf("%d\n", i);
	}
	return 0;
}