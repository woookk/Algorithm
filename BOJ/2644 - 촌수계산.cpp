//
//  2644 - 촌수계산.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/03/01.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int dist[101];

int main(){
    FASTIO;
    int n, m, start, end;
    cin >> n >> start >> end >> m;
    vector<int> v[101];
    queue<int> q;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    q.push(start);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(cur == end){
            cout << dist[end];
            return 0;
        }
        for(int i = 0; i < v[cur].size(); i++){
            if(dist[v[cur][i]]) continue;
            dist[v[cur][i]] = dist[cur] + 1;
            q.push(v[cur][i]);
        }
    }
    cout << -1;
    return 0;
}
