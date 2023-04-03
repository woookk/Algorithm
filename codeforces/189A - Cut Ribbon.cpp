//
//  189A - Cut Ribbon.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/04/03.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int n, len[3];
int d[3][4001];
int ans;

int main() {
    FASTIO
    cin >> n >> len[0] >> len[1] >> len[2];
    
    d[0][0] = d[1][0] = d[2][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            if (i - len[j] < 0) {
                d[j][i] = -1;
            }
            else if (i - len[j] == 0) {
                d[j][i] = 1;
            }
            else {
                int prev = max(max(d[0][i - len[j]], d[1][i - len[j]]), d[2][i - len[j]]);
                if (prev == -1) {
                    d[j][i] = -1;
                }
                else {
                    d[j][i] = prev + 1;
                }
            }
        }
    }
    ans = max(max(d[0][n], d[1][n]), d[2][n]);
    cout << ans;
    return 0;
}
