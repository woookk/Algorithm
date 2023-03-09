//
// Created by 민병욱 on 2023/03/09.
//
#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;

int TC;
int n;
ll a[100001];
ll prefix[100001];
ll total;
bool ans;

int main() {
    FASTIO
    cin >> TC;
    while (TC--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            prefix[i] = prefix[i - 1] + a[i];
        }
        total = prefix[n];

        ans = true;
        ll mn = 0;
        for (int i = 1; i < n; i++) {
            ll diff = prefix[i] - mn;
            if (diff >= total) ans = false;
            mn = min(mn, prefix[i]);
        }

        mn = prefix[1];
        for (int i = 2; i <= n; i++) {
            ll diff = prefix[i] - mn;
            if (diff >= total) ans = false;
            mn = min(mn, prefix[i]);
        }

        if (ans) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}

