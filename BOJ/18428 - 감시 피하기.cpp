//
//  18428 - 감시 피하기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/03/25.
//

#include <iostream>
#include <vector>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int N, ans;
char board[6][6];
bool isused[36];
vector<pair<int ,int>> blank;
vector<pair<int ,int>> teacher;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool check(int x, int y){
        for(int dir = 0; dir < 4; dir++){
            int nx = x;
            int ny = y;
            while(nx >= 0 && ny >= 0 && nx < N && ny < N){
                nx = nx + dx[dir];
                ny = ny + dy[dir];
                if(board[nx][ny] == 'O') break;
                else if(board[nx][ny] == 'S') return false;
            }
        }
    return true;
}

void func(int st, int k){
    if(k == 3){
        for(auto c : teacher){
            if(!check(c.X, c.Y)){
                return;
            }
        }
        cout << "YES\n";
        exit(0);
    }
    for(int i = st; i < blank.size(); i++){
        board[blank[i].X][blank[i].Y] = 'O';
        func(i + 1, k + 1);
        board[blank[i].X][blank[i].Y] = 'X';
    }
}

int main(){
    FASTIO;
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
            if(board[i][j] == 'X') blank.push_back({i, j});
            else if(board[i][j] == 'T') teacher.push_back({i, j});
        }
    }
    func(0, 0);
    cout << "NO";
    return 0;
}
