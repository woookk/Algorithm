//
//  21940 - 가운데에서 만나기.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/04/06.
//

#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int INF = INT_MAX / 10;
int N, M, K;
int A, B, T, val;

int C[201];
int D[201][201];

int sum[201];
int mn = INT_MAX;
vector<int> ans;

int main() {
    FASTIO
    cin >> N >> M;
    
    for (int i = 1; i <= N; i++) {
        fill(D[i] + 1, D[i] + N + 1, INF);
    }
    
    for (int i = 1; i <= N; i++) {
        D[i][i] = 0;
    }
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> T;
        D[A][B] = min(D[A][B], T);
    }
    cin >> K;
    for (int i = 1; i <= K; i++) {
        cin >> C[i];
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                if (D[j][k] > D[j][i] + D[i][k]) D[j][k] = D[j][i] + D[i][k];
            }
        }
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            sum[i] += (D[i][C[j]] + D[C[j]][i]);
        }
    }
    
    for(int i = 1; i <= N; i++) {
        int mx = 0;
        for(int j = 1; j <= K; j++) {
            mx = max(mx, D[i][C[j]] + D[C[j]][i]);
        }
        sum[i] = mx;
    }

    for (int i = 1; i <= N; i++) {
        if (mn > sum[i]) {
            ans.clear();
            ans.push_back(i);
            mn = sum[i];
        }
        else if (mn == sum[i]) {
            ans.push_back(i);
        }
    }
    for (int x: ans) {
        cout << x << " ";
    }
    return 0;
}
