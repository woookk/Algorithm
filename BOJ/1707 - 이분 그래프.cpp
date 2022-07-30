//
//  1707 - 이분 그래프.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/25.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int TC;
int V, E;


int depth[20001];
vector<int> edge[20001];

int main(){
    FASTIO
    cin >> TC;
    while(TC--){
        bool ans = true;
        cin >> V >> E;
        for(int i = 1; i <= V; i++){
            depth[i] = -1;
            edge[i].clear();
        }
        while(E--){
            int a, b;
            cin >> a >> b;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        queue<int> q;
        for(int st  = 1; st <= V; st++){
            if(depth[st] != -1)
                continue;
            q.push(st);
            depth[st] = 0;
            while(!q.empty()){
                int cur = q.front();
                q.pop();
                for(auto const &a : edge[cur]){
                    if(depth[a] != -1) continue;
                    depth[a] = depth[cur] + 1;
                    q.push(a);
                }
            }
        }
        for(int v = 1; v <= V; v++){
            for(auto const &a: edge[v]){
                if((depth[v] - depth[a]) % 2 == 0)
                    ans = false;
            }
        }
        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
