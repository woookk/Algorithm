//
// Created by 민병욱 on 2023/03/20.
//
#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int n;
int a[101];
int total, sum, ans;

bool cmp(int a, int b) {
    if (a > b) return true;
    return false;
}

int main() {
    FASTIO
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
    }

    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (sum > total / 2) {
            ans = i + 1;
            break;
        }
    }

    cout << ans << "\n";
    return 0;
}