//
//  17071 - 숨바꼭질 5.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/02/16.
//

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int dist[2][500001];

int main(){
    FASTIO;
    int N, K, ans = 0;
    cin >> N >> K;
    queue<pair<int ,int>> q;
    q.push({N, 0});
    for(int i = 0; i < 2; i++){
        fill(dist[i], dist[i] + 500001, -1);
    }
    dist[0][N] = 0;
    while(!q.empty()){
        int x, t;
        tie(x, t) = q.front();
        q.pop();
        for(int nx : {x -1, x + 1, 2 * x}){
            if(nx < 0 || nx > 500000) continue;
            if(dist[(t + 1) % 2][nx] != -1) continue;
            dist[(t + 1) % 2][nx] = t + 1;
            q.push({nx, t + 1});
        }
    }
    bool found = false;
    while(K <= 500000){
        if(dist[ans % 2][K] <= ans){
            found = true;
            break;
        }
        K += ++ans;
    }
    if(found) cout << ans;
    else
        cout << -1;
    return 0;
}
