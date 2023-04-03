//
//  2887 - 행성 터널.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/04/02.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second
#define MX 100001

int N;
pair<int, int> x[MX];
pair<int, int> y[MX];
pair<int, int> z[MX];

vector<bool> isMST(MX);
vector<pair<int, int>> adj[MX];
int cnt, ans;

int main() {
    FASTIO
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int curX, curY, curZ;
        cin >> curX >> curY >> curZ;
        x[i] = make_pair(curX, i);
        y[i] = make_pair(curY, i);
        z[i] = make_pair(curZ, i);
    }
    
    sort(x + 1, x + N + 1);
    sort(y + 1, y + N + 1);
    sort(z + 1, z + N + 1);
    
    adj[x[1].Y].push_back({abs(x[2].X - x[1].X), x[2].Y});
    adj[y[1].Y].push_back({abs(y[2].X - y[1].X), y[2].Y});
    adj[z[1].Y].push_back({abs(z[2].X - z[1].X), z[2].Y});
    for (int i = 2; i <= N - 1; i++) {
        adj[x[i].Y].push_back({abs(x[i + 1].X - x[i].X), x[i + 1].Y});
        adj[x[i].Y].push_back({abs(x[i].X - x[i - 1].X), x[i - 1].Y});
        
        adj[y[i].Y].push_back({abs(y[i + 1].X - y[i].X), y[i + 1].Y});
        adj[y[i].Y].push_back({abs(y[i].X - y[i - 1].X), y[i - 1].Y});
        
        adj[z[i].Y].push_back({abs(z[i + 1].X - z[i].X), z[i + 1].Y});
        adj[z[i].Y].push_back({abs(z[i].X - z[i - 1].X), z[i - 1].Y});
    }
    adj[x[N].Y].push_back({abs(x[N].X - x[N - 1].X), x[N - 1].Y});
    adj[y[N].Y].push_back({abs(y[N].X - y[N - 1].X), y[N - 1].Y});
    adj[z[N].Y].push_back({abs(z[N].X - z[N - 1].X), z[N - 1].Y});
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    isMST[1] = true;
    for (auto nx : adj[1]) {
        pq.push({nx.X, nx.Y});
    }
    
    while (cnt < N - 1) {
        auto cur = pq.top();
        pq.pop();
        
        if (isMST[cur.Y]) continue;
        isMST[cur.Y] = true;
        cnt++;
        ans += cur.X;
        
        for (auto nx : adj[cur.Y]) {
            if (isMST[nx.Y]) continue;
            pq.push({nx.X, nx.Y});
        }
    }
    
    cout << ans << "\n";
    return 0;
}
