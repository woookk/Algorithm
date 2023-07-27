//
//  14226 - 이모티콘.cpp
//  cpp
//
//  Created by 민병욱 on 2023/07/27.
//

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int MX = 1024 + 1;
int S;
int dist[MX][MX];
int ans;

static void BFS() {
    queue<pair<int, int>> q;
    q.push({0, 1});
    dist[0][1] = 1;
    
    while (!q.empty()) {
        auto [saved, cur] = q.front();
        q.pop();
        if (cur == S) {
            cout << dist[saved][cur] - 1;
            break;
        }
        
        if (!dist[cur][cur]) {
            dist[cur][cur] = dist[saved][cur] + 1;
            q.push({cur, cur});
        }
        
        for (int nx: {cur - 1, cur + saved}) {
            if (nx <= 0 || nx > MX) continue;
            if (dist[saved][nx]) continue;
            dist[saved][nx] = dist[saved][cur] + 1;
            q.push({saved, nx});
        }
    }
}

int main() {
    FASTIO
    cin >> S;
    BFS();
    return 0;
}


/*
 초기 이모티콘 1개
 3가지 연산만 사용해서 이모티콘을 S개 만들어야한다.
 1. 화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장 (이전에 클립보드에 있던 내용은 덮어쓰기)
 2. 클립보드에 있는 모든 이모티콘을 화면에 붙여넣기
 3. 화면에 있는 이모티콘 중 하나를 삭제 (클립보드에 있는 이모티콘 수 <= 화면에 있는 이모티콘 수)
 모든 연산이 1초가 걸릴 때 S개의 이모티콘을 화면에 만드는데 걸리는 시간의 최솟값
 
 dist[MX][MX] 배열 선언한 후 {클립보드에 저장된 개수, 현재 이모티콘 수}별로 도달 시간을 업데이트 하는 방식으로 BFS 탐색.
 */
