//
//  1149 - RGB거리.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/13.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
int d[1001][3];
int r[1001], g[1001], b[1001];

int main(){
    FASTIO;
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> r[i] >> g[i] >> b[i];
    }
    d[1][0] = r[1];
    d[1][1] = g[1];
    d[1][2] = b[1];
    for(int i = 2; i <= N; i++){
        d[i][0] = min(d[i - 1][1], d[i - 1][2]) + r[i];
        d[i][1] = min(d[i - 1][0], d[i - 1][2]) + g[i];
        d[i][2] = min(d[i - 1][0], d[i - 1][1]) + b[i];
    }
    cout << min({d[N][0], d[N][1], d[N][2]});
    return 0;
}
