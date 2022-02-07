//
//  1963 - 소수 경로.cpp
//  Cpp Algorithm
//
//  Created by 민병욱 on 2022/02/07.
//

#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define MX 9999

bool prime[10000];
int dist[10001];

void sieve(){
    for(int i = 2; i <= MX; i++)
        prime[i] = 1;
    for(int i = 2; i * i <= MX; i++){
        if(prime[i] == 0) continue;
        
        for(int j = i * i; j <= MX; j += i){
            if(prime[j] == 0) continue;
            else prime[j] = 0;
        }
    }
}

void bfs(int x, int y){
    queue<int> q;
    dist[x] = 1;
    q.push(x);
    while(!q.empty()){
        x = q.front(); q.pop();
        if(x == y){
            cout << dist[x] - 1 << "\n";
            return;
        }
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 10; j++){
                if(i == 0 && j == 0) continue;
                string s = to_string(x);
                s[i] = j + '0';
                int nx = stoi(s);
                if(dist[nx] || nx < 1000 || !prime[nx]) continue;
                dist[nx] = dist[x] + 1;
                q.push(nx);
            }
        }
    }
    cout << "Impossible\n";
}

int main(){
    FASTIO;
    int T;
    cin >> T;
    sieve();
    while(T--){
        int start, end;
        cin >> start >> end;
        fill_n(dist, 10001, 0);
        bfs(start, end);
    }
    return 0;
}
