//
// Created by 민병욱 on 2023/03/08.
//
#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

int n;
ll a[500001];
ll prefix[500001];

ll ans;
ll total, cnt;

int main() {
    FASTIO
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
    }

    total = prefix[n];
    if (total % 3 != 0) {
        ans = 0;
    }

    else {
        total /= 3;
        for (int i = 1; i < n; i++) {
            if (prefix[i] == total * 2) {
                ans += cnt;
            }

            if (prefix[i] == total) {
                cnt++;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}