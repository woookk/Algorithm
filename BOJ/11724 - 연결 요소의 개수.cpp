//
//  11724 - 연결 요소의 개수.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/03/02.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int vis[1001];

int main(){
    FASTIO;
    int N, M;
    cin >> N >> M;
    vector<int> node[1001];
    queue<int> q;
    while(M--){
        int u, v;
        cin >> u >> v;
        node[u].push_back(v);
        node[v].push_back(u);
    }
    int cnt = 0;
    for(int i = 1; i <= N; i++){
        if(vis[i]) continue;
        q.push(i);
        cnt++;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int nx : node[cur]){
                if(vis[nx]) continue;
                vis[nx] = 1;
                q.push(nx);
            }
        }
    }
    cout << cnt;
    return 0;
}
