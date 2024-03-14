//
//  9205 - 맥주 마시면서 걸어가기.cpp
//  cpp
//
//  Created by 민병욱 on 2024/03/14.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int TC;

int getDistance(vector<pair<int, int>>& point, int i, int j) {
    return abs(point[i].X - point[j].X) + abs(point[i].Y - point[j].Y);
}

int main() {
    FASTIO
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;
        vector<pair<int, int>> point(n + 2);
        vector<bool> visited(n + 2, false);
        for (int i = 0; i < n + 2; i++) {
            cin >> point[i].X >> point[i].Y;
        }
        queue<int> q;
        q.push(0);
        visited[0] = true;
        
        bool ans = false;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            
            if (getDistance(point, cur, n + 1) <= 1000) {
                ans = true;
                break;
            }
            
            for (int i = 0; i < n + 1; i++) {
                if (visited[i]) continue;
                if (getDistance(point, cur, i) > 1000) continue;
                visited[i] = true;
                q.push(i);
            }
        }
        if (ans) {
            cout << "happy\n";
        }
        else {
            cout << "sad\n";
        }
    }
    return 0;
}

/*
 락 페스티벌에 맥주를 마시면서 걸어가기로 했다.
 출발은 상근이네 집에서 하고, 맥주 한 박스를 들고 출발한다. (한 박스에는 맥주 20개)
 목이 마르면 안되기 때문에 50미터에 한 병씩 마시려고 한다. 즉, 50미터를 가려면 그 직전에 맥주 한 병을 마셔야 한다.
 상근이네 집에서 페스티벌이 열리는 곳이 매우 먼 거리이기 때문에 맥주를 더 구매해야 할 수도 있다. 편의점에 들렀을 때, 빈 병은 버리고 새 맥주 병을 살 수 있다. 하지만, 박스에 들어있는 맥주는 20병을 넘을 수 없다.
 편의점, 상근이네 집, 락 페스티벌의 좌표가 주어질 때, 페스티벌에 도착할 수 있는지를 구하는 프로그램을 작성
 
 
 */
