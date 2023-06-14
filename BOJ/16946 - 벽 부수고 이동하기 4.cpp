//
//  16946 - 벽 부수고 이동하기 4.cpp
//  cpp
//
//  Created by 민병욱 on 2023/06/14.
//

#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int rows, cols;

void exploreArea(int x, int y, vector<string>& grid, vector<vector<int>>& visited, vector<int>& areas, int areaIdx) {
    queue<pair<int, int>> q;
    visited[x][y] = areaIdx;
    q.push({ x, y });

    int area = 1;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || ny < 0 || nx >= rows || ny >= cols)
                continue;
            if (visited[nx][ny])
                continue;
            if (grid[nx][ny] != '0')
                continue;

            visited[nx][ny] = areaIdx;
            area++;
            q.push({ nx, ny });
        }
    }
    areas.push_back(area);
}

int main() {
    FASTIO
    cin >> rows >> cols;

    vector<string> grid(rows);
    for (int i = 0; i < rows; i++) {
        cin >> grid[i];
    }

    vector<vector<int>> visited(rows, vector<int>(cols, 0));
    vector<int> areas;

    int areaIdx = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] != '0' || visited[i][j])
                continue;

            exploreArea(i, j, grid, visited, areas, areaIdx++);
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == '0') {
                cout << '0';
                continue;
            }

            unordered_set<int> surrounded;
            int sum = 1;
            for (int dir = 0; dir < 4; dir++) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];

                if (nx < 0 || ny < 0 || nx >= rows || ny >= cols)
                    continue;
                if (grid[nx][ny] == '1')
                    continue;

                areaIdx = visited[nx][ny];
                if (surrounded.find(areaIdx) != surrounded.end())
                    continue;

                surrounded.insert(areaIdx);
                sum += areas[areaIdx - 1];
            }
            cout << sum % 10;
        }
        cout << '\n';
    }
    return 0;
}

/*
 N * M 행렬로 표현되는 맵. 0은 이동할 수 있는 곳, 1은 이동할 수 없는 벽이 있는 곳.
 다른 칸으로 이동하려면, 두 칸이 인접(변을 공유)해야한다.
 
 각각의 벽에 대해서 벽을 부수고 이동할 수 있는 곳으로 변경한 후 그 위치에서 이동할 수 있는 칸의 개수를 구하려고 한다.
 
 BFS를 돌려서 벽을 제외한 각 지역별 넓이를 구하고 각각의 벽에 대해서 인접한 지역 넓이를 더해주면 된다.
 */
