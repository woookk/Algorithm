//
//  1525 - 퍼즐.cpp
//  cpp
//
//  Created by 민병욱 on 2024/01/29.
//

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <climits>
#include <algorithm>
using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int N = 3;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int ans = INT_MAX;

int main() {
    FASTIO
    vector<vector<int>> board(N, vector<int>(N));
    string init = "";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            init += board[i][j] + '0';
        }
    }
    
    queue<string> q;
    q.push(init);
    map<string, int> dist;
    dist[init] = 0;
    
    while (!q.empty()) {
        string puzzle = q.front();
        q.pop();
        if (dist[puzzle] > ans) continue;
        if (puzzle == "123456780") {
            ans = min(ans, dist[puzzle]);
            continue;
        }
        
        int zero = puzzle.find('0');
        int curX = zero / N, curY = zero % N;
        for (int dir = 0; dir < 4; dir++) {
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            
            string nxPuzzle = puzzle;
            swap(nxPuzzle[curX * 3 + curY], nxPuzzle[nx * 3 + ny]);
            if (dist.find(nxPuzzle) != dist.end()) continue;
            dist[nxPuzzle] = dist[puzzle] + 1;
            q.push(nxPuzzle);
        }
    }
    if (ans == INT_MAX) ans = -1;
    cout << ans;
    return 0;
}

/*
 3×3 표에 수가 채워져 있다. 초기 상태가 주어졌을 때, 정리된 상태를 만들 수 있는 최소 이동 횟수를 구하는 프로그램 작성
 
 퍼즐을 배열이 아닌 문자열로 저장하여 BFS를 이용한 풀이를 진행
 Map을 이용해서 이전에 방문하였는지 확인한 후 방문하지 않은 퍼즐 상태에 대해서만 방문
 */
