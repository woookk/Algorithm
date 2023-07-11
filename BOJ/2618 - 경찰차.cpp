//
//  2618 - 경찰차.cpp
//  cpp
//
//  Created by 민병욱 on 2023/07/11.
//

#include <iostream>
#include <climits>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

int N, W;
pair<int, int> event[1005];
pair<int, int> tracking[1005][1005];
int dp[1005][1005]; // dp[i][j]: 경찰차 1의 최종 위치 i, 경찰차 2의 최종 위치 j일 때 이동 거리의 최솟걊
int ans[1005];

int getDistance(const pair<int, int> a, const pair<int, int> b) {
    return abs(a.X - b.X) + abs(a.Y - b.Y);
}

void calc(int idx, pair<int, int> track) {
    if (track == make_pair(0, 0)) {
        return;
    }
        
    pair<int, int> before = tracking[track.X][track.Y];
    if (track.X == idx) {
        while (idx > track.Y)
            ans[idx--] = 1;
    }
    else {
        while (idx > track.X)
            ans[idx--] = 2;
    }
    calc(idx, before);
}

int main() {
    FASTIO
    cin >> N >> W;
    for (int i = 1; i <= W; i++) {
        cin >> event[i].X >> event[i].Y;
    }
    
    dp[1][0] = getDistance({ 1, 1 }, event[1]);
    dp[0][1] = getDistance({ N, N }, event[1]);
    
    for (int i = 2; i <= W; i++) {
        dp[i][i - 1] = dp[0][i - 1] + getDistance({ 1, 1 }, event[i]);
        tracking[i][i - 1] = { 0, i - 1 };
        for (int j = 1; j < i - 1; j++) {
            if (dp[i][i - 1] > dp[j][i - 1] + getDistance(event[j], event[i])) {
                dp[i][i - 1] = dp[j][i - 1] + getDistance(event[j], event[i]);
                tracking[i][i - 1] = { j,i - 1 };
            }
        }
        dp[i - 1][i] = dp[i - 1][0] + getDistance({ N , N }, event[i]);
        tracking[i - 1][i] = { i - 1 , 0 };
        for (int j = 1; j < i - 1; j++) {
            if (dp[i - 1][i] > dp[i - 1][j] + getDistance(event[j], event[i])) {
                dp[i - 1][i] = dp[i - 1][j] + getDistance(event[j], event[i]);
                tracking[i - 1][i] = { i - 1,j };
            }
        }
        for (int j = 0; j < i - 1; j++) {
            dp[j][i] = dp[j][i - 1] + getDistance(event[i - 1], event[i]);
            dp[i][j] = dp[i - 1][j] + getDistance(event[i - 1], event[i]);
            tracking[j][i] = { j, i - 1 };
            tracking[i][j] = { i - 1, j };
        }
    }
    
    int mn = INT_MAX;
    pair<int, int> fin;
    for (int i = 0; i < W; i++) {
        if (mn > dp[W][i]) {
            mn = dp[W][i];
            fin = { W, i };
        }
        if (mn > dp[i][W]) {
            mn = dp[i][W];
            fin = { i, W };
        }
    }
    calc(W, fin);
    cout << mn << "\n";
    for (int i = 1; i <= W; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}

/*
    두 대의 경찰차(1, 2), 경찰차1은 (1, 1)의 위치에 있고 경찰차2는 (N, N)의 위치에 있다.
    경찰 본부에서는 처리할 사건이 있으면 그 사건이 발생된 위치를 두 대의 경찰차 중 하나에 알려주고, 연락 받은 경찰차는 경찰 본부로부터 다음 연락이 올 때까지 처리한 사건이 발생한 위치에서 기다린다.
    사건이 발생한 순서대로 두 대의 경찰차에게 맡길 때, 두 대의 경찰차들이 이동하는 거리의 합을 최소화 하도록 사건을 맡기려고 한다.
    
    각각의 사건에서 경찰차들이 가까운 사건을 처리하는 풀이 -> 모든 경우 보장하지 못한다.
    결국 완전 탐색으로 모든 경우의 수 해봐야한다.
    모든 경우의 수를 다 해볼 때 시간복잡도 2^W이므로 최대 2^W이므로 시간초과 발생한다.
    시간복잡도 줄일 방법 찾아야한다.
 
    
 
 */
