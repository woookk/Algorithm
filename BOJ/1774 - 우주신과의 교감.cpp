//
//  1774 - 우주신과의 교감.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/03/31.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int N, M;
int a, b;
pair<int, int> space[1001];
vector<int> isMST(1001);

int cnt;
double ans;

double adj[1001][1001];

double dist(long long x1, long long x2, long long y1, long long y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;

int main() {
    FASTIO
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> space[i].X >> space[i].Y;
    }
    
    for (int i = 0; i <= N; i++) {
        fill(adj[i], adj[i] + N + 1, LONG_LONG_MAX);
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            adj[i][j] = dist(space[i].X, space[j].X, space[i].Y, space[j].Y);
        }
    }
    
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        adj[a][b] = 0;
        adj[b][a] = 0;
    }
    
    isMST[a] = true;
    for (int i = 1; i <= N; i++) {
        pq.push({adj[a][i], i});
    }
    
    while (cnt < N - 1) {
        auto cur = pq.top();
        pq.pop();
        
        if (isMST[cur.Y]) continue;
        
        isMST[cur.Y] = true;
        cnt++;
        ans += cur.X;
        
        for (int i = 1; i <= N; i++) {
            if (isMST[i]) continue;
            pq.push({adj[cur.Y][i], i});
        }
    }
    
    cout << fixed;
    cout.precision(2);
    cout << ans << "\n";
    return 0;
}
