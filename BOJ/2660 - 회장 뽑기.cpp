//
//  2660 - 회장 뽑기.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/01/13.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
vector<int> member[51];
int vis[51];
int score[51];
int mn;
vector<int> ans;

void BFS(int st) {
    queue<int> q;
    q.push(st);
    vis[st] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < member[cur].size(); i++) {
            int nx = member[cur][i];
            if (vis[nx] >= 0) continue;
            vis[nx] = vis[cur] + 1;
            q.push(nx);
        }
    }
}

int main() {
    FASTIO
    cin >> N;
    while (true) {
        int a, b;
        cin >> a >> b;
        if (a == -1 && b == -1) break;
        member[a].push_back(b);
        member[b].push_back(a);
    }
    
    for (int i = 1; i <= N; i++) {
        fill(vis, vis + 51, -1);
        BFS(i);
        score[i] = *max_element(vis + 1, vis + N + 1);
    }
    
    mn = *min_element(score + 1, score + N + 1);
    for (int i = 1; i <= N; i++) {
        if (mn == score[i]) ans.push_back(i);
    }
    
    cout << mn << " " << ans.size() << "\n";
    for (auto v : ans) {
        cout << v << " ";
    }
    return 0;
}
