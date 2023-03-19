//
// Created by 민병욱 on 2023/03/19.
//
#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int n, s, ans;
int cnt[5];

int main() {
    FASTIO
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        cnt[s]++;
    }

    ans += cnt[4];

    ans += cnt[3];
    cnt[1] -= min(cnt[3], cnt[1]);

    ans += cnt[2] / 2;
    cnt[2] %= 2;

    ans += cnt[2];
    cnt[1] -= min(cnt[2] * 2, cnt[1]);

    ans += (cnt[1] + 3) / 4;

    cout << ans << "\n";
    return 0;
}