//
// Created by 민병욱 on 2023/02/11.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int n, m, t;
vector<int> party[52];
vector<int> adj[52];
bool truth[52];
int cnt;

void bfs() {
    queue<int> q;
    for(int i = 1; i <= n; i++)
        if(truth[i]) q.push(i);

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int nx : adj[cur]) {
            if(truth[nx]) continue;
            truth[nx] = 1;
            q.push(nx);
        }
    }
}

int main(void){
    FASTIO
    cin >> n >> m >> t;

    for (int i = 0; i < t; i++) {
        int idx;
        cin >> idx;
        truth[idx] = 1;
    }

    for(int i = 0; i < m; i++) {
        int num; cin >> num;

        int prev, next;
        cin >> prev;
        party[i].push_back(prev);

        while(--num) {
            cin >> next;
            party[i].push_back(next);
            adj[next].push_back(prev);
            adj[prev].push_back(next);
            swap(prev, next);
        }
    }

    bfs();

    for(int i = 0; i < m; i++) {
        bool known = 0;
        for(int p : party[i]) {
            if(truth[p]) known = 1;
        }
        if(!known) cnt++;
    }
    cout << cnt;
}