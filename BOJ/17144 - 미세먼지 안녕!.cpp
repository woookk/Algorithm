//
//  17144 - 미세먼지 안녕!.cpp
//  cpp
//
//  Created by 민병욱 on 2023/08/29.
//

#include <iostream>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int R, C, T, ans;
int curBoard[51][51];
int nxBoard[51][51];

int upper = -1, lower = -1;

void input() {
    cin >> R >> C >> T;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> curBoard[i][j];
            if (curBoard[i][j] == -1) {
                if (upper == -1) {
                    upper = i;
                }
                else {
                    lower = i;
                }
            }
        }
    }
}

void copyBoard() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            nxBoard[i][j] = curBoard[i][j];
        }
    }
}

void spread() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (curBoard[i][j] <= 0) continue;
            int count = 0;
            for (int dir = 0; dir < 4; dir++) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                
                if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
                if (curBoard[nx][ny] == -1) continue;
                nxBoard[nx][ny] += curBoard[i][j] / 5;
                count++;
            }
            nxBoard[i][j] -= (curBoard[i][j] / 5) * count;
        }
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            curBoard[i][j] = nxBoard[i][j];
        }
    }
}

void airClean() {
    for (int i = upper - 1; i > 0; i--) {
        curBoard[i][0] = curBoard[i - 1][0];
    }
    for (int i = 0; i < C - 1; i++) {
        curBoard[0][i] = curBoard[0][i + 1];
    }
    for (int i = 1; i <= upper; i++) {
        curBoard[i - 1][C - 1] = curBoard[i][C - 1];
    }
    for (int i = C - 1; i > 1; i--) {
        curBoard[upper][i] = curBoard[upper][i - 1];
    }
    curBoard[upper][1] = 0;
    
    for (int i = lower + 1; i < R - 1; i++) {
        curBoard[i][0] = curBoard[i + 1][0];
    }
    for (int i = 0; i < C - 1; i++) {
        curBoard[R - 1][i] = curBoard[R - 1][i + 1];
    }
    for (int i = R - 1; i >= lower; i--) {
        curBoard[i][C - 1] = curBoard[i - 1][C - 1];
    }
    for (int i = C - 1; i > 1; i--) {
        curBoard[lower][i] = curBoard[lower][i - 1];
    }
    curBoard[lower][1] = 0;
}

void calculateAnswer() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (curBoard[i][j] == -1) continue;
            ans += curBoard[i][j];
        }
    }
}

int main() {
    FASTIO
    input();
    
    while (T--) {
        copyBoard();
        spread();
        airClean();
    }
    calculateAnswer();
    cout << ans << "\n";
    return 0;
}

/*
 
 1초 동안 아래 적힌 일이 순서대로 일어난다.
 1. 미세먼지가 확산. 확산은 미세먼지가 있는 모든 칸에서 동시에 발생
    - 인접한 네 방향으로 확산
    - 인접한 방향에 공기청정기 있거나, 칸이 없으면 확산 X
    - 남은 미세먼지의 양은 Arc - (Arc / 5) * 확산된 방향의 개수
 2. 공기청정기가 작동
    - 위쪽 공기 청정기 바람은 반시계방향으로 순환, 아래쪽 공기 청정기 바람은 시계방향으로 순환
    - 바람이 불면 미세먼지가 바람의 방향대로 모두 한 칸씩 이동
    - 공기청정기에서 부는 바람은 미세먼지가 없는 바람이고, 공기청정기로 들어간 미세먼지는 모두 정화
 */
