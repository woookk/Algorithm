//
// Created by 민병욱 on 2023/02/21.
//
#include <iostream>
#include <vector>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, R, Q, U, V;
vector<int> adj[100001];
int nodes[100001];

int dfs(int cur) {
    nodes[cur] = 1;
    for (int nx: adj[cur]) {
        if (nodes[nx]) continue;
        nodes[cur] += dfs(nx);
    }
    return nodes[cur];
}

int main() {
    FASTIO
    cin >> N >> R >> Q;
    for (int i = 0; i < N - 1; i++) {
        cin >> U >> V;
        adj[U].push_back(V);
        adj[V].push_back(U);
    }

    dfs(R);

    for (int i = 0; i < Q; i++) {
        cin >> U;
        cout << nodes[U] << "\n";
    }
    return 0;
}