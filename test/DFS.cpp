//
//  DFS.cpp
//  DS
//
//  Created by 민병욱 on 2022/04/15.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define MAX_ROW 101
#define MAX_COL 101
#define MAX_SIZE 1000

int Stack[MAX_SIZE];
int sp;

int init(){
    sp = 0;
    return 0;
}

int isEmpty(){
    return sp == 0;
}

int Push(int x){
    Stack[sp++] = x;
    return 0;
}

int Pop(){
    return Stack[--sp];
}

int M, N;
char Map[MAX_ROW][MAX_COL];

// 현재 위치 기준 8방향 이동하기 위해 배열 활용.
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int Find(){
    int x = 0, y = 0;
    Map[x][y] = '*';
    while(1) {
        if(x == M - 1 && y == N - 1) return 1;
        int nx = -100, ny = - 100;
        for(int dir = 0; dir < 8; dir++){
            if(x + dx[dir] < 0 || y + dy[dir] < 0 || x + dx[dir] >= M || y + dy[dir] >= N) continue;
            if(Map[x + dx[dir]][y + dy[dir]] == '0'){
                nx = x + dx[dir];
                ny = y + dy[dir];
                break;
            }
        }
        if(nx != -100) { //전진
            Push(x); Push(y);
            x = nx; y = ny;
            Map[x][y] = '*';
        }
        else { //후진
            if(isEmpty()) return -1;
            Map[x][y] = 'X'; y = Pop(); x = Pop();
        }
    }
}

int main(){
    FASTIO;
    cin >> M >> N;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> Map[i][j]; //Map 입력
        }
    }
    init();
    int ans = Find();
    if(ans == 1){
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                cout << Map[i][j];
            }
            cout << "\n";
        }
    }
    else {
        cout << "Impossible\n";
    }
    return 0;
}
