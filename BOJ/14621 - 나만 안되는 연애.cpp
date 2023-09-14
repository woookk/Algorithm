//
//  14621 - 나만 안되는 연애.cpp
//  cpp
//
//  Created by 민병욱 on 2023/09/13.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int N, M;
vector<pair<int, int>> adj[1001];

int isMale[1001];
bool isMST[1001];
int cnt, ans;

int main() {
    FASTIO
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        char gender;
        cin >> gender;
        if (gender == 'M') {
            isMale[i] = 1;
        }
        else {
            isMale[i] = 0;
        }
    }
    
    for (int i = 0; i < M; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        if (isMale[u] == isMale[v]) continue;
        adj[u].push_back({d, v});
        adj[v].push_back({d, u});
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    isMST[1] = true;
    for (auto nx: adj[1]) {
        pq.push({nx.X, nx.Y});
    }
    
    while (cnt < N - 1) {
        if (pq.empty()) {
            cout << -1 << "\n";
            return 0;
        }
        
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
    cout << ans;
    return 0;
}

/*
 사용자들을 위해 사심 경로를 제공. 3가지 특징 가지고 있다.
 1. 사심 경로는 사용자들의 사심을 만족시키기 위해 남초 대학교와 여초 대학교들을 연결하는 도로로만 이루어져있다.
 2. 사용자들이 다양한 사람과 미팅할 수 있도록 어떤 대학교에서는 어떤 대학교에서든 모든 대학교로 이동이 가능한 경로이다.
 3. 시간을 낭비하지 않고 미팅할 수 있도록 이 경로의 길이는 최단 거리가 되어야 한다.
 
 
 */
