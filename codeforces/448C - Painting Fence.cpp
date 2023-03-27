//
// Created by 민병욱 on 2023/03/27.
//
#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define MX 5005

int n;
int a[MX];

int solve(int x[], int size) {
    int mn = *min_element(x, x + size);
    for (int i = 0; i < size; i++) {
        x[i] -= mn;
    }

    int ans = mn;
    int p, q;
    p = 0;
    while (p < size) {
        while (p < size && x[p] == 0) p++;
        if (p == size) break;
        q = p;
        while (q + 1 < size && x[q + 1] > 0) q++;
        ans += solve(x + p, q - p + 1);
    }
    return min(size, ans);
}

int main() {
    FASTIO
    cin >> n;
    for (int i = 0 ; i < n; i++) {
        cin >> a[i];
    }
    cout << solve(a, n);
    return 0;
}