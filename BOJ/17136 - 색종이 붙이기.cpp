//
//  17136 - 색종이 붙이기.cpp
//  cpp
//
//  Created by 민병욱 on 2023/09/04.
//

#include <iostream>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int MAX = 26;

int numberOfSquares, ans = MAX;
int board[11][11];
int remainingPaper[] = { 0, 5, 5, 5, 5, 5};

void input() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> board[i][j];
            if (board[i][j]) numberOfSquares++;
        }
    }
}

bool isAttacheable(int idx, int paper) {
    int row = idx / 10, col = idx % 10;
    for (int i = row; i < row + paper; i++) {
        for (int j = col; j < col + paper; j++) {
            if (!board[i][j]) return false;
        }
    }
    return true;
}

void attach(int idx, int paper, int isAttached) {
    int row = idx / 10, col = idx % 10;
    for (int i = row; i < row + paper; i++) {
        for (int j = col; j < col + paper; j++) {
            board[i][j] = isAttached;
        }
    }
}

void solve(int idx, int attached, int remain) {
    
    if (remain == 0) {
        ans = min(ans, attached);
        return;
    }
    if (idx >= 100) return;
    
    int row = idx / 10, col = idx % 10;
    if (board[row][col]) {
        for (int paperLen = 5; paperLen >= 1; paperLen--) {
            if (!remainingPaper[paperLen]) continue;
            
            if (isAttacheable(idx, paperLen)) {
                attach(idx, paperLen, 0);
                remainingPaper[paperLen]--;
                solve(idx + 1, attached + 1, remain - paperLen * paperLen);
                remainingPaper[paperLen]++;
                attach(idx, paperLen, 1);
            }
        }
    }
    else {
        solve(idx + 1, attached, remain);
    }
}

int main() {
    FASTIO
    input();
    solve(0, 0, numberOfSquares);
    if (ans == MAX) ans = -1;
    cout << ans << "\n";
    return 0;
}

/*
 정사각형 모양을 한 다섯 종류의 색종이가 있다. 색종이의 크기는 1×1, 2×2, 3×3, 4×4, 5×5로 총 다섯 종류가 있으며, 각 종류의 색종이는 5개씩 가지고 있다.
 
 색종이를 크기가 10×10인 종이 위에 붙이려고 한다. 종이는 1 * 1 크기의 칸으로 나누어져 있으며, 각각의 칸에는 0 또는 1이 적혀 있다. 1이 적힌 칸은 모두 색종이로 덮어져야 한다.
 
 종이가 주어졌을 때, 1이 적힌 모든 칸을 붙이는데 필요한 색종이의 최소 개수를 구해보자.
 
 
 */
