//
//  12764 - 싸지방에 간 준하.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/01/06.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int N;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 끝나는 시간, 자리 번호
priority_queue<int, vector<int>, greater<int>> seats; // 비어있는 자리 번호
vector<pair<int, int>> t;


int computer;

int main() {
    FASTIO
    cin >> N;
    vector<int> cnt(N);
    
    for (int i = 0; i < N; i++) {
        int st, end;
        cin >> st >> end;
        t.push_back({st, end});
    }
    
    sort(t.begin(), t.end());
    
    for (int i = 0; i < N; i++) {
        int st = t[i].X;
        int end = t[i].Y;
        
        while(!pq.empty()) {
            if (pq.top().X < st) {
                seats.push(pq.top().Y);
                pq.pop();
            }
            else break;
        }
        
        if (seats.empty()) {
            pq.push({end, ++computer});
            cnt[computer]++;
        }
        else {
            int seat = seats.top();
            pq.push({end, seat});
            cnt[seat]++;
            seats.pop();
        }
    }
    
    cout << computer << "\n";
    for (int i = 1; i <= computer; i++) {
        cout << cnt[i] << " ";
    }
    return 0;
}
