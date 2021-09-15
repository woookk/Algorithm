#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int T, x1, y1, r1, x2, y2, r2, Cp = -1;
	double d;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		d = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
		if (d == 0 && r1 == r2) Cp = -1;
		
		else if (d <r1 || d<r2) {
			if (abs(r2 - r1) == d) Cp = 1;
			else if (abs(r2 - r1) > d) Cp = 0;
			else Cp = 2;
		}
		else {
			if (r1 + r2 == d) Cp = 1;
			else if (r1 + r2 > d) Cp = 2;
			else if (r1 + r2 < d) Cp = 0;
		}
		cout << Cp << "\n";
	}
	return 0;
}