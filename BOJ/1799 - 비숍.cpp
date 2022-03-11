//
//  1560 - 비숍.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/03/11.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int N, ans[2];
bool used[2][20];
vector<pair<int, int>> board[2][20];

void func(int idx, int cnt, int color){
    if (idx == 2 * N){
        ans[color] = max(ans[color], cnt);
        return;
    }
    for(auto c : board[color][idx]){
        auto cur = c;
        if(used[color][cur.X + cur.Y]) continue;
        used[color][cur.X + cur.Y] = true;
        func(idx + 1, cnt + 1, color);
        used[color][cur.X + cur.Y] = false;
    }
    func(idx + 1, cnt, color);
}
int main(){
    FASTIO;
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int tmp;
            cin >> tmp;
            if(tmp == 1) board[(i + j + 1) % 2][N + i - j - 1].push_back({i,j});
        }
    }
    func(0, 0, 0);
    func(0, 0, 1);
    cout << ans[0] + ans[1];
    return 0;
}
