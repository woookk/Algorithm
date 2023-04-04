//
//  327A - Flipping Game.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/04/04.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int n;
int a[1001], b[1001], d[1001];
int ans;

int main() {
    FASTIO
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i]) {
            ans++;
            b[i] = -1;
        }
        else {
            b[i] = 1;
        }
    }
    d[0] = b[0];
    for (int i = 1; i < n; i++) {
        if (d[i - 1] + b[i] > b[i]) {
            d[i] = d[i - 1] + b[i];
        }
        else {
            d[i] = b[i];
        }
    }
    cout << ans +  *max_element(d, d + n);
    return 0;
}
