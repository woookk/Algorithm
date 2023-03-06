//
// Created by 민병욱 on 2023/03/03.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int MX = 1000001;

int N;
int u, v;
vector<int> adj[MX];
vector<int> tree[MX];
vector<int> state[MX];

void mktree(int cur, int prev) {
    for (int nx: adj[cur]) {
        if (nx == prev) continue;
        tree[cur].push_back(nx);
        mktree(nx, cur);
    }
}

int dp(int cur, bool isEarlyAdaptor) {
    if (state[cur][isEarlyAdaptor] != -1)
        return state[cur][isEarlyAdaptor];

    int val = 0;
    if (isEarlyAdaptor) {
        for (int nx: tree[cur]) {
            val += min(dp(nx, false), dp(nx, true));
        }
    }
    else {
        for (int nx : tree[cur]) {
            val += dp(nx, true);
        }
    }
    return state[cur][isEarlyAdaptor] = val + isEarlyAdaptor;
}

int main() {
    FASTIO
    cin >> N;

    for (int i = 1; i <= N; i++) {
        state[i].push_back(-1);
        state[i].push_back(-1);
    }

    for (int i = 0; i < N - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    mktree(1, -1);

    cout << min(dp(1, false), dp(1, true));
    return 0;
}