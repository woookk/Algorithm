#include<iostream>
using namespace std;
int a[5], sum=0;
int main() {
	for (int i = 0; i < 5; i++) {
		cin >> a[i];
		sum += a[i] * a[i];
	}
	cout << sum % 10;
	return 0;
}