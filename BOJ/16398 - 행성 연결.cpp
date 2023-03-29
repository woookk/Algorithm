//
//  16398 - 행성 연결.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/03/29.
//

#include <iostream>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int N;
int C[1001][1001];

vector<bool> isMST(1001);
int cnt;
long long ans;

int main() {
    FASTIO
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> C[i][j];
        }
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    isMST[1] = true;
    
    for (int i = 2; i <= N; i++) {
        pq.push({C[1][i], i});
    }
    
    while (cnt < N - 1) {
        auto cur = pq.top();
        pq.pop();
        
        if (isMST[cur.Y]) continue;
        isMST[cur.Y] = true;
        ans += cur.X;
        cnt++;
        
        for (int i = 1; i <= N; i++) {
            if (isMST[i]) continue;
            pq.push({C[cur.Y][i], i});
        }
    }
    cout << ans;
    return 0;
}
