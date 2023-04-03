//
//  455A - Boredom.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/04/03.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define MX 100005

int n;
int a[MX];
long long d[2][MX];

int main() {
    FASTIO
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    
    d[0][0] = 0;
    d[1][0] = a[0];
    
    for (int i = 1; i < n; i++) {
        if (a[i - 1] == a[i]) {
            d[0][i] = d[0][i - 1];
            d[1][i] = d[1][i - 1] + a[i];
        }
        else if (a[i] == a[i - 1] + 1) {
            d[0][i] = max(d[0][i - 1], d[1][i - 1]);
            d[1][i] = d[0][i - 1] + a[i];
        }
        else {
            d[0][i] = max(d[0][i - 1], d[1][i - 1]);
            d[1][i] = max(d[0][i - 1], d[1][i - 1]) + a[i];
        }
    }
    cout << max(d[0][n - 1], d[1][n - 1]);
    return 0;
}
