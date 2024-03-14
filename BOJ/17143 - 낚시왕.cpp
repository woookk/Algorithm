//
//  17143 - 낚시왕.cpp
//  cpp
//
//  Created by 민병욱 on 2024/03/14.
//

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, 1, -1 };

int R, C, M;
int ans;

void fishing(vector<vector<tuple<int, int, int>>>& board, int col) {
    for (int i = 1; i <= R; i++) {
        auto [sharkSpeed, sharkDirection, sharkSize] = board[i][col];
        if (sharkSpeed == -1) continue;
        ans += sharkSize;
        board[i][col] = { -1, -1, -1};
        break;
    }
}

void moveSharks(vector<vector<tuple<int, int, int>>>& board) {
    vector<vector<tuple<int, int, int>>> nxBoard(R + 1, vector<tuple<int, int, int>>(C + 1, {-1, -1, -1}));
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            auto [sharkSpeed, sharkDirection, sharkSize] = board[i][j];
            if (sharkSize == -1) continue;
            int nx = i + dx[sharkDirection] * sharkSpeed;
            int ny = j + dy[sharkDirection] * sharkSpeed;
            while (nx > R || nx <= 0) {
                if (nx > R) {
                    nx = 2 * R - nx;
                    sharkDirection = 0;
                }
                else if (nx <= 0) {
                    nx = -nx + 2;
                    sharkDirection = 1;
                }
            }
            while (ny > C || ny <= 0) {
                if (ny > C) {
                    ny = 2 * C - ny;
                    sharkDirection = 3;
                }
                else if (ny <= 0) {
                    ny = -ny + 2;
                    sharkDirection = 2;
                }
            }
            
            auto [nxSharkSpeed, nxSharkDirection, nxSharkSize] = nxBoard[nx][ny];
            if (nxSharkSize >= sharkSize) continue;
            nxBoard[nx][ny] = { sharkSpeed, sharkDirection, sharkSize };
        }
    }
    board = nxBoard;
}

int main() {
    FASTIO
    cin >> R >> C >> M;
    vector<vector<tuple<int, int, int>>> board(R + 1, vector<tuple<int, int, int>>(C + 1, {-1, -1, -1}));
    for (int i = 0; i < M; i++) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        board[r][c] = { s, d - 1, z};
    }
    
    for (int i = 1; i <= C; i++) {
        fishing(board, i);
        moveSharks(board);
    }
    cout << ans;
    return 0;
}

/*
 낚시왕은 처음에 1번 열의 한 칸 왼쪽에 있다. 다음은 1초 동안 일어나는 일이며, 아래 적힌 순서대로 일어난다. 낚시왕은 가장 오른쪽 열의 오른쪽 칸에 이동하면 이동을 멈춘다.
 1. 낚시왕이 오른쪽으로 한 칸 이동한다.
 2. 낚시왕이 있는 열에 있는 상어 중에서 땅과 제일 가까운 상어를 잡는다. 상어를 잡으면 격자판에서 잡은 상어가 사라진다.
 3. 상어가 이동한다.
 상어는 입력으로 주어진 속도로 이동한다. 상어가 이동하려고 하는 칸이 격자판의 경계를 넘는 경우에는 방향을 반대로 바꿔서 속력을 유지한채로 이동한다.
 상어가 이동을 마친 후에 한 칸에 상어가 두 마리 이상 있을 수 있다. 이때는 크기가 큰 상어가 나머지 상어를 모두 잡아먹는다.
 낚시왕이 상어 낚시를 하는 격자판의 상태가 주어졌을 때, 낚시왕이 잡은 상어 크기의 합을 구하는 프로그램을 작성
 
 각각의 좌표에 상어의 속도, 방향, 크기를 저장해놓고 낚시와 상어의 움직임을 각각 함수로 직접 구현
 각각의 상황 직접 돌려서 풀이 진행
 */
