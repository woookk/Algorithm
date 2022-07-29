//
//  20166 - 문자열 지옥에 빠진 호석.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/29.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);


int N, M, K;
char board[11][11];
int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};
string str;
unordered_map<string, int> ans;

void DFS(int x, int y){
    if(str.length() > 5) return;
    
    auto iter = ans.find(str);
    if(iter != ans.end()){
        iter->second++;
    }
    
    for(int dir = 0; dir < 8; dir++){
        int nx = (x + dx[dir] + N) % N;
        int ny = (y + dy[dir] + M) % M;
        str.push_back(board[nx][ny]);
        DFS(nx, ny);
        str.pop_back();
    }
}

int main(){
    FASTIO
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
        }
    }
    vector<string> god;
    for(int i = 0; i < K; i++){
        string temp;
        cin >> temp;
        god.push_back(temp);
        ans[temp] = 0;
    }
    unordered_map<string, int> map;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            str.push_back(board[i][j]);
            DFS(i, j);
            str.clear();
        }
    }
    for(auto key: god){
        cout << ans[key] << "\n";
    }
    return 0;
}
