//
//  13418 - 학교 탐방하기.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/03/31.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int N, M;
int A, B, C;
vector<pair<int, int>> adj[1001];
vector<bool> isMST(1001);

int mn, mx, cnt;


int main() {
    FASTIO
    cin >> N >> M;
    for (int i = 0; i < M + 1; i++) {
        cin >> A >> B >> C;
        adj[A].push_back({C, B});
        adj[B].push_back({C, A});
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mxq;
    
    isMST[0] = true;
    for (auto node: adj[0]) {
        mxq.push({node.X, node.Y});
    }
    
    while (cnt < N) {
        auto cur = mxq.top();
        mxq.pop();
        
        if (isMST[cur.Y]) continue;
        if (cur.X == 0) mx++;
        
        isMST[cur.Y] = true;
        cnt++;
        
        for (auto nx: adj[cur.Y]) {
            if (isMST[nx.Y]) continue;
            mxq.push({nx.X, nx.Y});
        }
    }
    
    priority_queue<pair<int, int>> mnq;
    fill(isMST.begin(), isMST.end(), 0);
    isMST[0] = true;
    cnt = 0;
    
    for (auto node: adj[0]) {
        mnq.push({node.X, node.Y});
    }
    
    while (cnt < N) {
        auto cur = mnq.top();
        mnq.pop();
        
        if (isMST[cur.Y]) continue;
        if (cur.X == 0) mn++;
        
        isMST[cur.Y] = true;
        cnt++;
        
        
        for (auto nx: adj[cur.Y]) {
            if (isMST[nx.Y]) continue;
            mnq.push({nx.X, nx.Y});
        }
    }
    cout << mx * mx - mn * mn;
    return 0;
}
