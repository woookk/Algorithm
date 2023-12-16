//
//  2580 - 스도쿠.cpp
//  cpp
//
//  Created by 민병욱 on 2023/12/15.
//

#include <iostream>
#include <vector>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int MAX = 9;

bool finish = false;
vector<vector<int>> board(9, vector<int>(9, 0));

void print() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

bool hasNumber(int row, int col, int num) {
    for (int i = 0; i < MAX; i++) {
        if (board[row][i] == num) return true;
        if (board[i][col] == num) return true;
    }
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[(row / 3) * 3 + i][(col / 3) * 3 + j] == num) return true;
        }
    }
    return false;
}

void solve(int depth) {
    if (depth == MAX * MAX) {
        finish = true;
        print();
        return;
    }
    
    int row = depth / MAX, col  = depth % MAX;
    if (board[row][col] != 0) {
        solve(depth + 1);
    }
    else {
        for (int num = 1; num <= MAX; num++) {
            if (hasNumber(row, col, num)) continue;
            board[row][col] = num;
            solve(depth + 1);
            if (finish) return;
            board[row][col] = 0;
        }
    }
}

int main() {
    FASTIO
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cin >> board[i][j];
        }
    }
    solve(0);
    return 0;
}

/*
 스도쿠는 가로, 세로 각각 9개씩 총 81개의 칸으로 이루어진 정사각형 판 위에서 이루어지는데, 게임 시작 전 일부 칸에는 1에서 9가지의 숫자 중 하나가 쓰여있다.
 각각의 가로줄과 세로줄에는 1부터 9까지의 숫자가 한 번씩만 나타나야 하고, 굵은 선으로 구분되어 있는 3*3 정사각형 안에도 1부터 9까지의 숫자가 한 번씩만 나타나도록 나머지 빈칸을 채워야한다.
 게임 시작 전 스도쿠 판에 쓰여 있는 숫자들의 정보가 주어질 때 모든 빈 칸이 채워진 최종 모습을 출력하는 프로그램을 작성
 
 백트래킹 이용해서 풀이
 */
