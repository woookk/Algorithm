//
//  1325 - 효율적인 해킹.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/03/26.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M;
const int MAX = 10001;
vector<int> trust[MAX];
bool visited[MAX];
queue<int> q;
vector<pair<int, int>> v;
int cnt = 1;

void BFS(int v) {
    visited[v] = true;
    q.push(v);
 
    while (!q.empty()) {
        v = q.front();
        q.pop();
 
        for (int w = 0; w < trust[v].size(); w++) {
            int nv = trust[v][w];
            
            if (visited[nv] == 0) {
                visited[nv] = true;
                q.push(nv);
                cnt++;
            }
        }
    }
}
 
void resetVisit() {
    for (int i = 0; i <= N; i++) {
        visited[i] = 0;
    }
}
 
int main() {
    cin >> N >> M;
    for(int i=0;i<M;i++) {
        int a, b;
        cin >> a >> b;
        trust[b].push_back(a);
    }
 
    for (int i = 1; i <= N; i++) {
        cnt = 1;
        resetVisit();
        BFS(i);
        v.push_back({i, cnt});
    }
 
    int maxcnt = -1;
    for (int i = 0; i < v.size(); i++) {
        if (v[i].second > maxcnt) {
            maxcnt = v[i].second;
        }
    }
 
    for (int i = 0; i < v.size(); i++) {
        if (v[i].second == maxcnt) {
            cout << v[i].first << " ";
        }
    }
    return 0;
}
