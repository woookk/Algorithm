//
// Created by 민병욱 on 2023/03/19.
//
#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int k2, k3, k5, k6;
int num256, num32;
int ans;

int main() {
    FASTIO
    cin >> k2 >> k3 >> k5 >> k6;
    num256 = min(k2, min(k5, k6));
    k2 -= num256;

    num32 = min(k2, k3);
    ans = num256 * 256 + num32 * 32;
    cout << ans << "\n";
    return 0;
}
