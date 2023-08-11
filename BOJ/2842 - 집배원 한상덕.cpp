//
//  2842 - 집배원 한상덕.cpp
//  cpp
//
//  Created by 민병욱 on 2023/08/11.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[] = {0, 1, 0, -1, 1, -1, -1, 1};

int N, K;
char board[55][55];
int height[55][55];
int visited[55][55];

pair<int, int> P;
vector<int> incline;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'P') {
                P.first = i;
                P.second = j;
            }
            if (board[i][j] == 'K') {
                K++;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> height[i][j];
            incline.push_back(height[i][j]);
        }
    }
    sort(incline.begin(), incline.end());
}

bool BFS(int minHeight, int maxHeight) {
    for (int i = 0; i < N; i++) {
        fill(visited[i], visited[i] + N + 1, 0);
    }
    
    queue<pair<int, int>> q;
    if (height[P.first][P.second] < minHeight || height[P.first][P.second] > maxHeight) return false;
    q.push(P);
    visited[P.first][P.second] = 1;
    
    int count = 0;
    while (!q.empty()) {
        auto [curX, curY] = q.front();
        q.pop();
        
        for (int dir = 0; dir < 8; dir++) {
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (visited[nx][ny]) continue;
            if (height[nx][ny] < minHeight || height[nx][ny] > maxHeight) continue;
            if (board[nx][ny] == 'K') count++;
            q.push({nx, ny});
            visited[nx][ny] = 1;
        }
    }
    if (count == K) return true;
    return false;
}

bool isPossible(int low, int high) {
    if (low > 0 && incline[low] == incline[low - 1]) {
        return true;
    }
    if (high < incline.size() - 1 && incline[high] == incline[high + 1]) {
        return false;
    }
    return BFS(incline[low], incline[high]);
}

int getMinTireness() {
    int ans = 1e6;
    int low = 0, high = 0;
    while (low < incline.size() && high < incline.size()) {
        if (isPossible(low, high)) {
            ans = min(ans, incline[high] - incline[low]);
            low++;
        }
        else {
            high++;
        }
    }
    return ans;
}

int main() {
    FASTIO
    input();
    cout << getMinTireness();
    return 0;
}
