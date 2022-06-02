//
//  10216 - Count Circle Groups.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/01.
//

#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

typedef struct _node{
    int X;
    int Y;
    int R;
}node;

int T;
node c[3001];
bool vis[3001];

bool dist(const node &a, const node &b){
    return (a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y) <= (a.R + b.R) * (a.R + b.R);
}

int main(){
    FASTIO;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        fill(vis, vis + N, 0);
        for(int i = 0; i < N; i++){
            cin >> c[i].X >> c[i].Y >> c[i].R;
        }
        int ans = 0;
        stack<int> s;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(vis[i]) continue;
                s.push(i);
                vis[i] = true;
                ans++;
                while(!s.empty()) {
                    int cur = s.top();
                    s.pop();
                    for(int cand = 0; cand < N; cand++){
                        if(!vis[cand] && dist(c[cand], c[cur])){
                            vis[cand] = true;
                            s.push(cand);
                        }
                    }
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
