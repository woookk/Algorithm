//
//  9019 - DSLR.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/31.
//

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int mod = 1e4;

int TC;
int dist[10001];

char command[4] = {'D', 'S', 'L', 'R'};

int main(){
    FASTIO
    cin >> TC;
    while(TC--){
        int A, B;
        int pre[10001];
        char cmd[10001];
        
        cin >> A >> B;
        fill(dist, dist + 10001, 0);
        
        queue<int> q;
        dist[A] = 1;
        q.push(A);
        while(!q.empty()){
            auto cur = q.front();
            if(cur == B){
                vector<char> ans;
                while(B != A){
                    ans.push_back(cmd[B]);
                    B = pre[B];
                }
                for(int i = (int)ans.size() - 1; i >= 0; i--){
                    cout << ans[i];
                }
                cout << "\n";
                break;
            }
            q.pop();
            int idx = -1;
            for(int nx : {cur * 2 % mod, ((cur - 1) + mod) % mod, cur * 10 % mod + cur / 1000, cur / 10 + cur % 10 * 1000}){
                idx++;
                if(dist[nx]) continue;
                dist[nx] = dist[cur] + 1;
                pre[nx] = cur;
                cmd[nx] = command[idx];
                q.push(nx);
            }
        }
    }
    return 0;
}
