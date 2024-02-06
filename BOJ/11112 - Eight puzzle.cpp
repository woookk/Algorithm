//
//  11112 - Eight puzzle.cpp
//  cpp
//
//  Created by 민병욱 on 2024/01/31.
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

int TC;

int main() {
    FASTIO
    string init = "12345678#";
    queue<string> q;
    map<string, int> dist;
    dist[init] = 0;
    q.push(init);
    
    while (!q.empty()) {
        string puzzle = q.front();
        q.pop();
        
        int curIdx = (int) puzzle.find('#');
        int curX = curIdx / N;
        int curY = curIdx % N;
        
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
    
    cin >> TC;
    while (TC--) {
        string cur = "";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                char c;
                cin >> c;
                cur += c;
            }
        }
        
        if (dist.find(cur) == dist.end()) {
            cout << "impossible\n";
        }
        else {
            cout << dist[cur] << "\n";
        }
    }
    return 0;
}

/*
 3 x 3 board with eight quadratic pieces, where you can slide a piece into the open slot. After rearranging the pieces randomly, the goal of the game is to get the board into the configuration "12345678 " by sliding pieces one by one.
 write a program to solve the puzzles optimally.
 
 1525 - 퍼즐 문제와 유사한 문제이다. 테스트케이스가 100까지 존재해서 100개의 데이터 각각에 대해서 BFS를 돌리게되면 시간 초과 발생
 정답에서부터 BFS를 시작하여 가능한 퍼즐의 상태들의 최소 이동 횟수를 모두 구하는 방식으로 중복 없이 탐색이 가능하다.
 */
