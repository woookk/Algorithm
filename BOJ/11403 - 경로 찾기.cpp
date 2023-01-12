//
//  11403 - 경로 찾기.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/01/12.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
vector<int> node[101];
int vis[101];

void DFS(int cur) {
    for (int i = 0; i < node[cur].size(); i++) {
        int nx = node[cur][i];
        if (!vis[nx]) {
            vis[nx] = 1;
            DFS(nx);
        }
    }
}

int main() {
    FASTIO
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int edge;
            cin >> edge;
            if (edge) node[i].push_back(j);
        }
    }
    
    for (int i = 1; i <= N; i++) {
        fill(vis, vis + 101, 0);
        DFS(i);
        for (int j = 1; j <= N; j++) {
            cout << vis[j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
