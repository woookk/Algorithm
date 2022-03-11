//
//  20304 - 비밀번호 제작.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/02/21.
//

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int dist[1000001];
int bit_size;

void max_bit(int n){
    while(1){
        if(n / 2 != 0){
            bit_size++;
            n /= 2;
        }
        else{
            bit_size++;
            break;
        }
    }
}

int main(){
    FASTIO;
    int N, M;
    cin >> N >> M;
    queue<int> q;
    for(int i = 0; i < M; i++){
        int tmp;
        cin >> tmp;
        q.push(tmp);
        dist[tmp] = 1;
    }
    max_bit(N);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i = 0; i < bit_size; i++){
            int nx = (cur ^ (1 << i));
            if(nx > N) continue;
            if(dist[nx]) continue;
            dist[nx] = dist[cur] + 1;
            q.push(nx);
        }
        
    }
    int MX = -1;
    for(int i = 0; i <= N; i++){
        MX = max(dist[i], MX);
    }
    cout << MX-1;
    return 0;
}
