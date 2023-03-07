//
// Created by 민병욱 on 2023/03/08.
//
#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int n, k;
int a[5001];
int prefix[5001];
double ans;

int main() {
    FASTIO
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
    }

    for (int i = k; i <= n; i++) {
        for (int j = 0; j <= n - i; j++) {
            ans = max(ans, (double) (prefix[j + i] - prefix[j]) / i);
        }
    }
    cout << fixed;
    cout.precision(10);
    cout << ans;
    return 0;
}