//
//  1948 - 임계경로.cpp
//  cpp
//
//  Created by 민병욱 on 2023/08/28.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int MAX = 1e4 + 5;
int n, m;
int st, en;
int ans, cnt;

vector<pair<int, int>> adj[MAX];
vector<pair<int, int>> pre[MAX];
int inDeg[MAX], dist[MAX], visited[MAX];

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        adj[a].push_back({b, cost});
        pre[b].push_back({a, cost});
        inDeg[b]++;
    }
    cin >> st >> en;
}

void calculateMaxPath() {
    queue<pair<int, int>> q;
    q.push({st, 0});
    
    while (!q.empty()) {
        auto [cur, curDist] = q.front();
        q.pop();
        
        for (auto [nx, nxDist]: adj[cur]) {
            dist[nx] = max(dist[nx], curDist + nxDist);
            inDeg[nx]--;
            
            if (!inDeg[nx]) {
                q.push({nx, dist[nx]});
            }
        }
    }
    ans = dist[en];
}

void getNumberOfRoad() {
    queue<int> q;
    q.push(en);
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto [prev, preDist] : pre[cur]) {
            if (dist[cur] - preDist == dist[prev]) {
                cnt++;
                if (!visited[prev]) {
                    visited[prev] = 1;
                    q.push(prev);
                }
            }
        }
    }
}

int main() {
    FASTIO
    input();
    calculateMaxPath();
    getNumberOfRoad();
    cout << ans << "\n" << cnt << "\n";
    return 0;
}

/*
 월드 나라의 지도를 그리기 위해서, 어떤 시작 도시로부터 도착 도시까지 출발을 하여 가능한 모든 경로를 탐색
 이 지도를 그리는 사람들은 사이가 너무 좋아서 지도를 그리는 일을 다 마치고 도착 도시에서 모두 다 만나기로 하였다.
 이들이 만나는 시간은 출발 도시로부터 출발한 후 최소 몇시간 후에 만날 수 있는가?
 
 도착점에 가장 늦게 도착했을 때 걸리는 시간을 구한 후 그 경로에서 지나는 도로의 개수를 구해야한다.
 
 도착점에 가장 늦게 도착했을 때 걸리는 시간을 구하기 위해서 위상정렬을 이용하여 접근
 이후 도착점에서 이전 경로로 돌아가면서 가장 늦게 도착하는 시간에서 간선을 제외하였을 때 최대 시간이라면 가장 오래 걸리는 경로에 포함되는 점인 것을 활용하여 최장 경로에서의 도로의 개수를 구함.
 */
