//
//  16953 - A → B.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/02/11.
//

#include <iostream>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int main(){
    FASTIO;
    long long A, B;
    cin >> A >> B;
    queue<pair<long long, int>> q;
    q.push({A, 1});
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for(long long nx : {cur.X * 2, cur.X * 10 + 1}){
            if(nx > B) continue;
            if(nx == B){
                cout << cur.Y + 1;
                return 0;
            }
            q.push({nx, cur.Y + 1});
        }
    }
    cout << -1;
    return 0;
}
