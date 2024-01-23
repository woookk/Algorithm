//
//  4485 - 녹색 옷 입은 애가 젤다지?.cpp
//  cpp
//
//  Created by 민병욱 on 2024/01/23.
//

#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <tuple>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int INF = INT_MAX;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int N;

int main() {
    FASTIO
    for (int TC = 1; ; TC++) {
        cin >> N;
        if (!N) break;
        vector<vector<int>> board(N, vector<int> (N));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> board[i][j];
            }
        }
        
        vector<vector<int>> dist(N, vector<int> (N, INF));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        dist[0][0] = board[0][0];
        pq.push({dist[0][0], 0, 0});
        
        while (!pq.empty()) {
            auto [distance, curX, curY] = pq.top();
            pq.pop();
            
            if (dist[curX][curY] != distance) continue;
            
            for (int dir = 0; dir < 4; dir++) {
                int nx = curX + dx[dir];
                int ny = curY + dy[dir];
                if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                if (dist[nx][ny] <= dist[curX][curY] + board[nx][ny]) continue;
                dist[nx][ny] = dist[curX][curY] + board[nx][ny];
                pq.push({dist[nx][ny], nx, ny});
            }
        }
        cout << "Problem " << TC << ": " << dist[N - 1][N - 1] << "\n";
    }
    return 0;
}

/**
 젤다의 전설 시리즈의 주인공, 링크는 지금 도둑루피만 가득한 N x N 크기의 동굴의 제일 왼쪽 위에 있다.
 링크는 이 동굴의 반대편 출구, 제일 오른쪽 아래 칸인 [N-1][N-1]까지 이동해야 한다.
 동굴의 각 칸마다 도둑루피가 있는데, 이 칸을 지나면 해당 도둑루피의 크기만큼 소지금을 잃게 된다. 링크는 잃는 금액을 최소로 하여 동굴 건너편까지 이동해야 하며, 한 번에 상하좌우 인접한 곳으로 1칸씩 이동할 수 있다.
 링크가 잃을 수밖에 없는 최소 금액을 구하는 프로그램을 작성
 
 인접한 상하좌우가 연결된 간선이라고 생각하고 다익스트라를 이용하여 풀이를 진행
 */
