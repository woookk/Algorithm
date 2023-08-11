//
//  1981 - 베열에서 이동.cpp
//  cpp
//
//  Created by 민병욱 on 2023/08/10.
//

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int n;
int arr[105][105];
int visited[105][105];
int minValue = 200, maxValue = 0;

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] > maxValue) maxValue = arr[i][j];
            if (arr[i][j] < minValue) minValue = arr[i][j];
        }
    }
}

bool BFS(int min, int max) {
    queue<pair<int, int>> q;
    q.push({1, 1});
    visited[1][1] = 1;
    
    for (int i = 0; i < 105; i++) {
        fill(visited[i], visited[i] + 105, 0);
    }
    
    while (!q.empty()) {
        auto [curX, curY] = q.front();
        q.pop();
        
        if (curX == n && curY == n) {
            return true;
        }
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            
            if (nx <= 0 || ny <= 0 || nx > n || ny > n) continue;
            if (visited[nx][ny]) continue;
            if (arr[nx][ny] < min || arr[nx][ny] > max) continue;
            visited[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
    return false;
}

bool isPossible(int limit) {
    for (int i = minValue; i <= maxValue - limit; i++) {
        if (arr[1][1] < i || arr[1][1] > i + limit) continue;
        if (BFS(i, i + limit)) return true;
    }
    return false;
}

int main() {
    FASTIO
    input();
    
    int high = maxValue - minValue, low = 0;
    while (low <= high) {
        int mid = (high + low) / 2;
        if (isPossible(mid)) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    cout << low;
    return 0;
}

/*
 n * n짜리 배열 존재. (1, 1) -> (n, n)까지 이동하려고 할 때 지나온 경로에서 최댓값과 최솟값의 차이가 가장 작아지는 경우를 구하는 프로그램
 
 1. 지나온 경로에서 최댓값과 최솟값의 차이가 더 작을 경우 업데이트 ->
 단순히 최댓값과 최솟값의 차이만을 비교하므로 경로에서 더 작은 최솟값이 나타나는 경우 또는 더 큰 최댓값이 나타나는 경우를 제대로 반영하지 못함
 
 2. 이분 탐색을 통해 경로에서의 최솟값, 최댓값을 정한 후
 그 안에 들어가는 값들로만 BFS 탐색 가능한지 확인하는 방식
 
 */
