//
//  1368 - 물대기.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/03/28.
//

#include <iostream>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int N;
int W[301];
int P[301][301];

bool isMST[301];
int cnt, ans;

int main() {
    FASTIO
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> W[i];
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> P[i][j];
        }
    }
    
    for (int i = 1; i <= N; i++) {
        P[0][i] = W[i];
        P[i][0] = W[i];
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    isMST[0] = true;
    for (int i = 1; i <= N; i++) {
        if (P[0][i]) {
            pq.push({P[0][i], i});
        }
    }
    
    while (cnt < N) {
        auto cur = pq.top();
        pq.pop();
        
        if (isMST[cur.Y]) continue;
        isMST[cur.Y] = true;
        cnt++;
        ans += cur.X;
        
        for (int i = 0; i <= N; i++) {
            if (isMST[i]) continue;
            pq.push({P[cur.Y][i], i});
        }
    }
    
    cout << ans;
    return 0;
}
