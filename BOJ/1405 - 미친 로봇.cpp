//
//  1405 - 미친 로봇.cpp
//  cpp
//
//  Created by 민병욱 on 2024/02/20.
//

#include <iostream>
#include <vector>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int MAX = 100, DIRECTIONS = 4;

const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, 1, -1 };

int N;
double ans;

void solve(vector<vector<bool>>& visited, vector<double>& probability, int x, int y, double prob, int depth) {
    
    if (visited[x][y]) return;
    
    visited[x][y] = true;
    if (depth == N) {
        ans += prob;
        visited[x][y] = false;
        return;
    }
    
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        solve(visited, probability, nx, ny, prob * probability[dir], depth + 1);
    }
    visited[x][y] = false;
}

int main() {
    FASTIO
    cin >> N;
    vector<vector<bool>> visited(MAX, vector<bool>(MAX, false));
    vector<double> probability(DIRECTIONS);
    for (int i = 0; i < DIRECTIONS; i++) {
        int p;
        cin >> p;
        probability[i] = p / 100.0;
    }
    solve(visited, probability, MAX / 2, MAX / 2, 1, 0);
    cout << fixed;
    cout.precision(18);
    cout << ans;
    return 0;
}

/*
 통제 할 수 없는 미친 로봇이 평면위에 있다. 그리고 이 로봇은 N번의 행동을 취할 것이다.
 각 행동에서 로봇은 4개의 방향 중에 하나를 임의로 선택한다. 그리고 그 방향으로 한 칸 이동한다.
 로봇이 같은 곳을 한 번 보다 많이 이동하지 않을 때, 로봇의 이동 경로가 단순하다고 한다. (로봇의 시작 위치가 처음 방문한 곳)
 로봇의 이동 경로가 단순할 확률을 구하는 프로그램을 작성
 
 완전탐색을 이용하여 모든 경우 다 탐색해보는 방식으로 풀이 진행
 N번 이동했을 때 각각의 확률을 더해주는 방식
 
 **각각의 확률이 다르므로 동, 서, 남, 북을 순서대로 입력 받아야 한다. 동쪽, 서쪽이 서로 반대되고, 남쪽, 북쪽이 서로 반대되는데 이 확률들의 순서는 답에 영향을 준다.**
 */
