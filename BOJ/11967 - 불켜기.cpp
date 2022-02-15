//
//  11967 - 불켜기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/02/15.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int N, M;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool light[101][101];
bool vis[101][101];

bool is_conn(pair<int, int> nxt) {
  for (int dir = 0; dir < 4; dir++) {
    int nx = nxt.X + dx[dir];
    int ny = nxt.Y + dy[dir];
    if (nx <= 0 || ny <= 0 || nx > N || ny > N) continue;
    if (vis[nx][ny]) return 1;
  }
  return 0;
}

int main(){
    FASTIO;
    cin >> N >> M;
    queue<pair<int, int>> q;
    vector<pair<int, int>> v[101][101];
    for(int i = 0; i < M; i++){
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        v[x][y].push_back({a,b});
    }
    int cnt = 1;
    light[1][1] = 1;
    vis[1][1] = 1;
    q.push({1,1});
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for(auto nxt : v[cur.X][cur.Y]){
            if(light[nxt.X][nxt.Y]) continue;
            if(is_conn(nxt)){
                vis[nxt.X][nxt.Y] = 1;
                q.push({nxt.X, nxt.Y});
            }
            light[nxt.X][nxt.Y] = 1;
            cnt++;
        }
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx <= 0 || ny <= 0 || nx > N || ny >  N) continue;
            if(vis[nx][ny]) continue;
            if(!light[nx][ny]) continue;
            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
    cout << cnt << "\n";
    return 0;
}
