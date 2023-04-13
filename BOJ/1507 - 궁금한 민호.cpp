//
//  1507 - 궁금한 민호.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/04/12.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
int d[25][25];
bool u[22][22];
int ans;

int main() {
    FASTIO
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> d[i][j];
        }
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            bool isExist = true;
            for (int k = 1; k <= N; k++) {
                if (k == i || k == j) continue;
                
                if (d[i][k] + d[k][j] < d[i][j]) {
                    cout << -1;
                    return 0;
                }
                else if (d[i][k] + d[k][j] == d[i][j]) {
                    isExist = false;
                }
            }
            if (isExist) {
                u[i][j] = u[j][i] = true;
            }
        }
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (u[i][j]) ans += d[i][j];
        }
    }
    cout << ans;
    
    return 0;
}
