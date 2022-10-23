//
//  BFS.cpp
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

int Queue[MAX_SIZE];
int Head, Tail;

int init(){
    Head = Tail = 0;
    return 0;
}

int isEmpty(){
    return Head == Tail;
}

int Insert(int x){
    Queue[Head] = x; Head = (Head + 1) % MAX_SIZE;
    return 0;
}

int Pop(){
    int RetVal;
    RetVal = Queue[Tail]; Tail = (Tail + 1) % MAX_SIZE;
    return RetVal;
}

int M, N;
char Map[MAX_ROW][MAX_COL];

// 현재 위치 기준 8방향 이동하기 위해 배열 활용.
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int Find(){
    int x = 0, y = 0;
    while(1) {
        if(Map[x][y] == '*'){
            if(isEmpty()){
                return -1;
            }
            x = Pop(); y = Pop();
            continue;
        }
        Map[x][y] = '*';
        if(x == M - 1 && y == N - 1) return 1;
        for(int dir = 0; dir < 8; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
            if(Map[nx][ny] == '0'){
                Insert(nx);
                Insert(ny);
            }
        }
        if(isEmpty()){
            return -1;
        }
        x = Pop(); y = Pop();
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
    Find();
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cout << Map[i][j];
        }
        cout << "\n";
    }
    return 0;
}
