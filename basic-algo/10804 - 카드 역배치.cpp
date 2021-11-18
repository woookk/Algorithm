#include<iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int card[21];
int temp[21];

void layout(int start, int end){
	for (int i = start; i < end + 1; i++) {
		temp[i] = card[i];
	}
	for (int i = start; i < end + 1; i++) {
		card[i] = temp[end + start - i];
	}
}
int main() {
	FASTIO;

	for (int i = 0; i < 21; i++) {
		card[i] = i;
	}
	
	for (int i = 0; i < 10; i++) {
		int a, b;
		cin >> a >> b;
		layout(a, b);
	}
	
	for (int i = 1; i < 21; i++) {
		cout << card[i] << " ";
	}
	return 0;
}