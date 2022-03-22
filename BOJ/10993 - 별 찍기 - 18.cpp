//
//  10993 - 별 찍기 - 18.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/03/21.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

char board[1024][2048];

void func(int x, int y, int n){
    if(n == 0){
        board[x][y] = '*';
        return;
    }
    int row = (1 << n) - 1;
    int col = (1 << (n + 1)) - 3;
    
    if(n % 2 == 0){
        for(int i = 0; i < col; i++){
            board[x][y + i] = '*';
        }
        for(int i = 0; i < row; i++){
            board[x + i][y + i] = '*';
            board[x + i][y + col - 1 - i] = '*';
        }
        func(x + 1, y + (1 << (n - 1)), n - 1);
    }
    else {
        for(int i = 0; i < col; i++){
            board[x + row - 1][y + i] = '*';
        }
        for(int i = 0; i < row; i++){
            board[x + i][y + col / 2 - i] = '*';
            board[x + i][y + col / 2 + i] = '*';
        }
        func(x + row / 2, y + (1 << (n - 1)), n - 1);
    }
}

int main(){
    FASTIO;
    int N;
    cin >> N;
    int row = (1 << N) - 1;
    int col = (1 << (N + 1)) - 3;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            board[i][j] = ' ';
        }
    }
    func(0, 0, N);
    if(N % 2 == 0){
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col - i; j++){
                cout << board[i][j];
            }
            cout << "\n";
        }
    }
    else {
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col - row + i + 1; j++){
                cout << board[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}
