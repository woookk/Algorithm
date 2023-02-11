//
// Created by 민병욱 on 2023/02/11.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M;
int cnt;
int ans;

vector<int> is_heavy[101];
vector<int> is_light[101];
bool is_impossible;

int vis[101];

void light_DFS(int cur) {
    vis[cur] = 1;
    cnt++;

    for (int nx: is_light[cur]) {
        if (vis[nx]) continue;
        light_DFS(nx);
    }
}

void heavy_DFS(int cur) {
    vis[cur] = 1;
    cnt++;

    for (int nx: is_heavy[cur]) {
        if (vis[nx]) continue;
        heavy_DFS(nx);
    }
}

int main() {
    FASTIO
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        is_light[a].push_back(b);
        is_heavy[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) {
        cnt = 0;
        fill(vis, vis + N + 1, 0);
        light_DFS(i);
        if (cnt > N / 2 + 1) {
            ans++;
            continue;
        }
        cnt = 0;
        fill(vis, vis + N + 1, 0);
        heavy_DFS(i);
        if (cnt > N / 2 + 1) {
            ans++;
            continue;
        }
    }

    cout << ans;
    return 0;
}