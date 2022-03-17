//
//  15686 - 치킨 배달.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/03/16.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int N, M, MN = 99999999;
int board[51][51];
int copy_board[51][51];

vector<pair<int, int>> home;
vector<pair<int, int>> chicken;
bool isopen[13];

void calc(int st, int k){
    if(k == M){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                copy_board[i][j] = board[i][j];
            }
        }
        for(int i = 0; i < M; i++){
            if(!isopen[i]) copy_board[chicken[i].X][chicken[i].Y] = 0;
        }
        int sum = 0;
        for(auto h : home){
            int dist = 99999999;
            for(int i = 0; i < chicken.size(); i++){
                if(isopen[i])
                    dist = min(dist, abs(chicken[i].X - h.X) + abs(chicken[i].Y - h.Y));
            }
            sum += dist;
        }
        MN = min(sum, MN);
        return;
    }
    for(int i = st; i < chicken.size(); i++){
        if(!isopen[i]){
            isopen[i] = 1;
            calc(i + 1, k + 1);
            isopen[i] = 0;
        }
    }
}

int main(){
    FASTIO;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
            if(board[i][j] == 2) chicken.push_back({i, j});
            else if(board[i][j] == 1) home.push_back({i, j});
        }
    }
    calc(0, 0);
    cout << MN;
    return 0;
}

// do while 이용한 next_permutation으로도 해결 가능.
// code
/*
 vector<int> brute(chicken.size(), 1);
   fill(brute.begin(), brute.begin() + chicken.size() - m, 0); // 앞의 chicken.size() - m 칸은 0, 뒤의 m칸은 1
   int mn = 0x7f7f7f7f; // 답을 저장할 변수
   do{
     int dist = 0; // 도시의 치킨 거리를 저장할 변수
     for(auto h : house){
       int tmp = 0x7f7f7f7f; // 집의 치킨 거리를 저장할 변수
       for(int i = 0; i < chicken.size(); i++){
         if(brute[i] == 0) continue;
         tmp = min(tmp, abs(chicken[i].X - h.X) + abs(chicken[i].Y - h.Y)); // 집의 치킨 거리 갱신
       }
       dist += tmp;
     }
     mn = min(mn, dist);
   }while(next_permutation(brute.begin(), brute.end()));
 */
