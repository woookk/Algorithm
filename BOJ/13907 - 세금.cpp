//
//  13907 - 세금.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/06/06.
//

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <tuple>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int INF = INT_MAX / 5;

int n, m, k;
int st, en;
int dist[1001][1001];
vector<pair<int, int>> adj[1001];
int sum, ans;

void dijkstra() {
    for (int i = 0; i < n; i++) {
        fill(dist[i], dist[i] + n + 1, INF);
    }
    dist[0][st] = 0;
    
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.push({dist[0][st], st, 0});
    
    while (!pq.empty()) {
        auto [cur_dist, cur_node, cur_cnt] = pq.top();
        pq.pop();

        if (cur_dist != dist[cur_cnt][cur_node]) continue;

        for (auto [nx_dist, nx_node]: adj[cur_node]) {
            if (dist[cur_cnt + 1][nx_node] <= dist[cur_cnt][cur_node] + nx_dist) continue;
            dist[cur_cnt + 1][nx_node] = dist[cur_cnt][cur_node] + nx_dist;
            pq.push({dist[cur_cnt + 1][nx_node], nx_node, cur_cnt + 1});
        }
    }
}

void calc_ans() {
    ans = INT_MAX;
    for (int i = 1; i < n; i++) {
        ans = min(ans, dist[i][en] + i * sum);
    }
    cout << ans << "\n";
}

int main() {
    FASTIO
    cin >> n >> m >> k;
    cin >> st >> en;
    
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({w, b});
        adj[b].push_back({w, a});
    }

    dijkstra();
    calc_ans();
    
    while (k--) {
        int p;
        cin >> p;
        sum += p;
        calc_ans();
    }
    return 0;
}

/*
 두 도시를 오가면서 장사 -> 통행료의 합이 가장 적은 경로로 이동한다.
 도시들은 양방향 도로로 이어져있고, 도로마다 통행료 존재
 
 세금 인상 시 세금이 A만큼 오르면 모든 도로의 통행료가 A만큼 오른다.
 세금이 올랐을 때는 경로별 지나는 도로수에 따라 오르는 비용이 다르게 된다. -> 지나는 도로수 별로 최소 통행료를 구해야한다.
 
 dist 배열을 지나는 도로수, 도착지 이차원 배열로 선언한 후 다익스트라 알고리즘 적용
 */
