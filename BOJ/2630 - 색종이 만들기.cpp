//
//  2630 - 색종이 만들기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/03/04.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int cnt[2];
int board[150][150];

bool check(int x, int y, int n){
    for(int i = x; i < x + n; i++){
        for(int j = y; j < y + n; j++){
            if(board[x][y] != board[i][j]) return false;
        }
    }
    return true;
}
void func(int x, int y, int n){
    if(check(x, y, n)) {
        cnt[board[x][y]] += 1;
        return;
    }
    
    int N = n / 2;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            func(x + i * N, y + j * N, N);
        }
    }
}
int main(){
    FASTIO;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> board[i][j];
    func(0, 0, N);
    for(int i = 0; i < 2; i++){
        cout << cnt[i] << "\n";
    }
    return 0;
}
