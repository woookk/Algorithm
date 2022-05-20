//
//  2240 - 자두나무.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/20.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int T, W;
int num[1001], d[1001][31][3];

int main(){
    FASTIO;
    cin >> T >> W;
    for(int i = 1; i <= T; i++){
        cin >> num[i];
    }
    
    for(int i = 1; i <= T; i++){
        d[i][0][1] = d[i - 1][0][1] + (num[i] == 1 ? 1 : 0);
        for(int j = 1; j <= W; j++){
            if(i < j) break;
            if(num[i] == 1) {
                d[i][j][1] = max(d[i - 1][j - 1][2], d[i - 1][j][1]) + 1;
                d[i][j][2] = max(d[i - 1][j - 1][1], d[i - 1][j][2]);
            }
            else {
                d[i][j][1] = max(d[i - 1][j - 1][2], d[i - 1][j][1]);
                d[i][j][2] = max(d[i - 1][j - 1][1], d[i - 1][j][2]) + 1;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= W; i++){
        ans = max({ans, d[T][i][1], d[T][i][2]});
    }
    cout << ans;
    return 0;
}
