#include<iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
int main() {
	double R;
	cin >> R;
	cout << fixed;
	cout.precision(6);
	cout << M_PI * R * R << "\n" << 2 * R * R;
	return 0;
}