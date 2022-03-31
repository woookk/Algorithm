//
//  15685 -  드래곤 커브.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/03/30.
//

#include <iostream>
#include <vector>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, ans;
bool board[101][101];

void curve(int x, int y, int d, int g){
    vector<int> dir;
    dir.push_back(d);
    board[y][x] = 1;
    
    while(g--){
        int dirsize = (int)dir.size();
        for(int i = dirsize - 1; i >= 0; i--){
            dir.push_back((dir[i] + 1) % 4);
        }
    }
    
    for(int i = 0; i < dir.size(); i++){
        int curdir = dir[i];
        if(curdir == 0) x++;
        else if(curdir == 1) y--;
        else if(curdir == 2) x--;
        else if(curdir == 3) y++;
        board[y][x] = 1;
    }
}

void check(){
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            if(board[i][j] && board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1]) ans++;
        }
    }
}

int main(){
    FASTIO;
    cin >> N;
    for(int i = 0; i < N; i++){
        int x, y, dir, g;
        cin >> x >> y >> dir >> g;
        curve(x, y, dir, g);
    }
    check();
    cout << ans << "\n";
    return 0;
}
