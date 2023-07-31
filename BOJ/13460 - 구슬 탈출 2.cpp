//
//  13460 - 구슬 탈출 2.cpp
//  cpp
//
//  Created by 민병욱 on 2023/08/01.
//

#include <iostream>
#include <queue>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int N, M;
char board[15][15];
int visited[15][15][15][15];
pair<int, int> red, blue;

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'R') {
                red = {i, j};
                board[i][j] = '.';
            }
            if (board[i][j] == 'B') {
                blue = {i, j};
                board[i][j] = '.';
            }
        }
    }
}

int BFS() {
    queue<pair<pair<int, int>, pair<int, int>>> nxQ;
    queue<pair<pair<int, int>, pair<int, int>>> curQ;
    nxQ.push({red, blue});
    
    int count = 0;
    while (!nxQ.empty()) {
        curQ = nxQ;
        while (!nxQ.empty()) {
            nxQ.pop();
        }
        while (!curQ.empty()) {
            auto [curRed, curBlue] = curQ.front();
            curQ.pop();
            
            if (board[curRed.X][curRed.Y] == 'O') {
                return count;
            }
            
            for (int dir = 0; dir < 4; dir++) {
                pair<int, int> nxRed = curRed;
                pair<int, int> nxBlue = curBlue;
                
                while (board[nxRed.X + dx[dir]][nxRed.Y + dy[dir]] != '#' && board[nxRed.X][nxRed.Y] != 'O') {
                    nxRed.X += dx[dir];
                    nxRed.Y += dy[dir];
                }
                while (board[nxBlue.X + dx[dir]][nxBlue.Y + dy[dir]] != '#' && board[nxBlue.X][nxBlue.Y] != 'O') {
                    nxBlue.X += dx[dir];
                    nxBlue.Y += dy[dir];
                }
                
                if (nxRed == nxBlue) {
                    if (board[nxRed.X][nxRed.Y] == 'O') continue;
                    
                    if (abs(nxRed.X - curRed.X) + abs(nxRed.Y - curRed.Y) > abs(nxBlue.X - curBlue.X) + abs(nxBlue.Y - curBlue.Y)) {
                        nxRed.X -= dx[dir];
                        nxRed.Y -= dy[dir];
                    }
                    else {
                        nxBlue.X -= dx[dir];
                        nxBlue.Y -= dy[dir];
                    }
                    
                }
                
                if (visited[nxRed.X][nxRed.Y][nxBlue.X][nxBlue.Y]) continue;
                nxQ.push({nxRed, nxBlue});
                visited[nxRed.X][nxRed.Y][nxBlue.X][nxBlue.Y] = 1;
            }
        }
        if (count == 10) return -1;
        count++;
    }
    return -1;

}

int main() {
    FASTIO
    input();
    cout << BFS();
    return 0;
}

/*
 구슬 탈출: 직사각형 보드에 빨간 구슬과 파란 구슬을 하나씩 넣은 다음, 빨간 구슬을 구멍을 통해 빼내는 게임
 보드의 세로 크기 N, 가로 크기 M
 게임의 목표는 빨간 구슬을 구멍을 통해서 빼내는 것. 파란 구슬이 구멍에 들어가면 안된다.
 이 때, 구슬을 손으로 건드릴 수는 없고, 중력을 이용해서 이리 저리 굴려야한다. (왼쪽으로 기울이기, 오른쪽으로 기울이기, ... 등 네 가지 동작이 가능하다.)
 각각의 동작에서 공은 동시에 움직이고 빨간 구슬이 구멍에 빠지면 성공, 파란 구슬이 구멍에 빠지면 실패, 두 구슬이 동시에 빠져도 실패이다.
 
 */
