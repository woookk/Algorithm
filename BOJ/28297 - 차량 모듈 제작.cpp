//
//  28297 - 차량 모듈 제작.cpp
//  cpp
//
//  Created by 민병욱 on 2023/07/01.
//

#include <iostream>
#include <tuple>
#include <math.h>
#include <queue>
#include <algorithm>
using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int N;
tuple<int, int, int> gear[1005];
vector<pair<double, int>> adj[1005];
int cnt;
double ans;

double getDistance(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

double getEnclosingLength(int x1, int y1, int r1, int x2, int y2, int r2) {
    double dist = getDistance(x1, y1, x2, y2);
    return 2 * (M_PI * max(r1, r2) - acos(abs(r1 - r2)/dist) * abs(r1 - r2) + sqrt(dist * dist - abs(r1 - r2) * abs(r1 - r2)));
}



int main() {
    FASTIO
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        gear[i] = {x, y, r};
    }
    
    for (int i = 1; i < N; i++) {
        for (int j = i + 1; j <= N; j++) {
            int x1, y1, r1, x2, y2, r2;
            tie(x1, y1, r1) = gear[i];
            tie(x2, y2, r2) = gear[j];
            if (getDistance(x1, y1, x2, y2) <= r1 + r2) {
                adj[i].push_back({0, j});
                adj[j].push_back({0, i});
                continue;
            }
            else {
                double dist = getEnclosingLength(x1, y1, r1, x2, y2, r2);
                adj[i].push_back({dist, j});
                adj[j].push_back({dist, i});
            }
        }
    }
    
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    vector<bool> isMST(1005, 0);
    
    isMST[1] = true;
    for (auto nx : adj[1]) {
        pq.push({nx.X, nx.Y});
    }
        
    while (cnt < N - 1) {
        auto cur = pq.top();
        pq.pop();
        
        if (isMST[cur.Y]) continue;
        isMST[cur.Y] = 1;
        cnt++;
        ans += cur.X;
        
        for (auto nx: adj[cur.Y]) {
            if (!isMST[nx.Y])
            pq.push({nx.X, nx.Y});
        }
    }
    cout << fixed;
    cout.precision(10);
    cout << ans;
    return 0;
}
