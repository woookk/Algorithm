//
//  1992 - 쿼드트리.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/03/04.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

string board[65];

bool check(int x, int y, int n){
    for(int i = x; i < x + n; i++)
        for(int j = y; j < y + n; j++)
            if(board[x][y] != board[i][j]) return false;
    return true;
}

void func(int x, int y, int n){
    if(check(x, y, n)){
        cout << board[x][y];
        return;
    }
    int N = n / 2;
    cout << "(";
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            func(x + i * N, y + j * N, N);
        }
    }
    cout << ")";
}

int main(){
    FASTIO;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> board[i];
    func(0, 0, N);
    return 0;
}
