//
//  28298 - 더 흔한 타일 색칠 문제.cpp
//  cpp
//
//  Created by 민병욱 on 2023/07/13.
//

#include <iostream>
#include <algorithm>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, M, K, ans;
char d[505][505];
int cnt[26];

int main() {
    FASTIO
    cin >> N >> M >> K;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> d[i][j];
        }
    }
    
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            fill(cnt, cnt + 26, 0);
            for (int k = 0; k < N; k += K) {
                for (int l = 0; l < M; l += K) {
                    cnt[d[i + k][j + l] - 'A']++;
                }
            }
            
            int maxCount = 0;
            char maxAlphabet;
            for (int k = 0; k < 26; k++) {
                if (cnt[k] > maxCount) {
                    maxCount = cnt[k];
                    maxAlphabet = 'A' + k;
                }
            }
            
            for (int k = 0; k < N; k += K) {
                for (int l = 0; l < M; l += K) {
                    if (d[i + k][j + l] != maxAlphabet) {
                        d[i + k][j + l] = maxAlphabet;
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans << "\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << d[i][j];
        }
        cout << "\n";
    }
    return 0;
}

/*
    N * M 크기 타일
 
    주어진 타일을 K * K 크기의 작은 타일들로 겹치지 않게 나눴을 때, 나눠진 타일의 색상 배치가 전부 동일하도록 타일의 일부 칸을 골라 다시 색칠하고자 한다.
    최소 몇 개의 칸 다시 색칠해야하는지?
 
    K * K만큼씩 확인하면서 가장 많은 원소 구해야한다.
    
    
 */
